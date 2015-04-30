#!/usr/bin/bash

cd ~/eus/doc/latex
rm -fr /tmp/html
mkdir -p /tmp/html
latex2html -dir /tmp/html/ -local_icons -auto_prefix -iso_language JP manual -split 1 -no_navigation
# euslisp-docs, generate markdown from pandoc
sudo apt-get install -qq -y pandoc
cd /tmp/html
for file in manual*.html; do
    name=`basename $file .html`.md
    cp $file $file.tmp
    sed -i 's@<BR>@@' $file.tmp
    sed -i 's@ALIGN="CENTER"@@' $file.tmp
    pandoc -f html -t markdown -s $file.tmp -o $name
    sed -i 's@(\(.*\)\.html)@(\1)@g' $name
    rm $file.tmp
done

git clone http://github.com/jsk-ros-pkg/euslisp-docs /tmp/euslisp-docs
rm -fr  /tmp/euslisp-docs/site
rm -fr  /tmp/euslisp-docs/docs/euslisp/*
mkdir -p /tmp/euslisp-docs/docs/euslisp
mv *.md /tmp/euslisp-docs/docs/euslisp/
cp *.png /tmp/euslisp-docs/docs/euslisp/
cd /tmp/euslisp-docs
git add docs/euslisp/*
git commit -m "Update euslisp form $TRAVIS_COMMIT"
git push -f quiet https://$GH_TOKEN@github.com/jsk-ros-pkg/euslisp-docs/


