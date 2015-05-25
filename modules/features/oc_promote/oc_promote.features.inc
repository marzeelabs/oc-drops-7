<?php
/**
 * @file
 * oc_promote.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oc_promote_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function oc_promote_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function oc_promote_image_default_styles() {
  $styles = array();

  // Exported image style: oc_slideshow.
  $styles['oc_slideshow'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 700,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      4 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 700,
          'height' => 450,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'oc_slideshow',
  );

  // Exported image style: oc_small_block.
  $styles['oc_small_block'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 440,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'oc_small_block',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function oc_promote_node_info() {
  $items = array(
    'featured_content' => array(
      'name' => t('Featured content'),
      'base' => 'node_content',
      'description' => t('This will create a promoted content box that you can promote to the front page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
