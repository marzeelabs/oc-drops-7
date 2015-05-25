Open Consortium
===============

## Installation instructions

Clone this repository into a folder `oc`. This will be your profile folder, *not* your actual Drupal core folder.

	git clone github.com/marzeelabs/oc oc

Build the profile into a folder `oc-site`. This will be your Drupal installation in which to develop further the profile.

	drush make oc/build-oc.make oc-site

Now, to develop within this drupal installation, replace the downloaded `oc` profile with a symlink to the `oc` repository.

	cd oc-site
	rm -fr profiles/oc
	ln -s <github-oc> profiles/oc

Then, setup up `phing` to automate tasks such as site installation, contrib module updates, etc.


## Credits

Points of contact : peter@marzeelabs.org

Development by Marzee Labs.
@marzeelabs
