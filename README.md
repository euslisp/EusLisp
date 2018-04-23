## [EusLisp] [![Build Status](https://travis-ci.org/euslisp/EusLisp.png?branch=master)](https://travis-ci.org/euslisp/EusLisp)

EusLisp was originally developed by [Dr. Toshihiro Matsui at AIST](http://staff.aist.go.jp/t.matsui/ )

This page and repository are maintained by [JSK](http://www.jsk.t.u-tokyo.ac.jp ) at The University of Tokyo.

### Introduction

EusLisp is an integrated programming system for the research on intelligent robots based on Common Lisp and Object-Oriented programming. The principal subjects in the field of robotics research are sensory data processing, visual environment recognition, collision avoiding motion planning, and task planning. In either problem, three dimensional shape models of robots and environment play crucial roles. A motivation to the development of EusLisp was a demand for an extensible solid modeler that can easily be made use of from higher level symbolic processing system. Investigations into traditional solid modelers proved that the vital requirement for their implementation language was the list processing capability to represent and manage topology among model components. Numerical computation power was also important, but locality of geometric computation suggested the provision of vector/matrix functions as built-ins would greatly ease programming. (From [EusLisp Manual, Part I, EusLisp Basics, 1. Introduction](http://staff.aist.go.jp/t.matsui/eus/intro/eusintro.html ))

### How To Download and Compile

### Installation

#### Binary Installation (Recommended)

Please check http://github.com/euslisp/jskeus for easy binary installation and how to run current
demo programs. Most of programs in EusLisp/lib/ EusLisp/contrib/ directories are outdated.

#### Source Installation (Experts Only)

Note: we strongly recommend you to check http://github.com/euslisp/jskeus for download and compile euslisp and irteus; humanoid model description and other useful function layer on euslisp. Following description is only for euslisp hard-core developers.


```
$ git clone https://github.com/euslisp/EusLisp euslisp
$ cd euslisp
$ export ARCHDIR=Linux64
$ export EUSDIR=`pwd`
$ export PATH=$PATH:$EUSDIR/$ARCHDIR/bin
$ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$EUSDIR/$ARCHDIR/lib
$ cd lisp
$ ln -sf Makefile.Linux64 Makefile
$ make eus0 eus1 eus2 eusg eusx eusgl eus
```

For cygwin sytem, set ARCHDIR=Cygwin and ln -sf Makefile.Cygwin Makefile<br>
For 32bit Linux system, set ARCHDIR=Linux and ln -sf Makefile.Linux.thread Makefile

### Documnets

See online [manual](http://euslisp.github.io/EusLisp/manual.html). (Japanese translation [manual](http://euslisp.github.io/EusLisp/jmanual.html))

Download PDF version ([English](https://github.com/euslisp/EusLisp/raw/master/doc/latex/manual.pdf), [Japanese](https://github.com/euslisp/EusLisp/raw/master/doc/jlatex/jmanual.pdf))

### Original EusLisp Homepage

* Check out original EusLisp homepage [EusLisp: Object-Oriented Concurrent Lisp with Solid Modeling Facilities](http://staff.aist.go.jp/t.matsui/eus/ )

### Robots using EusLisp based Robot Software

- Jijo-2 Robot
- Remote brain robots (apelike, hanzo, sasuke, igoid, akira, haru, gibbon, jikokuten, taro, kaz and many.....)
- Musculoskeletal humanoids:  Kotaro, Kojiro
- Robot Platform in JSK: Aibo, Hoap, HRP2W, HRP2JSK, PR2, Nao
