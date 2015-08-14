#!/bin/sh

rm -rf ssu-test

git pull
drush make --no-build ssu.make --lock=ssu-lock.make

git commit -m auto ssu-lock.make
perl -p -i.bak -e 'if (m/^projects\[panopoly\]\[version\]/ and not m/7.x/) { s/ = "/ = "7.x-/; }' ssu-lock.make
git commit -m 'version fix' ssu-lock.make

drush make ssu-lock.make ssu-test
