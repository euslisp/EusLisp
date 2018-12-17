#!/bin/bash

set -e
export DEBIAN_FRONTEND=noninteractive

function travis_time_start {
    TRAVIS_START_TIME=$(date +%s)
    TRAVIS_TIME_ID=$(cat /dev/urandom | LC_ALL=C LC_CTYPE=C tr -dc 'a-z0-9' | fold -w 8 | head -n 1)
    TRAVIS_FOLD_NAME=$1
    echo -e "\e[0Ktravis_fold:start:$TRAVIS_FOLD_NAME"
    echo -e "\e[0Ktravis_time:start:$TRAVIS_TIME_ID"
    set -x # enable debug information
}
function travis_time_end {
    set +x # disable debug information
    _COLOR=${1:-32}
    TRAVIS_END_TIME=$(date +%s)
    TIME_ELAPSED_SECONDS=$(( ($TRAVIS_END_TIME - $TRAVIS_START_TIME)/1000000000 ))
    echo -e "travis_time:end:$TRAVIS_TIME_ID:start=$TRAVIS_START_TIME,finish=$TRAVIS_END_TIME,duration=$(($TRAVIS_END_TIME - $TRAVIS_START_TIME))\n\e[0K"
    echo -e "travis_fold:end:$TRAVIS_FOLD_NAME"
    echo -e "\e[0K\e[${_COLOR}mFunction $TRAVIS_FOLD_NAME takes $(( $TIME_ELAPSED_SECONDS / 60 )) min $(( $TIME_ELAPSED_SECONDS % 60 )) sec\e[0m"
}

if [ "$TRAVIS_OS_NAME" == "linux" ]; then 

    travis_time_start setup.apt-get_update
    if [ ! -e /usr/bin/sudo ] ; then apt-get update && apt-get install -y sudo;  else sudo apt-get update; fi
    travis_time_end

    travis_time_start setup.apt-get_install
    ret=1; while [ $ret != 0 ]; do sudo apt-get install -qq -y git make gcc g++ libjpeg-dev libxext-dev libx11-dev libgl1-mesa-dev libglu1-mesa-dev libpq-dev libpng-dev xfonts-100dpi xfonts-75dpi && ret=0 || echo "failed, retry"; done # msttcorefonts could not install on 14.04 travis
    if [ "`uname -m`" == "x86_64" ] ; then sudo apt-get install -qq -y texlive-latex-base ptex-bin latex2html nkf poppler-utils || echo "ok"; fi # 16.04 does ont have ptex bin
    travis_time_end

fi
if [ "$TRAVIS_OS_NAME" == "osx" ]; then
    travis_time_start setup.install
    # skip if already installed
    # https://discourse.brew.sh/t/skip-ignore-brew-install-if-package-is-already-installed/633/2
    # brew install jpeg libpng mesalib-glw;
    brew list jpeg &>/dev/null || brew install jpeg
    brew list libpng &>/dev/null || brew install libpng
    brew list mesalib-glw &>/dev/null || brew install mesalib-glw
    travis_time_end

fi

travis_time_start install # Use this to install any prerequisites or dependencies necessary to run your build
cd ${HOME}
[ -e jskeus ] || git clone http://github.com/euslisp/jskeus jskeus
ln -s $CI_SOURCE_PATH jskeus/eus
ln -s `pwd`/jskeus/irteus   jskeus/eus/irteus
travis_time_end

travis_time_start script.make # All commands must exit with code 0 on success. Anything else is considered failure.
cd jskeus
if [[ "$DOCKER_IMAGE" == *"trusty"* || "$DOCKER_IMAGE" == *"jessie"* ]]; then
    make eus-installed WFLAGS="-Werror=implicit-int -Werror=implicit-function-declaration -Werror=unused-result"
else
    make eus-installed WFLAGS="-Werror=implicit-int -Werror=implicit-function-declaration -Werror=incompatible-pointer-types -Werror=int-conversion -Werror=unused-result"
fi
make

travis_time_end

if [ "$TRAVIS_OS_NAME" == "linux" -a "`uname -m`" == "x86_64" -a "$ROS_DISTRO" != "" ]; then

    travis_time_start setup.ros

    export TZ=Asia/Tokyo
    echo "${TZ}" > /etc/timezone
    apt-get install -qq -y lsb-release gnupg
    sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
    ret=1; while [ $ret != 0 ]; do apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116 && ret=0; done
    apt-get update -qq
    apt-get install -qq -y wget python-rosdep python-wstool python-catkin-tools ros-$ROS_DISTRO-rosbash ros-$ROS_DISTRO-rospack
    mkdir -p ~/ws/src
    cd ~/ws/src

    travis_time_end
    travis_time_start setup.workspace

    # setup roseus
    git clone http://github.com/jsk-ros-pkg/jsk_roseus
    # setup euslisp
    ln -sf ~/jskeus/eus ./euslisp
    wget https://raw.githubusercontent.com/tork-a/euslisp-release/release/kinetic/euslisp/package.xml -O euslisp/package.xml
    mkdir -p euslisp/cmake euslisp/env-hooks
    for file in CMakeLists.txt cmake/euslisp-extras.cmake.in env-hooks/99.euslisp.sh.in; do
        wget https://raw.githubusercontent.com/tork-a/euslisp-release/master/patches/${file} -O euslisp/${file}
    done
    # setup jskeus
    mkdir jskeus
    ln -sf ~/jskeus/irteus ./jskeus/irteus
    cp -r ~/jskeus/doc ~/jskeus/images ./jskeus/
    wget https://raw.githubusercontent.com/tork-a/jskeus-release/release/$ROS_DISTRO/jskeus/package.xml -O jskeus/package.xml
    wget https://raw.githubusercontent.com/tork-a/jskeus-release/master/patches/CMakeLists.txt -O jskeus/CMakeLists.txt
    #
    travis_time_end
    travis_time_start rosdep.update

    cd ~/ws
    source /opt/ros/$ROS_DISTRO/setup.bash
    sudo rosdep init
    rosdep update
    rosdep install -y -q -r --from-paths ./src  --ignore-src

    travis_time_end
    travis_time_start compile.roseus

    catkin build roseus

    travis_time_end
    travis_time_start run_tests.roseus

    catkin run_tests -p1 -j1 roseus
    source devel/setup.bash
    rospack find roseus
    (roscd roseus; rostest -t test/test-roseus.test)
    catkin_test_results --verbose --all build

    travis_time_end

    exit 0
fi

source bashrc.eus
export DISPLAY=
export EXIT_STATUS=0;
set +e

# arm target (ubuntu_arm64/trusty) takes too long time (>50min) for test
if [[ "`uname -m`" == "aarch"* ]]; then
    sed -i 's@00000@0000@' $CI_SOURCE_PATH/test/object.l $CI_SOURCE_PATH/test/coords.l
fi

    # run test in EusLisp/test
    for test_l in $CI_SOURCE_PATH/test/*.l; do

        travis_time_start euslisp.${test_l##*/}.test

        eusgl $test_l;
        export TMP_EXIT_STATUS=$?

        travis_time_end `expr 32 - $TMP_EXIT_STATUS`

        export EXIT_STATUS=`expr $TMP_EXIT_STATUS + $EXIT_STATUS`;
    done;
    echo "Exit status : $EXIT_STATUS";


    # run test in compiled EusLisp/test
    for test_l in $CI_SOURCE_PATH/test/*.l; do
        # bignum test fails on armhf
        [[ "`uname -m`" == "arm"* && $test_l =~ bignum.l ]] && continue;
        # const.l does not compilable https://github.com/euslisp/EusLisp/issues/318
        [[ $test_l =~ const.l ]] && continue;

        travis_time_start compiled.${test_l##*/}.test

        eusgl "(let ((o (namestring (merge-pathnames \".o\" \"$test_l\"))) (so (namestring (merge-pathnames \".so\" \"$test_l\")))) (compile-file \"$test_l\" :o o) (if (probe-file so) (load so) (exit 1))))"
        export TMP_EXIT_STATUS=$?

        travis_time_end `expr 32 - $TMP_EXIT_STATUS`

        export EXIT_STATUS=`expr $TMP_EXIT_STATUS + $EXIT_STATUS`;
    done;
    echo "Exit status : $EXIT_STATUS";

    # run test in jskeus/irteus
    for test_l in irteus/test/*.l; do

        [[ ("`uname -m`" == "arm"* || "`uname -m`" == "aarch"*) && $test_l =~ geo.l|mathtest.l|interpolator.l|test-irt-motion.l|test-pointcloud.l|irteus-demo.l ]] && continue;

        travis_time_start irteus.${test_l##*/}.test

        irteusgl $test_l;
        export TMP_EXIT_STATUS=$?

        travis_time_end `expr 32 - $TMP_EXIT_STATUS`

        export EXIT_STATUS=`expr $TMP_EXIT_STATUS + $EXIT_STATUS`;
    done;
    echo "Exit status : $EXIT_STATUS";


[ $EXIT_STATUS == 0 ] || exit 1

travis_time_start eus64.test

if [[ "$TRAVIS_OS_NAME" == "osx" || "`uname -m`" == "arm"* ]]; then
    uname -a
else
    make -C eus/contrib/eus64-check/ || exit 1 # check eus64-check
fi
travis_time_end

if [ "$TRAVIS_OS_NAME" == "linux" -a "`uname -m`" == "x86_64" ]; then

    travis_time_start script.doc
    set +e
    (cd doc; make)
    travis_time_end

fi
