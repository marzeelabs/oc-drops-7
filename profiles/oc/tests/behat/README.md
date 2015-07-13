Behat tests
===========

See complete documentation at http://behat-drupal-extension.readthedocs.org/

Setup
-----

##Install Composer

```
curl -sS https://getcomposer.org/installer | php
mv composer.phar /usr/local/bin/composer
```

Note: If the above fails due to permissions, run the mv line again with sudo.
Then, just run composer in order to run Composer instead of php composer.phar.
more information here: https://getcomposer.org/doc/00-intro.md

##Install Behat and dependencies via Composer

```
cd profiles/oc/tests/behat
composer install
```

##Generate behat.yml

Copy `behat.yml.example` to `behat.yml` and modify `${drush.root}` and `${drupal.uri}`

- `cp behat.template.yml behat.yml`
- replace `${drush.root}` with your local url (example `http://domain.local`)
- replace `${drupal.uri}` with the absolute path to your project's webroot (example `/var/www/project_folder`)

##Install and run Selenium

- Go to http://docs.seleniumhq.org/download/ and download the latest Selenium server.
- Place the jar file in `/usr/local/lib/` and run:
- `java -jar /usr/local/lib/selenium-server-standalone-2.42.2.jar` (matching your downloaded version)

more information here: https://kalamuna.atlassian.net/wiki/pages/viewpage.action?pageId=1540111
If it complains about Java JDK, get it here: http://www.oracle.com/technetwork/java/javase/downloads/index.html


##Run Behat and examine test results!

```
cd profiles/oc/tests/behat
./bin/behat
```
