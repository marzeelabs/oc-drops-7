<?php

/**
 * @file
 * API documentation for OC Site.
 */

/**
 * Alter the list of logos provided by OC.
 */
function hook_oc_site_logos_alter(&$logos) {
  $logos['europe'] = array(
    'img' => $img_path . 'europe.png',
    'title' => t("European Comission"),
    'link' => '#',
  );
}
