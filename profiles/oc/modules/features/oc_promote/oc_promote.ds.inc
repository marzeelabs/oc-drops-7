<?php
/**
 * @file
 * oc_promote.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function oc_promote_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|featured_content|promoted_big';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'featured_content';
  $ds_fieldsetting->view_mode = 'promoted_big';
  $ds_fieldsetting->settings = array(
    'promoted_read_more' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'field_promoted_media' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|featured_content|promoted_big'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|featured_content|promoted_small';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'featured_content';
  $ds_fieldsetting->view_mode = 'promoted_small';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|featured_content|promoted_small'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function oc_promote_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'promoted_read_more';
  $ds_field->label = 'Promoted Read More';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array();
  $export['promoted_read_more'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function oc_promote_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|featured_content|promoted_big';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'featured_content';
  $ds_layout->view_mode = 'promoted_big';
  $ds_layout->layout = 'oc_2regions';
  $ds_layout->settings = array(
    'regions' => array(
      'primary' => array(
        0 => 'field_promoted_media',
      ),
      'secondary' => array(
        1 => 'title',
        2 => 'field_promoted_text',
        3 => 'promoted_read_more',
      ),
    ),
    'fields' => array(
      'field_promoted_media' => 'primary',
      'title' => 'secondary',
      'field_promoted_text' => 'secondary',
      'promoted_read_more' => 'secondary',
    ),
    'classes' => array(),
    'wrappers' => array(
      'primary' => 'div',
      'secondary' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|featured_content|promoted_big'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|featured_content|promoted_small';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'featured_content';
  $ds_layout->view_mode = 'promoted_small';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_promoted_media',
        1 => 'title',
        2 => 'field_promoted_text',
      ),
    ),
    'fields' => array(
      'field_promoted_media' => 'ds_content',
      'title' => 'ds_content',
      'field_promoted_text' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|featured_content|promoted_small'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function oc_promote_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'promoted_big';
  $ds_view_mode->label = 'Promoted big';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'file' => 'file',
  );
  $export['promoted_big'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'promoted_small';
  $ds_view_mode->label = 'Promoted small';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'file' => 'file',
  );
  $export['promoted_small'] = $ds_view_mode;

  return $export;
}
