<?php
/**
 * @file
 * oc_profile.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function oc_profile_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'profile2|researcher_profile|map';
  $ds_fieldsetting->entity_type = 'profile2';
  $ds_fieldsetting->bundle = 'researcher_profile';
  $ds_fieldsetting->view_mode = 'map';
  $ds_fieldsetting->settings = array(
    'researcher_full_name_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'researcher_location' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['profile2|researcher_profile|map'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'profile2|researcher_profile|page';
  $ds_fieldsetting->entity_type = 'profile2';
  $ds_fieldsetting->bundle = 'researcher_profile';
  $ds_fieldsetting->view_mode = 'page';
  $ds_fieldsetting->settings = array(
    'research_wp_leader' => array(
      'weight' => '7',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:15:{s:23:"override_pager_settings";i:0;s:9:"use_pager";i:0;s:14:"nodes_per_page";s:1:"0";s:8:"pager_id";s:1:"0";s:6:"offset";s:1:"0";s:9:"more_link";i:0;s:10:"feed_icons";i:0;s:10:"panel_args";i:0;s:12:"link_to_view";i:0;s:4:"args";s:0:"";s:3:"url";s:0:"";s:7:"display";s:5:"block";s:7:"context";a:1:{i:0;s:33:"argument_entity_id:profile2_1.pid";}s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";}s:4:"type";s:5:"views";s:7:"subtype";s:21:"work_packages_profile";}',
        'load_terms' => 0,
        'ft' => array(
          'lb' => 'Work Packages as Leader',
        ),
      ),
    ),
    'researcher_profile_projects' => array(
      'weight' => '6',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:15:{s:23:"override_pager_settings";i:0;s:9:"use_pager";i:0;s:14:"nodes_per_page";s:1:"0";s:8:"pager_id";s:1:"0";s:6:"offset";s:1:"0";s:9:"more_link";i:0;s:10:"feed_icons";i:0;s:10:"panel_args";i:0;s:12:"link_to_view";i:0;s:4:"args";s:0:"";s:3:"url";s:0:"";s:7:"display";s:7:"block_2";s:7:"context";a:1:{i:0;s:33:"argument_entity_id:profile2_1.pid";}s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";}s:4:"type";s:5:"views";s:7:"subtype";s:12:"project_jobs";}',
        'load_terms' => 0,
        'ft' => array(
          'lb' => 'Supervised projects',
        ),
      ),
    ),
    'researcher_wp_contributor' => array(
      'weight' => '8',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:15:{s:23:"override_pager_settings";i:0;s:9:"use_pager";i:0;s:14:"nodes_per_page";s:1:"0";s:8:"pager_id";s:1:"0";s:6:"offset";s:1:"0";s:9:"more_link";i:0;s:10:"feed_icons";i:0;s:10:"panel_args";i:0;s:12:"link_to_view";i:0;s:4:"args";s:0:"";s:3:"url";s:0:"";s:7:"display";s:7:"block_1";s:7:"context";a:1:{i:0;s:33:"argument_entity_id:profile2_1.pid";}s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";}s:4:"type";s:5:"views";s:7:"subtype";s:21:"work_packages_profile";}',
        'load_terms' => 0,
        'ft' => array(
          'lb' => 'Work Packages as Contributor',
        ),
      ),
    ),
    'field_rprofile_partner_ref' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Institution',
        ),
      ),
    ),
  );
  $export['profile2|researcher_profile|page'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'profile2|researcher_profile|search';
  $ds_fieldsetting->entity_type = 'profile2';
  $ds_fieldsetting->bundle = 'researcher_profile';
  $ds_fieldsetting->view_mode = 'search';
  $ds_fieldsetting->settings = array(
    'researcher_full_name_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['profile2|researcher_profile|search'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'profile2|researcher_profile|teaser';
  $ds_fieldsetting->entity_type = 'profile2';
  $ds_fieldsetting->bundle = 'researcher_profile';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'researcher_full_name_link' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_rprofile_photo' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['profile2|researcher_profile|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'profile2|researcher_profile|teaser_small';
  $ds_fieldsetting->entity_type = 'profile2';
  $ds_fieldsetting->bundle = 'researcher_profile';
  $ds_fieldsetting->view_mode = 'teaser_small';
  $ds_fieldsetting->settings = array(
    'researcher_full_name_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_rprofile_photo' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['profile2|researcher_profile|teaser_small'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function oc_profile_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'full_name';
  $ds_field->label = 'Full name';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'profile2' => 'profile2',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[profile2:field_rprofile_first_name] [profile2:field_rprofile_last_name]',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['full_name'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'research_wp_leader';
  $ds_field->label = 'Research WP Leader';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'profile2' => 'profile2',
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
  $export['research_wp_leader'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'researcher_full_name_link';
  $ds_field->label = 'Researcher full name link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'profile2' => 'profile2',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a href="[profile2:url]"><span class="nowrap">[profile2:field_rprofile_first_name]</span> <span class="nowrap">[profile2:field_rprofile_last_name]</span></a>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['researcher_full_name_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'researcher_location';
  $ds_field->label = 'Researcher Location';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'profile2' => 'profile2',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<span aria-hidden="true" class="oc-icon" data-icon="&#xe000;"></span><span class="profile-city">[profile2:field-rprofile-address:locality]</span>, <span class="profile-country">[profile2:field-rprofile-address:country]</span>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['researcher_location'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'researcher_profile_projects';
  $ds_field->label = 'Researcher Profile Projects';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'profile2' => 'profile2',
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
  $export['researcher_profile_projects'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'researcher_wp_contributor';
  $ds_field->label = 'Researcher WP Contributor';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'profile2' => 'profile2',
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
  $export['researcher_wp_contributor'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function oc_profile_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'profile2|researcher_profile|map';
  $ds_layout->entity_type = 'profile2';
  $ds_layout->bundle = 'researcher_profile';
  $ds_layout->view_mode = 'map';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_rprofile_photo',
        1 => 'researcher_full_name_link',
        2 => 'field_rprofile_title',
        3 => 'field_rprofile_email',
        4 => 'field_rprofile_website',
        5 => 'field_rprofile_telephone',
        6 => 'field_rprofile_partner_ref',
        7 => 'researcher_location',
      ),
    ),
    'fields' => array(
      'field_rprofile_photo' => 'ds_content',
      'researcher_full_name_link' => 'ds_content',
      'field_rprofile_title' => 'ds_content',
      'field_rprofile_email' => 'ds_content',
      'field_rprofile_website' => 'ds_content',
      'field_rprofile_telephone' => 'ds_content',
      'field_rprofile_partner_ref' => 'ds_content',
      'researcher_location' => 'ds_content',
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
  $export['profile2|researcher_profile|map'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'profile2|researcher_profile|page';
  $ds_layout->entity_type = 'profile2';
  $ds_layout->bundle = 'researcher_profile';
  $ds_layout->view_mode = 'page';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_profile',
        1 => 'field_rprofile_desctitle',
        2 => 'field_rprofile_short_bio',
        3 => 'field_rprofile_publications',
        4 => 'field_rprofile_partner_ref',
        5 => 'field_rprofile_members',
        6 => 'field_rprofile_photo',
        7 => 'researcher_profile_projects',
        8 => 'research_wp_leader',
        9 => 'field_rprofile_title',
        10 => 'field_rprofile_lab',
        11 => 'researcher_wp_contributor',
        12 => 'field_rprofile_location',
        13 => 'field_rprofile_website',
        14 => 'field_rprofile_email',
        15 => 'field_rprofile_telephone',
        16 => 'field_rprofile_address',
      ),
    ),
    'fields' => array(
      'group_profile' => 'ds_content',
      'field_rprofile_desctitle' => 'ds_content',
      'field_rprofile_short_bio' => 'ds_content',
      'field_rprofile_publications' => 'ds_content',
      'field_rprofile_partner_ref' => 'ds_content',
      'field_rprofile_members' => 'ds_content',
      'field_rprofile_photo' => 'ds_content',
      'researcher_profile_projects' => 'ds_content',
      'research_wp_leader' => 'ds_content',
      'field_rprofile_title' => 'ds_content',
      'field_rprofile_lab' => 'ds_content',
      'researcher_wp_contributor' => 'ds_content',
      'field_rprofile_location' => 'ds_content',
      'field_rprofile_website' => 'ds_content',
      'field_rprofile_email' => 'ds_content',
      'field_rprofile_telephone' => 'ds_content',
      'field_rprofile_address' => 'ds_content',
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
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['profile2|researcher_profile|page'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'profile2|researcher_profile|search';
  $ds_layout->entity_type = 'profile2';
  $ds_layout->bundle = 'researcher_profile';
  $ds_layout->view_mode = 'search';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_rprofile_photo',
        1 => 'researcher_full_name_link',
        2 => 'field_rprofile_title',
        3 => 'field_rprofile_email',
        4 => 'field_rprofile_website',
        5 => 'field_rprofile_telephone',
      ),
    ),
    'fields' => array(
      'field_rprofile_photo' => 'ds_content',
      'researcher_full_name_link' => 'ds_content',
      'field_rprofile_title' => 'ds_content',
      'field_rprofile_email' => 'ds_content',
      'field_rprofile_website' => 'ds_content',
      'field_rprofile_telephone' => 'ds_content',
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
  $export['profile2|researcher_profile|search'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'profile2|researcher_profile|teaser';
  $ds_layout->entity_type = 'profile2';
  $ds_layout->bundle = 'researcher_profile';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'oc_2regions';
  $ds_layout->settings = array(
    'regions' => array(
      'primary' => array(
        0 => 'researcher_full_name_link',
      ),
      'secondary' => array(
        1 => 'field_rprofile_photo',
        2 => 'field_rprofile_title',
        3 => 'field_rprofile_partner_ref',
      ),
    ),
    'fields' => array(
      'researcher_full_name_link' => 'primary',
      'field_rprofile_photo' => 'secondary',
      'field_rprofile_title' => 'secondary',
      'field_rprofile_partner_ref' => 'secondary',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
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
  $export['profile2|researcher_profile|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'profile2|researcher_profile|teaser_small';
  $ds_layout->entity_type = 'profile2';
  $ds_layout->bundle = 'researcher_profile';
  $ds_layout->view_mode = 'teaser_small';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_rprofile_photo',
        1 => 'researcher_full_name_link',
        2 => 'field_rprofile_title',
      ),
    ),
    'fields' => array(
      'field_rprofile_photo' => 'ds_content',
      'researcher_full_name_link' => 'ds_content',
      'field_rprofile_title' => 'ds_content',
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
    'layout_attributes_merge' => 1,
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['profile2|researcher_profile|teaser_small'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function oc_profile_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teaser_small';
  $ds_view_mode->label = 'Teaser Small';
  $ds_view_mode->entities = array(
    'profile2' => 'profile2',
  );
  $export['teaser_small'] = $ds_view_mode;

  return $export;
}
