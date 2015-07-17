; Open Consortium Make file
; @openconsortium
; by @marzeelabs

core = 7.x
api = 2

; Include base make files, originally from MZ
includes[] = mz.make
includes[] = mz_geo.make

; Projects
; --------

; Entities / Fields
projects[profile2][version] = 1.3
projects[profile2][subdir] = "contrib"
; Patch to provide support for entitycache; see issue https://drupal.org/node/1387268
projects[profile2][patch][] = "http://drupal.org/files/profile2-1387268-9.patch"
projects[calendar][version] = 3.5
projects[calendar][subdir] = "contrib"
projects[bean][version] = 1.9
projects[bean][subdir] = "contrib"
projects[blockreference][version] = 1.16
projects[blockreference][subdir] = "contrib"
projects[multiple_selects][version] = 1.2
projects[multiple_selects][subdir] = "contrib"

; Site Building
projects[views_field_view][version] = 1.1
projects[views_field_view][subdir] = "contrib"
projects[draggableviews][version] = 2.1
projects[draggableviews][subdir] = "contrib"

; Search
projects[search_api][version] = 1.8
projects[search_api][subdir] = "contrib"

; A bug in search_api_db prevents search_api_db fields to be created from exported search servers. Solution is to disable/enable any search features. See also http://drupal.org/node/1347438#comment-7038576
projects[search_api_db][version] = 1.x-dev
projects[search_api_db][subdir] = "contrib"
projects[search_api_db][download][revision] = "80d4070"
projects[search_api_page][version] = 1.2
projects[search_api_page][subdir] = "contrib"
projects[facetapi][version] = 1.3
projects[facetapi][subdir] = "contrib"

; Migrate
projects[migrate][version] = 2.8
projects[migrate][subdir] = "contrib"

projects[migrate_extras][version] = 2.5
projects[migrate_extras][subdir] = "contrib"
; Add support for bean migrate; see https://drupal.org/node/1977058
projects[migrate_extras][patch][] = "https://drupal.org/files/migrate_extras_entity_api_entity_keys_name.patch"


; Other
projects[webform][version] = 3.18
projects[webform][subdir] = "contrib"

projects[logintoboggan][version] = 1.5
projects[logintoboggan][subdir] = "contrib"

projects[maxlength][version] = 3.2
projects[maxlength][subdir] = "contrib"

;projects[votingapi][version] = 2.10
;projects[votingapi][subdir] = "contrib"

;projects[fivestar][version] = 2.1
;projects[fivestar][subdir] = "contrib"

projects[fitvids][version] = 1.17
projects[fitvids][subdir] = "contrib"

projects[flexslider][version] = 2.x-dev
projects[flexslider][subdir] = "contrib"
projects[flexslider][download][revision] = "19a7e49"

projects[menu_attributes][version] = 1.0-rc3
projects[menu_attributes][subdir] = "contrib"

projects[taxonomy_title][version] = 1.5
projects[taxonomy_title][subdir] = "contrib"

projects[better_exposed_filters][version] = 3.2
projects[better_exposed_filters][subdir] = "contrib"

projects[fonticon][version] = 1.x-dev
projects[fonticon][subdir] = "contrib"
projects[fonticon][download][revision] = "ddbbee5"

projects[smart_trim][version] = 1.5
projects[smart_trim][subdir] = "contrib"

projects[colorbox][version] = 2.9
projects[colorbox][subdir] = "contrib"

projects[imagecache_actions][version] = 1.5
projects[imagecache_actions][subdir] = "contrib"

projects[crumbs][version] = 1.10
projects[crumbs][subdir] = "contrib"

projects[taxonomy_access_fix][version] = 1.3
projects[taxonomy_access_fix][subdir] = "contrib"

projects[pathauto_entity][version] = 1.0
projects[pathauto_entity][subdir] = "contrib"

projects[chosen][version] = 2.0-beta4
projects[chosen][subdir] = "contrib"

; Reporting
; ---------

projects[google_analytics_reports][version] = 3.0-beta1
projects[google_analytics_reports][subdir] = "contrib"

projects[chart][version] = 1.1
projects[chart][subdir] = "contrib"

projects[oauth][version] = 3.2
projects[oauth][subdir] = "contrib"


; Custom modules or sandboxes
; ---------------------------

;
;

; Projects overwritten specifically for OC
; ----------------------------------------

; @todo remove
projects[spamicide][version] = 1.2
projects[spamicide][subdir] = "contrib"


; Optional projects
; -----------------

projects[field_collection][version] = 1.0-beta8
projects[field_collection][subdir] = "contrib"

; Themes
; ------

projects[zen][version] = 5.5

; Libraries
; ---------

libraries[flexslider][download][type] = "git"
libraries[flexslider][download][url] = "git://github.com/woothemes/FlexSlider.git"
libraries[flexslider][directory_name] = "flexslider"

libraries[fitvids][download][type] = "get"
libraries[fitvids][download][url] = "https://raw.github.com/davatron5000/FitVids.js/master/jquery.fitvids.js"
libraries[fitvids][directory_name] = "fitvids"

libraries[colorbox][download][type] = "git"
libraries[colorbox][download][url] = "git://github.com/jackmoore/colorbox.git"
libraries[colorbox][directory_name] = "colorbox"

libraries[chosen][download][type] = "get"
libraries[chosen][download][url] = "https://github.com/harvesthq/chosen/releases/download/1.4.2/chosen_v1.4.2.zip"
libraries[chosen][directory_name] = "chosen"
libraries[chosen][destination] = "libraries"
