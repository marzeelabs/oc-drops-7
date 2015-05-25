#!/bin/bash

# Enable the module
drush en features_status -y
drush fra -y
drush fs

OVERRIDDEN=`drush fs | grep  'OVERRIDDEN' | wc -l`
NEEDS_REVIEW=`drush fs | grep  'NEEDS_REVIEW' | wc -l`

if [ $OVERRIDDEN -ne "0" ] || [ $NEEDS_REVIEW -ne "0" ]
then
  echo "ERROR: Features aren't clean. Here is the log"
  drush features
  drush fs --diff
  exit 1
else
  # Features clean, no need to print them
  echo "[OK] Features are clean. Well done."
  exit 0
fi
