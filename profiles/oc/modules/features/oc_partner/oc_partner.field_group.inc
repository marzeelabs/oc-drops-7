<?php
/**
 * @file
 * oc_partner.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function oc_partner_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|node|partner|teaser_extended';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'partner';
  $field_group->mode = 'teaser_extended';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Partner Info',
    'weight' => '1',
    'children' => array(
      0 => 'field_partner_address',
      1 => 'field_partner_url',
      2 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Partner Info',
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
  $export['group_info|node|partner|teaser_extended'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_partner|node|partner|search';
  $field_group->group_name = 'group_partner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'partner';
  $field_group->mode = 'search';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group partner',
    'weight' => '1',
    'children' => array(
      0 => 'field_partner_address',
      1 => 'field_partner_logo',
      2 => 'field_partner_url',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Group partner',
      'instance_settings' => array(
        'classes' => 'group-partner field-group-div ',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_partner|node|partner|search'] = $field_group;

  return $export;
}
