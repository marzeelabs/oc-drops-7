<?php
/**
 * @file
 * oc_project.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function oc_project_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|project|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'project_supervisors' => array(
      'weight' => '7',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:15:{s:23:"override_pager_settings";i:0;s:9:"use_pager";i:0;s:14:"nodes_per_page";s:1:"5";s:8:"pager_id";s:1:"0";s:6:"offset";s:1:"0";s:9:"more_link";i:0;s:10:"feed_icons";i:0;s:10:"panel_args";i:0;s:12:"link_to_view";i:0;s:4:"args";s:0:"";s:3:"url";s:0:"";s:7:"display";s:5:"block";s:7:"context";a:1:{i:0;s:0:"";}s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";}s:4:"type";s:5:"views";s:7:"subtype";s:19:"project_supervisors";}',
        'load_terms' => 0,
      ),
    ),
  );
  $export['node|project|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project|map';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project';
  $ds_fieldsetting->view_mode = 'map';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => 'title',
        'ft' => array(),
      ),
    ),
  );
  $export['node|project|map'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project|search';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project';
  $ds_fieldsetting->view_mode = 'search';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => 'title',
        'ft' => array(),
      ),
    ),
  );
  $export['node|project|search'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => 'title',
        'ft' => array(),
      ),
    ),
  );
  $export['node|project|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function oc_project_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'project_supervisors';
  $ds_field->label = 'Project supervisors';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['project_supervisors'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function oc_project_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'oc_2regions';
  $ds_layout->settings = array(
    'regions' => array(
      'primary' => array(
        0 => 'field_project_type',
        1 => 'field_project_status',
        2 => 'field_project_goal',
        3 => 'group_project_metadata',
        4 => 'field_project_nrpositions',
        5 => 'field_project_period',
        6 => 'body',
        7 => 'field_project_contact',
      ),
      'secondary' => array(
        8 => 'project_supervisors',
        9 => 'field_project_host',
      ),
    ),
    'fields' => array(
      'field_project_type' => 'primary',
      'field_project_status' => 'primary',
      'field_project_goal' => 'primary',
      'group_project_metadata' => 'primary',
      'field_project_nrpositions' => 'primary',
      'field_project_period' => 'primary',
      'body' => 'primary',
      'field_project_contact' => 'primary',
      'project_supervisors' => 'secondary',
      'field_project_host' => 'secondary',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'primary' => array(
        'grid-11 push-5 alpha' => 'grid-11 push-5 alpha',
      ),
      'secondary' => array(
        'grid-5 pull-11 omega' => 'grid-5 pull-11 omega',
      ),
    ),
    'wrappers' => array(
      'primary' => 'div',
      'secondary' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|project|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|map';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'map';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_project_nrpositions',
        2 => 'field_project_goal',
        3 => 'field_project_period',
        4 => 'body',
        5 => 'field_project_host',
        6 => 'field_project_supervisor',
        7 => 'field_project_type',
        8 => 'field_project_contact',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_project_nrpositions' => 'ds_content',
      'field_project_goal' => 'ds_content',
      'field_project_period' => 'ds_content',
      'body' => 'ds_content',
      'field_project_host' => 'ds_content',
      'field_project_supervisor' => 'ds_content',
      'field_project_type' => 'ds_content',
      'field_project_contact' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|project|map'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|search';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'search';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_project_host',
        2 => 'field_project_type',
        3 => 'field_project_status',
        4 => 'field_project_period',
        5 => 'group_project_metadata',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_project_host' => 'ds_content',
      'field_project_type' => 'ds_content',
      'field_project_status' => 'ds_content',
      'field_project_period' => 'ds_content',
      'group_project_metadata' => 'ds_content',
    ),
    'limit' => array(
      'field_project_host' => '1',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|project|search'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_project_host',
        1 => 'title',
        2 => 'field_project_goal',
        3 => 'group_project_metadata',
        4 => 'field_project_status',
        5 => 'field_project_period',
      ),
    ),
    'fields' => array(
      'field_project_host' => 'ds_content',
      'title' => 'ds_content',
      'field_project_goal' => 'ds_content',
      'group_project_metadata' => 'ds_content',
      'field_project_status' => 'ds_content',
      'field_project_period' => 'ds_content',
    ),
    'limit' => array(
      'field_project_host' => '1',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|project|teaser'] = $ds_layout;

  return $export;
}
