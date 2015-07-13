<?php
/**
 * @file
 * oc_base.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oc_base_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function oc_base_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function oc_base_image_default_styles() {
  $styles = array();

  // Exported image style: oc_elastislide.
  $styles['oc_elastislide'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 140,
          'height' => 140,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'oc_elastislide',
  );

  // Exported image style: oc_teaser_small.
  $styles['oc_teaser_small'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 50,
          'height' => 50,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'oc_teaser_small',
  );

  return $styles;
}
