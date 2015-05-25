<?php
/**
 * @file
 * mz_editorial.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mz_editorial_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
