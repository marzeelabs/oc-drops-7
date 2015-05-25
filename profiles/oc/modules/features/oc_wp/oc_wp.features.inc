<?php
/**
 * @file
 * oc_wp.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oc_wp_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function oc_wp_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function oc_wp_node_info() {
  $items = array(
    'wp' => array(
      'name' => t('Work Package'),
      'base' => 'node_content',
      'description' => t('A <em>work package</em> relates to one specific activity type within the project. It has an associated <em>institution</em> and <em>researcher profile</em> that is coordinating the work.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
