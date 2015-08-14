#!/bin/sh

CORE=$(grep '= "core"' ssu-lock.make | cut -d[ -f2 | cut -d] -f1)
COREVER=$(grep "projects\[$CORE\]\[version\]" ssu-lock.make | cut -d= -f2 | cut -d'"' -f2)
DATE=$(date +%Y%m%d)

git pull
drush make --no-build ssu.make --lock=ssu-lock.make

git commit -m auto ssu-lock.make
perl -p -i.bak -e 'if (m/^projects\[panopoly\]\[version\]/ and not m/7.x/) { s/ = "/ = "7.x-/; }' ssu-lock.make
git commit -m 'version fix' ssu-lock.make


OUTPUTDIR="$CORE-$COREVER-$DATE"

drush make ssu-lock.make $OUTPUTDIR

chgrp -R drupal $OUTPUTDIR
chmod -R g+w $OUTPUTDIR
find $OUTPUTDIR -type d -print0 | xargs --null chmod g+s
