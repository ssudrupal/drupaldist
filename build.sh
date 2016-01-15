#!/bin/sh

# Collect git garbage to make thing stay small
git gc --auto > /dev/null

# Date in YYYYMMDD format for use in filenames
DATE=$(date +%Y%m%d)

MAKEFILES=$(find . -maxdepth 1 -name \*.make -not -name \*-\*)

for MAKE in $MAKEFILES; do

  BASENAME=$(basename ${MAKE} .make)

  # The makefile we build with versions locked, used to track changes
  LOCK="${BASENAME}.lock"

  # Make sure we have the latest copy of our makefile, etc
  git pull > /dev/null

  # Make new locked makefile
  drush make --no-build ${MAKE} --lock=$LOCK

  # Temporary fix for version problem with alternate cores
  perl -p -i -e 'if (m/^projects\[panopoly\]\[version\]/ and not m/7.x/) { s/ = "/ = "7.x-/; }' $LOCK

  # Check if there's any changes
  if git diff --quiet $LOCK; then
    echo "=== $LOCK has not changed since the last run."
    echo "=== That means there's probably no point in proceeding."
    read -p "=== Would you like to proceed anyways? [y/N] " PROCEEDUNCHANGED
    if [ -n "$PROCEEDUNCHANGED" ] && [ $PROCEEDUNCHANGED = "y" -o $PROCEEDUNCHANGED = "Y" ]; then
      echo "=== Ok, we're proceeding anyways"
    else
      echo "=== Exiting"
      exit 0
    fi
  fi
    

  # Extract which core/distribution we're using
  CORE=$(grep '= "core"' $LOCK | cut -d[ -f2 | cut -d] -f1)
  # and what version it is
  COREVER=$(grep "projects\[$CORE\]\[version\]" $LOCK | cut -d= -f2 | cut -d'"' -f2)

  # The directory we're going to put a distro into
  OUTPUTDIR="$BASENAME-$COREVER-$DATE"

  # A locked makefile that (usually) doesn't change, named to obviously match
  # the distro directory it was used to make
  DATELOCK="$OUTPUTDIR.make"

  # If there's no DATELOCK file, then go ahead and copy our lockfile to it
  # If it exists, but is the same as our lockfile, do nothing
  # If it exists, and is different, prompt the user about whether or not to change it.

  if ! [ -e $DATELOCK ]; then # No DATELOCK yet
    cp $LOCK $DATELOCK
    git add $DATELOCK
    git commit -m "Auto copied from $LOCK" $DATELOCK
    DATELOCKUPDATED=y
  elif cmp $LOCK $DATELOCK; then # no changes
    echo === $DATELOCK already like $LOCK
    git add $DATELOCK
    git commit -m "Already like $LOCK" $DATELOCK
    DATELOCKUPDATED=n
  else
    echo "=== There is already a locked makefile for today ($DATELOCK)."
    echo "=== Here are the differences: "
    diff -u $DATELOCK $LOCK
    read -p "=== Would you like to overwrite $DATELOCK with these changes? [y/N] " OVERWRITEDATELOCK
    if [ -n "$OVERWRITEDATELOCK" ] && [ $OVERWRITEDATELOCK = "y" -o $OVERWRITEDATELOCK = "Y" ]; then
      cp -f $LOCK $DATELOCK
      git add $DATELOCK
      git commit -m "Forced overwritten from $LOCK" $DATELOCK
      DATELOCKUPDATED=y
    else
      DATELOCKUPDATED=n
    fi
  fi

  # If directory doesn't exists, drush make it
  # If directory already exists, only drush make it if user answers yes to
  #   destruction
  if ! [ -d $OUTPUTDIR ]; then
    drush make $DATELOCK $OUTPUTDIR
  else
    echo "=== $OUTPUTDIR already exists."
    if [ $DATELOCKUPDATED = y ]; then
      echo "=== $DATELOCK is modified, so you probably want to recreate $OUTPUTDIR."
    else
      echo "=== $DATELOCK is unchanged, so $OUTPUTDIR probably should be left alone."
    fi
    read -p "=== Would you like to destroy $OUTPUTDIR? [y/N] " OVERWRITEOUTPUTDIR
    if [ -n "$OVERWRITEOUTPUTDIR" ] && [ $OVERWRITEOUTPUTDIR = "y" -o $OVERWRITEOUTPUTDIR = "Y" ]; then
      rm -rf $OUTPUTDIR
      drush make $DATELOCK $OUTPUTDIR
    fi
  fi

  # Ignore our new directory if it's not already ignored
  if ! grep -q $OUTPUTDIR .gitignore; then
    echo $OUTPUTDIR >> .gitignore
    git commit -m "Added $OUTPUTDIR" .gitignore
  fi

  # Ownership/permissions fixes
  chgrp -R drupal $OUTPUTDIR $LOCK $DATELOCK 2> /dev/null
  chmod -R g+w $OUTPUTDIR $LOCK $DATELOCK 2> /dev/null
  find $OUTPUTDIR -type d -print0 | xargs --null chmod g+s 2> /dev/null

  # Make sure old locked makefile is tracked by git
  git add $LOCK

  # Commit the manually edited makefiles, with verbosity so changes are shown
  #   to user.
  git commit -v ${MAKE} $LOCK ssu-*.make

  # Push changes upstream
  git push

  # And output the useful information to the user
  echo; echo ; echo
  echo === Your new distribution is: $OUTPUTDIR
  echo === For aegir, use $DATELOCK
done

git prune
git gc --auto --quiet
