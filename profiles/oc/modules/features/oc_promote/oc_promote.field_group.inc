<?php
/**
 * @file
 * oc_promote.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function oc_promote_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promoted_caption|node|featured_content|promoted_big';
  $field_group->group_name = 'group_promoted_caption';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'featured_content';
  $field_group->mode = 'promoted_big';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Caption',
    'weight' => '15',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Caption',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_promoted_caption|node|featured_content|promoted_big'] = $field_group;

  return $export;
}
