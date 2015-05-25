api = 2
core = 7.x

; Include the definition for how to build Drupal core directly
includes[] = drupal-org-core.make

; Download the install profile and recursively build all its dependencies:
projects[oc][type] = "profile"
projects[oc][download][type] = "git"
projects[oc][download][url] = "git@github.com:marzeelabs/oc.git"
projects[oc][download][branch] = "master"
