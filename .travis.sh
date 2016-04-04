#!/bin/bash

set -e

function travis_time_start {
    set +x
    TRAVIS_START_TIME=$(date +%s%N)
    TRAVIS_TIME_ID=$(cat /dev/urandom | tr -dc 'a-z0-9' | fold -w 8 | head -n 1)
    TRAVIS_FOLD_NAME=$1
    echo -e "\e[0Ktraivs_fold:start:$TRAVIS_FOLD_NAME"
    echo -e "\e[0Ktraivs_time:start:$TRAVIS_TIME_ID"
    set -x
}
function travis_time_end {
    set +x
    _COLOR=${1:-32}
    TRAVIS_END_TIME=$(date +%s%N)
    TIME_ELAPSED_SECONDS=$(( ($TRAVIS_END_TIME - $TRAVIS_START_TIME)/1000000000 ))
    echo -e "traivs_time:end:$TRAVIS_TIME_ID:start=$TRAVIS_START_TIME,finish=$TRAVIS_END_TIME,duration=$(($TRAVIS_END_TIME - $TRAVIS_START_TIME))\n\e[0K"
    echo -e "traivs_fold:end:$TRAVIS_FOLD_NAME"
    echo -e "\e[0K\e[${_COLOR}mFunction $TRAVIS_FOLD_NAME takes $(( $TIME_ELAPSED_SECONDS / 60 )) min $(( $TIME_ELAPSED_SECONDS % 60 )) sec\e[0m"
    set -x
}

if [ "$TRAVIS_OS_NAME" == "linux" ]; then 

    if [ ! -e /usr/bin/sudo ] ; then apt-get install -y sudo; fi

    travis_time_start setup.apt-get_update
    sudo apt-get update
    travis_time_end

    travis_time_start setup.apt-get_install
    sudo apt-get install -qq -y git make gcc g++ libjpeg-dev libxext-dev libx11-dev libgl1-mesa-dev libglu1-mesa-dev libpq-dev libpng12-dev xfonts-100dpi xfonts-75dpi  # msttcorefonts could not install on 14.04 travis
    sudo apt-get install -qq -y texlive-latex-base ptex-bin latex2html nkf poppler-utils || echo "ok" # 16.04 does ont have ptex bin
    travis_time_end

fi
if [ "$TRAVIS_OS_NAME" == "osx" ]; then

    travis_time_start setup.install
    brew install jpeg libpng mesalib-glw wget;
    travis_time_end

fi

travis_time_start install # Use this to install any prerequisites or dependencies necessary to run your build
cd ${HOME}
git clone http://github.com/euslisp/jskeus jskeus
ln -s $CI_SOURCE_PATH jskeus/eus
travis_time_end

travis_time_start script.make # All commands must exit with code 0 on success. Anything else is considered failure.
cd jskeus
make
source bashrc.eus
export DISPLAY=
set +e
export EXIT_STATUS=0; for test_l in irteus/test/*.l; do irteusgl $test_l; export EXIT_STATUS=`expr $? + 1`; done;echo "Exit status : $EXIT_STATUS"; [ $EXIT_STATUS == 0 ]
travis_time_end

if [ "$TRAVIS_OS_NAME" == "linux" ]; then 

    travis_time_start script.doc
    set +e
    (cd doc; make)
    travis_time_end

fi
