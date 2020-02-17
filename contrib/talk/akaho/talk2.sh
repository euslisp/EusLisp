#!/bin/sh
DB=/usr/local/WWW/data/akaho/data/database
DB2=/usr/local/WWW/data/akaho/data/database2
TMP=/usr/local/WWW/data/akaho/data/tmp
NN=/usr/local/WWW/data/akaho/nn
FREQ=/usr/local/WWW/data/akaho/freq
RANDLINE=/usr/local/WWW/data/akaho/randline
echo 'Content-type: text/html'
echo ""

echo '<TITLE> Talk with me </TITLE>'
echo 'I am Valkyrie, let'"'"'s talk with me <hr>'
submit=`echo $QUERY_STRING | sed -e 's/+/ /g' -e 's/[Ii]nput=//' \
-e 's/%3F/?/g' -e 's/%27/'"'"/g -e 's/%2C/,/g' -e 's/%21/!/g'`
if [ a"$submit" != a ]; then
  # if TMP or DB do not exist, create it
  if [ ! -r $TMP ]; then
    echo "Talk with me" > $TMP
  fi
  if [ ! -w $DB ]; then
    touch $DB
  fi
  # TMP is my previous saying
  prev=`cat $TMP`
  ocode=`echo $prev | $FREQ`
  # register my saying and user answer to DB
  echo "$ocode" "$submit" >> $DB
  code=`echo "$submit" | $FREQ`
  # find nearest neighbor answer
  lineno=`$NN $code < $DB`
  fcode=`sed -n ${lineno}p $DB | awk '{print $1}'`
  egrep $fcode $DB > $DB.find
  mywc=`wc -l $DB.find | awk '{print $1}'`
  mymsg="`$RANDLINE $mywc $DB.find | sed 's/^[01]* //'`"
  #
  echo "$mymsg" > $TMP
  echo '<H1>' "$mymsg" '</H1> <hr>'
fi
echo '<b> Input any message (I will respond): <b>'
echo '<FORM ACTION=/htbin/talk.sh>'
echo '<INPUT TYPE=text NAME=input MAXLENGTH=256>'
echo '<INPUT TYPE=submit>'
echo '</FORM> <hr>'
echo '-&gt <A HREF='"/akaho/welcome.html"'>' Akaho\''s Home Page </A> <P>'
echo '<address> akaho@etl.go.jp </address>'
exit 0
