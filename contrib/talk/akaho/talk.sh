#!/bin/sh
DB=/usr/local/WWW/data/akaho/data/database
DB2=/usr/local/WWW/data/akaho/data/database2
TMPDB=/tmp/talk.find
TMP=/tmp/talk.tmp
NN=/usr/local/WWW/data/akaho/nn
FREQ=/usr/local/WWW/data/akaho/freq
RANDLINE=/usr/local/WWW/data/akaho/randline
echo 'Content-type: text/html'
echo ""

echo '<TITLE> Talk with me </TITLE>'
echo 'I am Valkyrie, let'"'"'s talk with me <hr>'

submit=`echo $QUERY_STRING | sed \
  -e 's/+/ /g' -e 's/[Ii]nput=//' \
  -e 's/%3F/?/g' -e 's/%27/'"'"/g \
  -e 's/%20/ /g' \
  -e 's/%2C/,/g' -e 's/%21/!/g'`
if [ A"$submit" != A ]; then
  # if TMP/DB/DB2 do not exist, create it
  if [ ! -r $TMP ]; then
    echo "Talk with me" > $TMP
  fi
  if [ ! -w $DB ]; then
    touch $DB
  fi
  if [ ! -w $DB ]; then
    touch $DB2
  fi
  # TMP is my previous saying
  prev=`cat $TMP`
  ocode=`echo $prev | $FREQ`
  # register my saying and user answer to DB
  echo "$ocode" "$submit" >> $DB
  code=`echo "$submit" | $FREQ`
  # find nearest neighbor answer
  lineno=`$NN $code 5 < $DB`
  echo "$code" "$submit" >> $DB2
  if [ $lineno -eq 0 ]; then
    mywc=`wc -l $DB2 | awk '{print $1}'`
    mytmp="`$RANDLINE $mywc $DB2`"
    mymsg="`echo $mytmp | sed 's/^[0-9]* //'`"
    ocode=`echo "$mymsg" | $FREQ`
    sed "/$ocode/d" $DB2 > $DB2.tmp
    mv $DB2.tmp $DB2
  else
    fcode=`sed -n ${lineno}p $DB | awk '{print $1}'`
    egrep $fcode $DB > $TMPDB
    mywc=`wc -l $TMPDB | awk '{print $1}'`
    mymsg="`$RANDLINE $mywc $TMPDB | sed 's/^[0-9]* //'`"
  fi
  #
  echo "$mymsg" > $TMP
  echo '<H1>' "$mymsg" '</H1> <hr>'
else
  mymsg=`ls -l $DB | awk '{print $5, $6, $7}'`
  echo '<H1> I cannot respond to nothing. </H1>'
  echo last talk: "$mymsg" '<hr>'
fi

echo '<b> Input any message (I will respond): <b>'
echo '<FORM ACTION=/htbin/talk.sh>'
echo '<INPUT TYPE=text NAME=input MAXLENGTH=256>'
echo '<INPUT TYPE=submit>'
echo '</FORM> <hr>'
echo '-&gt <A HREF='"/akaho/welcome.html"'>' Akaho\''s Home Page </A> <P>'
echo '<address> akaho@etl.go.jp </address>'

exit 0


