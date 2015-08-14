#!/bin/sh

rm -rf ssu-test

git pull
drush make --no-build ssu.make --lock=ssu-lock.make
git commit -m auto ssu-lock.make

drush make ssu-lock.make ssu-test
