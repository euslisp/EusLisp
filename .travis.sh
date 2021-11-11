#!/bin/bash

set -e
export DEBIAN_FRONTEND=noninteractive

function travis_time_start {
    if [ "$TRAVIS_OS_NAME" == "osx" ]; then
        TRAVIS_START_TIME=$(( $(date +%s)*1000000000 ))
    else
        TRAVIS_START_TIME=$(date +%s%N)
    fi
    TRAVIS_TIME_ID=$(cat /dev/urandom | LC_ALL=C LC_CTYPE=C tr -dc 'a-z0-9' | fold -w 8 | head -n 1)
    TRAVIS_FOLD_NAME=$1
    echo -e "\e[0Ktravis_fold:start:$TRAVIS_FOLD_NAME"
    echo -e "\e[0Ktravis_time:start:$TRAVIS_TIME_ID"
    set -x # enable debug information
}
function travis_time_end {
    set +x # disable debug information
    _COLOR=${1:-32}
    if [ "$TRAVIS_OS_NAME" == "osx" ]; then
        TRAVIS_END_TIME=$(( $(date +%s)*1000000000 ))
    else
        TRAVIS_END_TIME=$(date +%s%N)
    fi
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
    ret=1; while [ $ret != 0 ]; do sudo apt-get install -qq -y git make gcc g++ libjpeg-dev libxext-dev libx11-dev libgl1-mesa-dev libglu1-mesa-dev libpq-dev libpng-dev xfonts-100dpi xfonts-75dpi pkg-config libbullet-dev && ret=0 || echo "failed, retry"; done # msttcorefonts could not install on 14.04 travis
    # unset protocol version https://github.com/juju/charm-tools/issues/532
    git config --global --unset protocol.version || echo "OK"
    if [ "`uname -m`" == "x86_64" ] ; then sudo apt-get install -qq -y texlive-latex-base ptex-bin latex2html nkf poppler-utils || echo "ok"; fi # 16.04 does ont have ptex bin
    travis_time_end

fi
if [ "$TRAVIS_OS_NAME" == "osx" ]; then
    travis_time_start setup.install
    # https://apple.stackexchange.com/questions/393481/homebrew-cask-download-failure-ssl-certificate-problem-certificate-has-expired
    # skip if already installed
    # https://discourse.brew.sh/t/skip-ignore-brew-install-if-package-is-already-installed/633/2
    # brew install jpeg libpng mesalib-glw;
    echo insecure >> ~/.curlrc
    export HOMEBREW_CURLRC=1
    brew list jpeg &>/dev/null || HOMEBREW_NO_AUTO_UPDATE=1 brew install jpeg
    brew list libpng &>/dev/null || HOMEBREW_NO_AUTO_UPDATE=1 brew install libpng
    brew list mesalib-glw &>/dev/null || HOMEBREW_NO_AUTO_UPDATE=1 brew install mesalib-glw
    brew list bullet &>/dev/null || HOMEBREW_NO_AUTO_UPDATE=1 brew install bullet
    travis_time_end

fi

### for multiarch compile test
if [ "$QEMU" != "" ]; then
    travis_time_start install.dpkg-dev
    apt-get install -qq -y dpkg-dev patchutils
    travis_time_end

    echo "uname -a : $(uname -a)"
    echo "uname -m : $(uname -m)"
    echo "gcc -dumpmachine : $(gcc -dumpmachine)"
    echo "gcc -dumpversion : $(gcc -dumpversion)"
    echo "getconf LONG_BIT : $(getconf LONG_BIT)"

    travis_time_start download.euslisp-debian
    export GIT_SSL_NO_VERIFY=1
    git clone http://salsa.debian.org/science-team/euslisp /tmp/euslisp-dfsg
    for file in $(cat /tmp/euslisp-dfsg/debian/patches/series); do
        # skip patch already applied by https://github.com/euslisp/EusLisp/pull/441
        if [[ $file =~  fix-for-reprotest.patch ]]; then
            filterdiff -p1 -x 'lisp/image/jpeg/makefile' -x 'lisp/comp/comp.l' < /tmp/euslisp-dfsg/debian/patches/$file > /tmp/euslisp-dfsg/debian/patches/$file-fix
            file=$file-fix
        fi
        echo $file
        patch -p1 < /tmp/euslisp-dfsg/debian/patches/$file
    done
    travis_time_end

    travis_time_start compile.euslisp
    export EUSDIR=`pwd`
    eval "$(dpkg-buildflags --export=sh)"
    make
    travis_time_end

    if [[ `gcc -dumpmachine | egrep "^(arm|aarch)"` != "" ]]; then
        export ARCHDIR=LinuxARM
    elif [[ `gcc -dumpmachine | egrep "^x86_64"` != "" ]]; then
        export ARCHDIR=Linux64
    else
        export ARCHDIR=Linux
    fi
    export PATH=`pwd`/$ARCHDIR/bin:$PATH

    export EXIT_STATUS=0;
    set +e
    # run test in EusLisp/test
    make -C test
    for test_l in test/*.l; do

        [[ "`uname -m`" == "ppc64le"* && $test_l =~ test-foreign.l ]] && continue;

        travis_time_start euslisp.${test_l##*/}.test

        sed -i 's/\(i-max\ [0-9]000\)0*/\1/' $test_l

        eusgl $test_l;
        export TMP_EXIT_STATUS=$?

        export CONTINUE=0
        # test-foreign.l only works for x86 / arm
        if [[ $test_l =~ test-foreign.l  && ! "$(gcc -dumpmachine)" =~ "aarch".*|"arm".*|"x86_64".*|"i"[0-9]"86".* ]]; then export CONTINUE=1; fi

        if [[ $CONTINUE == 0 ]]; then travis_time_end `expr 32 - $TMP_EXIT_STATUS`; else travis_time_end 33; fi

        if [[ $TMP_EXIT_STATUS != 0 ]]; then echo "Failed running $test_l. Exiting with $TMP_EXIT_STATUS"; fi

        if [[ $CONTINUE != 0 ]]; then export TMP_EXIT_STATUS=0; fi

        export EXIT_STATUS=`expr $TMP_EXIT_STATUS + $EXIT_STATUS`;

        travis_time_start compiled.${test_l##*/}.test

        eusgl "(let ((o (namestring (merge-pathnames \".o\" \"$test_l\"))) (so (namestring (merge-pathnames \".so\" \"$test_l\")))) (compile-file \"$test_l\" :o o) (if (probe-file so) (load so) (exit 1))))"
        export TMP_EXIT_STATUS=$?

        # const.l does not compilable https://github.com/euslisp/EusLisp/issues/318
        if [[ $test_l =~ const.l ]]; then export CONTINUE=1; fi

        if [[ $CONTINUE == 0 ]]; then travis_time_end `expr 32 - $TMP_EXIT_STATUS`; else travis_time_end 33; fi

        if [[ $TMP_EXIT_STATUS != 0 ]]; then echo "Failed running $test_l. Exiting with $TMP_EXIT_STATUS"; fi

        if [[ $CONTINUE != 0 ]]; then continue; fi

        export EXIT_STATUS=`expr $TMP_EXIT_STATUS + $EXIT_STATUS`;
    done;
    echo "Exit status : $EXIT_STATUS";

    travis_time_start euslisp.eusjpeg.test

    eusgl '(progn (load (format nil "~A/lisp/image/jpeg/eusjpeg.l" *eusdir*))(image::write-jpeg-file "test.jpg" (instance color-image24 :init 100 100)) (print *user*) (unix::exit))'

    export TMP_EXIT_STATUS=$?

    travis_time_end `expr 32 - $TMP_EXIT_STATUS`
    export EXIT_STATUS=`expr $TMP_EXIT_STATUS + $EXIT_STATUS`;
    echo "Exit status : $EXIT_STATUS";
    [ $EXIT_STATUS == 0 ] || exit 1
    exit 0
fi

travis_time_start install # Use this to install any prerequisites or dependencies necessary to run your build
cd ${HOME}
[ -e jskeus ] || git clone --depth 1 http://github.com/euslisp/jskeus jskeus
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
travis_time_end

travis_time_start script.make.jskeus

make

travis_time_end

travis_time_start script.eustag

(cd eus/lisp/tool; make)

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

set -x # enable debug information
# arm target (ubuntu_arm64/trusty) takes too long time (>50min) for test
# osrf/ubuntu_arm64:trusty takes >50 min, reduce loop count for irteus-demo.l
if [[ "$DOCKER_IMAGE" == *"arm"* ]]; then
    sed -i 's@00000@0@' $CI_SOURCE_PATH/test/object.l $CI_SOURCE_PATH/test/coords.l
    sed -i 's@do-until-key-counter 10@do-until-key-counter 1@' irteus/test/irteus-demo.l;
    sed -i 's/h7/ape/' irteus/test/test-cad.l
    sed -i 's/(hanoi-program (length \*disks\*))/(subseq (hanoi-program (length \*disks\*)) 0 2)/' irteus/demo/hanoi-arm.l
    sed -i 's/^\s*footstep-list/(subseq footstep-list 0 3)/' irteus/demo/walk-motion.l
fi
set +x # disable debug information

    # run test in EusLisp/test
    travis_time_start script.make.test
    make -C $CI_SOURCE_PATH/test
    travis_time_end

    for test_l in $CI_SOURCE_PATH/test/*.l; do

        travis_time_start euslisp.${test_l##*/}.test

        eusgl $test_l;
        export TMP_EXIT_STATUS=$?

        travis_time_end `expr 32 - $TMP_EXIT_STATUS`

        if [[ $TMP_EXIT_STATUS != 0 ]]; then echo "Failed running $test_l. Exiting with $TMP_EXIT_STATUS"; fi

        export EXIT_STATUS=`expr $TMP_EXIT_STATUS + $EXIT_STATUS`;
    done;
    echo "Exit status : $EXIT_STATUS";


    # run test in compiled EusLisp/test
    for test_l in $CI_SOURCE_PATH/test/*.l; do

        travis_time_start compiled.${test_l##*/}.test

        eusgl "(let ((o (namestring (merge-pathnames \".o\" \"$test_l\"))) (so (namestring (merge-pathnames \".so\" \"$test_l\")))) (compile-file \"$test_l\" :o o) (if (probe-file so) (load so) (exit 1))))"
        export TMP_EXIT_STATUS=$?

        export CONTINUE=0
        # const.l does not compilable https://github.com/euslisp/EusLisp/issues/318
        if [[ $test_l =~ const.l ]]; then export CONTINUE=1; fi

        if [[ $CONTINUE == 0 ]]; then travis_time_end `expr 32 - $TMP_EXIT_STATUS`; else travis_time_end 33; fi

        if [[ $TMP_EXIT_STATUS != 0 ]]; then echo "Failed running $test_l. Exiting with $TMP_EXIT_STATUS"; fi

        if [[ $CONTINUE != 0 ]]; then continue; fi

        export EXIT_STATUS=`expr $TMP_EXIT_STATUS + $EXIT_STATUS`;
    done;
    echo "Exit status : $EXIT_STATUS";

    # run test in jskeus/irteus
    for test_l in irteus/test/*.l; do

        travis_time_start irteus.${test_l##*/}.test

        irteusgl $test_l;
        export TMP_EXIT_STATUS=$?

        export CONTINUE=0
        # skip collision test because bullet of 2.83 or later version is not released in trusty and jessie.
        # https://github.com/euslisp/jskeus/blob/6cb08aa6c66fa8759591de25b7da68baf76d5f09/irteus/Makefile#L37
        if [[ ( "$DOCKER_IMAGE" == *"trusty"* || "$DOCKER_IMAGE" == *"jessie"* ) && $test_l =~ test-collision.l ]]; then export CONTINUE=1; fi

        if [[ $CONTINUE == 0 ]]; then travis_time_end `expr 32 - $TMP_EXIT_STATUS`; else travis_time_end 33; fi

        if [[ $TMP_EXIT_STATUS != 0 ]]; then echo "Failed running $test_l. Exiting with $TMP_EXIT_STATUS"; fi

        if [[ $CONTINUE != 0 ]]; then continue; fi

        export EXIT_STATUS=`expr $TMP_EXIT_STATUS + $EXIT_STATUS`;
    done;
    echo "Exit status : $EXIT_STATUS";


[ $EXIT_STATUS == 0 ] || exit 1

if [ "$TRAVIS_OS_NAME" == "linux" -a "`uname -m`" == "x86_64" ]; then

    travis_time_start script.doc
    set +e
    (cd doc; make)
    travis_time_end

fi
