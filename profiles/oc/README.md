Open Consortium
===============

The Open Consortium profile is a stand-alone package, i.e., there's no Drupal core or base modules on this repo.

In order to develop in your local environment you will follow the instructions to:

1. Download Drupal core, the MZ base profile and a snapshot of the OC profile (stable) with Drush
2. Replace the downloaded OC snapshot with your local OC repo
3. Build the website using your local OC repo and Phing

## Installation instructions

Clone this repository into an `oc` directory. This will be your profile folder, *not* your actual Drupal core folder as this repo only contains the OC profile.

	git clone github.com/marzeelabs/oc oc

Build the profile into an`oc-site` directory. This will be where your Drupal installation will reside (your docroot).

  drush make oc/build-oc.make oc-site

Now, to develop the OC profile within this Drupal installation, replace the `oc-site/profiles/oc` (snapshot) directory with a symlink to your local `oc` repository.

	cd oc-site
	rm -Rf profiles/oc
	ln -s /absolute/path/to/cloned/oc profiles/oc

You can now install your website with the OC profile from the branch of your choice.

-----

You can also set up `phing` to automate tasks such as site installation, contrib module updates, etc.

After creating a database, copy the `build.properties.example` to `build.properties`.

	cd oc-site/profiles/oc
	cp build.properties.example build.properties

Set up the `build.properties` file with your database connection string and absolute path for the oc-site directory (your Drupal installation). You are now able to use `phing build` in order to install a test website using your development OC profile.


## Credits

Points of contact : peter@marzeelabs.org

Development by Marzee Labs.
@marzeelabs
