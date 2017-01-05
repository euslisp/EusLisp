#!/usr/bin/env python

import subprocess, os, sys
def sh(command):
    print("+ {}".format(command))
    print(subprocess.check_output(command, shell=True))

# install latex2html
sh("mkdir -p tmp")
sh("apt-get download libnetpbm10")
sh("dpkg-deb -x libnetpbm10_*.deb tmp")
sh("apt-get download netpbm")
sh("dpkg-deb -x netpbm_*.deb tmp")
sh("apt-get download latex2html")
sh("dpkg-deb -x latex2html_*.deb tmp")
sh("cd tmp/usr/share/latex2html; ln -sf ../../../etc/latex2html.conf l2hconf.pm")

sh("sed -i 's@PERL /usr@PERL {}/tmp/usr@' tmp/etc/latex2html.conf".format(os.getcwd()))
sh("sed -i 's@/usr/bin/pnm@{}/tmp/usr/bin/pnm@' tmp/etc/latex2html.conf".format(os.getcwd()))
sh("sed -i 's@/usr/bin/pnm@{}/tmp/usr/bin/pnm@' tmp/usr/bin/pstoimg".format(os.getcwd()))
sh("sed -i 's@/usr/bin/ppm@{}/tmp/usr/bin/ppm@' tmp/usr/bin/pstoimg".format(os.getcwd()))
sh("sed -i 's@/usr/bin/pbm@{}/tmp/usr/bin/pbm@' tmp/usr/bin/pstoimg".format(os.getcwd()))

# run make html
sh("export CURDIR=`pwd`; cd ../latex/; LATEX2HTMLDIR=$CURDIR/tmp/usr/share/latex2html LERL5LIB=$LATEX2HTMLDIR LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$CURDIR/tmp/usr/lib/ PATH=$PATH:$CURDIR/tmp/usr/bin/ make html")
sh("export CURDIR=`pwd`; cd ../jlatex/; LATEX2HTMLDIR=$CURDIR/tmp/usr/share/latex2html LERL5LIB=$LATEX2HTMLDIR LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$CURDIR/tmp/usr/lib/ PATH=$PATH:$CURDIR/tmp/usr/bin/ make html")

# copy result to docs and _build/html
sh("cd ../../; ln -sf doc/html docs")
sh("cp * _build/html/; echo 'ok'")

# custom settings conf.py
master_doc = 'index'

