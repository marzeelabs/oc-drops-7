<?php
/**
 * @file
 * oc_profile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function oc_profile_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile|profile2|researcher_profile|page';
  $field_group->group_name = 'group_profile';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'researcher_profile';
  $field_group->mode = 'page';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group Profile',
    'weight' => '0',
    'children' => array(
      0 => 'field_rprofile_address',
      1 => 'field_rprofile_email',
      2 => 'field_rprofile_lab',
      3 => 'field_rprofile_photo',
      4 => 'field_rprofile_telephone',
      5 => 'field_rprofile_title',
      6 => 'field_rprofile_website',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Group Profile',
      'instance_settings' => array(
        'classes' => 'group-profile field-group-div ',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_profile|profile2|researcher_profile|page'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rprofile_admin|profile2|researcher_profile|form';
  $field_group->group_name = 'group_rprofile_admin';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'researcher_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Keywords',
    'weight' => '13',
    'children' => array(
      0 => 'field_rprofile_keywords',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Keywords',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_rprofile_admin|profile2|researcher_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rprofile_project|profile2|researcher_profile|form';
  $field_group->group_name = 'group_rprofile_project';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'researcher_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Research',
    'weight' => '12',
    'children' => array(
      0 => 'field_rprofile_desctitle',
      1 => 'field_rprofile_publications',
      2 => 'field_rprofile_short_bio',
      3 => 'field_rprofile_members',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Research',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_rprofile_project|profile2|researcher_profile|form'] = $field_group;

  return $export;
}
