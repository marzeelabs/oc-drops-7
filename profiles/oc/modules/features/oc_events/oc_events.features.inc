<?php
/**
 * @file
 * oc_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oc_events_ctools_plugin_api($module = NULL, $api = NULL) {
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
function oc_events_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function oc_events_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('An event will be displayed in the calendar section.'),
      'has_title' => '1',
      'title_label' => t('Event'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
