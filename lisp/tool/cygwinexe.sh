#! /bin/sh

shift
EXE=$1
EXEBASE=`basename $1`
EXEDIR=`dirname $1`
BASE=`echo $EXEBASE | cut -f 1 -d '.'`
DEF=$EXEDIR/$BASE.def
EXP=$EXEDIR/$BASE.exp
BAS=$EXEDIR/$BASE.base
LIB=$EXEDIR/$BASE.a
shift
ARGS=$@
GCC="gcc -g"
GCCVERSION=`$GCC -dumpversion`
LIBS="-L/usr/lib/gcc-lib/i686-pc-cygwin/$GCCVERSION -lgcc -lcygwin -lkernel32 -lc"

for arg in $ARGS;
do
if [ "o" = "`basename $arg | cut -f 2 -d '.'`" ]; then
    OBJS="$OBJS $arg"
elif [ "o" = "`basename $arg | cut -f 3 -d '.'`" ]; then
    OBJS="$OBJS $arg"
else
    FLAGS="$FLAGS $arg"
fi
done

ld --export-all-symbols -o $EXE --base-file $BAS $OBJS $FLAGS $LIBS -L$EUSDIR/$ARCHDIR/lib
echo 1
$GCC -Wl,--export-all-symbols -o $EXE --base-file $OBJS $FLAGS $LIBS -L$EUSDIR/$ARCHDIR/lib
echo 1.5
dlltool --export-all-symbols --kill-at -z $DEF.tmp $OBJS
perl -e "$\=\"\n\"; while(<>){s/@.*$//g;s/\s//g;s/^CODE$//g;print;}" $DEF.tmp > $DEF
echo 2
dlltool --as=as --dllname $EXE --def $DEF --base-file $BAS --output-exp $EXP
echo 3
$GCC -Wl,--export-all-symbols -o $EXE $EXP $OBJS $FLAGS -L$EUSDIR/$ARCHDIR/lib
echo 4
dlltool --as=as --dllname $EXEBASE --def $DEF --base-file $BAS --output-exp $EXP
echo 5
dlltool --as=as --dllname $EXEBASE --def $DEF --output-lib $LIB


