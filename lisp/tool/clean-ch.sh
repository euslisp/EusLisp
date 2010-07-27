#!/bin/sh
#

find . -name '*.l' -print |
while read f
do
  d=`dirname $f`
  c=`basename $f .l`.c
  h=`basename $f .l`.h
  if [ -f $d/$c ]
  then
    rm -f $d/$c
  fi
  if [ -f $d/$h ]
  then
    rm -f $d/$h
  fi
done

