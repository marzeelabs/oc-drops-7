core = 7.x
api = 2

; Projects
; --------

projects[geofield][version] = 1.2
projects[geofield][subdir] = "contrib"

projects[leaflet][version] = 1.1
projects[leaflet][subdir] = "contrib"

projects[geophp][version] = 1.7
projects[geophp][subdir] = "contrib"

projects[geocoder][version] = 1.2
projects[geocoder][subdir] = "contrib"

projects[leaflet_markercluster][version] = 1.2
projects[leaflet_markercluster][subdir] = "contrib"

; Libraries
; ---------

;libraries[leaflet][type] = "libraries"
;libraries[leaflet][download][type] = "git"
;libraries[leaflet][download][url] = "git@github.com:Leaflet/Leaflet.git"
;libraries[leaflet][download][tag] = "v0.7.3"

libraries[leaflet][download][type] = "file"
libraries[leaflet][download][url] = "http://cdn.leafletjs.com/downloads/leaflet-0.7.3.zip"

libraries[leaflet_markercluster][type] = "libraries"
libraries[leaflet_markercluster][download][type] = "git"
libraries[leaflet_markercluster][download][url] = "https://github.com/Leaflet/Leaflet.markercluster"
libraries[leaflet_markercluster][download][tag] = "v0.4.0-hotfix.1"
