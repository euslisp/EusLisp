#
# cwd = EUSDIR (/usr/local/eus)
cvs export -D "`date`" euslisp
cvs export -D "`date`" euslib
cvs export -D "`date`" eusdoc
cvs export -D "`date`" eusrobot
cvs export -D "`date`" euscontrib
ln -s lisp/c include
mkdir SunOS5; cd SunOS5; mkdir lib bin obj ; cd ..
mkdir Linux; cd Linux; mkdir lib bin obj ; cd ..
mkdir IRIX; cd IRIX; mkdir lib bin obj  ; cd ..

