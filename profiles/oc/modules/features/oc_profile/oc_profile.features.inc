<?php
/**
 * @file
 * oc_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oc_profile_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "snippet" && $api == "default_snippet") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function oc_profile_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function oc_profile_image_default_styles() {
  $styles = array();

  // Exported image style: oc_user_large.
  $styles['oc_user_large'] = array(
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'oc_user_large',
  );

  // Exported image style: oc_user_medium.
  $styles['oc_user_medium'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'oc_user_medium',
  );

  // Exported image style: oc_user_small.
  $styles['oc_user_small'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 60,
          'height' => 60,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'oc_user_small',
  );

  return $styles;
}

/**
 * Implements hook_default_profile2_type().
 */
function oc_profile_default_profile2_type() {
  $items = array();
  $items['researcher_profile'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "researcher_profile",
    "label" : "Researcher Profile",
    "weight" : "0",
    "data" : { "registration" : 1, "use_page" : 1 }
  }');
  return $items;
}
