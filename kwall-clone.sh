#!/bin/sh

git pull

DATE=$(date +%Y%m%d)
INCREMENT=0

until [ ! -e "kwall-${DATE}-${INCREMENT}" ] ; do
  echo "kwall-${DATE}-${INCREMENT}" already exists.
  INCREMENT=$((INCREMENT + 1))
done

git submodule add git@git.kwallco.com:kwall/sonoma.git "kwall-${DATE}-${INCREMENT}"

(
  cd "kwall-${DATE}-${INCREMENT}"
  git remote set-url origin git@github-appliance.sonoma.edu:drupal/kwall.git
  git push
)

git commit -m "Pulling latest source from KWALL" .gitmodules "kwall-${DATE}-${INCREMENT}"


git push --all
