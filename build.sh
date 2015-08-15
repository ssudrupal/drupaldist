#!/bin/sh

DATE=$(date +%Y%m%d)
LOCK="ssu-lock.make"
DATELOCK="ssu-lock-$DATE.make"

# Make sure we have the latest
git pull

# About to rewrite this
rm -f $LOCK

# Make new locked makefile
drush make --no-build ssu.make --lock=$LOCK

# Temporary fix for version problem with alternate cores
perl -p -i -e 'if (m/^projects\[panopoly\]\[version\]/ and not m/7.x/) { s/ = "/ = "7.x-/; }' $LOCK

# Keep this exact version forever
cp -f $LOCK $DATELOCK
git add $DATELOCK
git commit -m auto $DATELOCK

CORE=$(grep '= "core"' $LOCK | cut -d[ -f2 | cut -d] -f1)
COREVER=$(grep "projects\[$CORE\]\[version\]" $LOCK | cut -d= -f2 | cut -d'"' -f2)

OUTPUTDIR="$CORE-$COREVER-$DATE"

# Actually make the output dir
rm -rf $OUTPUTDIR
drush make $LOCK $OUTPUTDIR

chgrp -R drupal $OUTPUTDIR
chmod -R g+w $OUTPUTDIR
find $OUTPUTDIR -type d -print0 | xargs --null chmod g+s

git add $LOCK
git commit -v ssu.make $LOCK

echo; echo ; echo
echo === Your new distribution is: $OUTPUTDIR
echo === For aegir, use $LOCK
