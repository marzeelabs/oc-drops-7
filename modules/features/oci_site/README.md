# OCI Site
**Open Consortium Intranet site controller feature**

## About

Contains general settings we like to build upon Open Atrium (6.x) based intranets for Open Consortium.

## Installation

```sh
drush make oc_openatrium MYSITE --prepare-install
```
Builds a OC Intranet site ready to be installed

## Site Configuration

* Enable the `oci_site` feature; this will also enable all the other dependencies
* Create an admin account with the OC logo
* Go to /admin/build/themes/settings to configure logo and favicon
* Create a "General" group & enable some common features such as Files, Calendar, etc.
* Create a first user account with the "manager" role
* Add this user to a masquerade block (in Content area) from here: admin/settings/masquerade

## Issues

* Automation card on Trello that contains most links to previously built sites: https://trello.com/c/7laD8KyN/93-automate-oc-openatrium-install

## Credits

* http://marzeelabs.org
* [@marzeelabs](http://twitter.com/marzeelabs)
