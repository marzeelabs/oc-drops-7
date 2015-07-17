<?php
/**
 * @file
 * oc_profile.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function oc_profile_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'oc_profile_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Profiles List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Network';
  $handler->display->display_options['css_class'] = 'view-grid';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Relationship: Profile: Profile Keywords (field_rprofile_keywords) */
  $handler->display->display_options['relationships']['field_rprofile_keywords_tid']['id'] = 'field_rprofile_keywords_tid';
  $handler->display->display_options['relationships']['field_rprofile_keywords_tid']['table'] = 'field_data_field_rprofile_keywords';
  $handler->display->display_options['relationships']['field_rprofile_keywords_tid']['field'] = 'field_rprofile_keywords_tid';
  $handler->display->display_options['relationships']['field_rprofile_keywords_tid']['label'] = 'Profile Type';
  $handler->display->display_options['relationships']['field_rprofile_keywords_tid']['required'] = TRUE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'workbench_profile:page';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_arguments'] = 'none';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'field_rprofile_keywords_tid';
  $handler->display->display_options['arguments']['name']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['name']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['name']['title'] = '%1';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['default_argument_options']['argument'] = 'partner';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['name']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['name']['validate_options']['vocabularies'] = array(
    'researcher_profile_type' => 'researcher_profile_type',
  );
  $handler->display->display_options['arguments']['name']['validate_options']['type'] = 'name';
  $handler->display->display_options['arguments']['name']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  $handler->display->display_options['arguments']['name']['transform_dash'] = TRUE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'researcher_profile' => 'researcher_profile',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'network/%';
  $export['oc_profile_list'] = $view;

  $view = new view();
  $view->name = 'oc_profile_partners';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Researcher Profiles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Partners';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Added soon';
  $handler->display->display_options['empty']['area']['content'] = 'Will be added soon.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Profile: Profile Keywords (field_rprofile_keywords) */
  $handler->display->display_options['relationships']['field_rprofile_keywords_tid']['id'] = 'field_rprofile_keywords_tid';
  $handler->display->display_options['relationships']['field_rprofile_keywords_tid']['table'] = 'field_data_field_rprofile_keywords';
  $handler->display->display_options['relationships']['field_rprofile_keywords_tid']['field'] = 'field_rprofile_keywords_tid';
  $handler->display->display_options['relationships']['field_rprofile_keywords_tid']['label'] = 'Profile Keyword';
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  /* Sort criterion: Profile: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'profile';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'researcher_profile' => 'researcher_profile',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Profile: Profile Keywords (field_rprofile_keywords) */
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['id'] = 'field_rprofile_keywords_tid';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['table'] = 'field_data_field_rprofile_keywords';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['field'] = 'field_rprofile_keywords_tid';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['vocabulary'] = 'researcher_profile_type';

  /* Display: Partners */
  $handler = $view->new_display('page', 'Partners', 'page');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'view-grid';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'network/partners';

  /* Display: Fellows */
  $handler = $view->new_display('page', 'Fellows', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Fellows';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'view-grid';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'researcher_profile' => 'researcher_profile',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Profile: Profile Keywords (field_rprofile_keywords) */
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['id'] = 'field_rprofile_keywords_tid';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['table'] = 'field_data_field_rprofile_keywords';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['field'] = 'field_rprofile_keywords_tid';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['vocabulary'] = 'researcher_profile_type';
  $handler->display->display_options['path'] = 'network/fellows';

  /* Display: Advisory Board */
  $handler = $view->new_display('page', 'Advisory Board', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Advisory Board';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'view-grid';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'researcher_profile' => 'researcher_profile',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Profile: Profile Keywords (field_rprofile_keywords) */
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['id'] = 'field_rprofile_keywords_tid';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['table'] = 'field_data_field_rprofile_keywords';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['field'] = 'field_rprofile_keywords_tid';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['operator'] = 'and';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['vocabulary'] = 'researcher_profile_type';
  $handler->display->display_options['path'] = 'network/advisory-board';

  /* Display: Contact Persons */
  $handler = $view->new_display('block', 'Contact Persons', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Contact Persons';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Profile: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'profile';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'researcher_profile' => 'researcher_profile',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Profile: Profile Keywords (field_rprofile_keywords) */
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['id'] = 'field_rprofile_keywords_tid';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['table'] = 'field_data_field_rprofile_keywords';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['field'] = 'field_rprofile_keywords_tid';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['vocabulary'] = 'researcher_profile_type';
  $export['oc_profile_partners'] = $view;

  $view = new view();
  $view->name = 'researcher_profile_teaser';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Researcher profile teaser';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Project supervisors';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'researcher_profile' => 'researcher_profile',
  );

  /* Display: Teaser Block */
  $handler = $view->new_display('block', 'Teaser Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['researcher_profile_teaser'] = $view;

  $view = new view();
  $view->name = 'workbench_profile';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Workbench Profile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Workbench Profile';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit any researcher_profile profile';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter List';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '50,100,250';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = 'Every researcher is associated with a real user on the site. You can change the user\'s settings such as password and email address by clicking on <i>edit user settings</i>. Every researcher also has a rich profile which contains their research project, associated institution, etc. You can change the profiles by clicking on <i>edit researcher profile</i>.

You can organize the list of researchers by grabbing the handle on the left side, next to the photo.  ';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Field: Draggableviews: Profile */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'profile';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = 'Drag to reorder';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Field: Profile: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_profile2';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Global: Base URL */
  $handler->display->display_options['fields']['oc_base_base_url']['id'] = 'oc_base_base_url';
  $handler->display->display_options['fields']['oc_base_base_url']['table'] = 'views';
  $handler->display->display_options['fields']['oc_base_base_url']['field'] = 'oc_base_base_url';
  $handler->display->display_options['fields']['oc_base_base_url']['label'] = '';
  $handler->display->display_options['fields']['oc_base_base_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['oc_base_base_url']['element_label_colon'] = FALSE;
  /* Field: Profile: User uid */
  $handler->display->display_options['fields']['user_1']['id'] = 'user_1';
  $handler->display->display_options['fields']['user_1']['table'] = 'profile';
  $handler->display->display_options['fields']['user_1']['field'] = 'user';
  $handler->display->display_options['fields']['user_1']['exclude'] = TRUE;
  /* Field: Profile: Photo */
  $handler->display->display_options['fields']['field_rprofile_photo']['id'] = 'field_rprofile_photo';
  $handler->display->display_options['fields']['field_rprofile_photo']['table'] = 'field_data_field_rprofile_photo';
  $handler->display->display_options['fields']['field_rprofile_photo']['field'] = 'field_rprofile_photo';
  $handler->display->display_options['fields']['field_rprofile_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_rprofile_photo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Profile: First name */
  $handler->display->display_options['fields']['field_rprofile_first_name']['id'] = 'field_rprofile_first_name';
  $handler->display->display_options['fields']['field_rprofile_first_name']['table'] = 'field_data_field_rprofile_first_name';
  $handler->display->display_options['fields']['field_rprofile_first_name']['field'] = 'field_rprofile_first_name';
  $handler->display->display_options['fields']['field_rprofile_first_name']['exclude'] = TRUE;
  /* Field: Profile: Last name */
  $handler->display->display_options['fields']['field_rprofile_last_name']['id'] = 'field_rprofile_last_name';
  $handler->display->display_options['fields']['field_rprofile_last_name']['table'] = 'field_data_field_rprofile_last_name';
  $handler->display->display_options['fields']['field_rprofile_last_name']['field'] = 'field_rprofile_last_name';
  $handler->display->display_options['fields']['field_rprofile_last_name']['label'] = 'Researcher name';
  $handler->display->display_options['fields']['field_rprofile_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_rprofile_last_name']['alter']['text'] = '[field_rprofile_first_name] [field_rprofile_last_name]';
  $handler->display->display_options['fields']['field_rprofile_last_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_rprofile_last_name']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['field_rprofile_last_name']['alter']['alt'] = 'Click to view researcher profile.';
  /* Field: Profile: Institution */
  $handler->display->display_options['fields']['field_rprofile_partner_ref']['id'] = 'field_rprofile_partner_ref';
  $handler->display->display_options['fields']['field_rprofile_partner_ref']['table'] = 'field_data_field_rprofile_partner_ref';
  $handler->display->display_options['fields']['field_rprofile_partner_ref']['field'] = 'field_rprofile_partner_ref';
  $handler->display->display_options['fields']['field_rprofile_partner_ref']['label'] = 'Partner institution';
  $handler->display->display_options['fields']['field_rprofile_partner_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Profile: Profile Keywords */
  $handler->display->display_options['fields']['field_rprofile_keywords']['id'] = 'field_rprofile_keywords';
  $handler->display->display_options['fields']['field_rprofile_keywords']['table'] = 'field_data_field_rprofile_keywords';
  $handler->display->display_options['fields']['field_rprofile_keywords']['field'] = 'field_rprofile_keywords';
  $handler->display->display_options['fields']['field_rprofile_keywords']['label'] = 'Researcher Keywords';
  $handler->display->display_options['fields']['field_rprofile_keywords']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_rprofile_keywords']['delta_offset'] = '0';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'user';
  $handler->display->display_options['fields']['status']['label'] = 'User Status';
  $handler->display->display_options['fields']['status']['type'] = 'active-blocked';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Profile: User uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'profile';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['fields']['user']['label'] = 'Actions';
  $handler->display->display_options['fields']['user']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['user']['alter']['text'] = '<a href="[oc_base_base_url]/user/[user]/edit?destination=admin/workbench/content/researcher-profiles" title="Click to edit user login preferences and account.">edit user settings</a> | <a href="[oc_base_base_url]/profile-researcher_profile/[user]/edit?destination=admin/workbench/content/researcher-profiles" title="Click to edit the public researcher profile of this user.">edit researcher profile</a>';
  $handler->display->display_options['fields']['user']['alter']['absolute'] = TRUE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'self';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_arguments'] = 'none';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'researcher_profile' => 'researcher_profile',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Profile: Profile Keywords (field_rprofile_keywords) */
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['id'] = 'field_rprofile_keywords_tid';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['table'] = 'field_data_field_rprofile_keywords';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['field'] = 'field_rprofile_keywords_tid';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['expose']['operator_id'] = 'field_rprofile_keywords_tid_op';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['expose']['label'] = 'Researcher Keywords';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['expose']['operator'] = 'field_rprofile_keywords_tid_op';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['expose']['identifier'] = 'field_rprofile_keywords_tid';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['vocabulary'] = 'researcher_profile_type';
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_rprofile_keywords_tid']['error_message'] = FALSE;
  /* Filter criterion: Profile: Institution (field_rprofile_partner_ref) */
  $handler->display->display_options['filters']['field_rprofile_partner_ref_target_id']['id'] = 'field_rprofile_partner_ref_target_id';
  $handler->display->display_options['filters']['field_rprofile_partner_ref_target_id']['table'] = 'field_data_field_rprofile_partner_ref';
  $handler->display->display_options['filters']['field_rprofile_partner_ref_target_id']['field'] = 'field_rprofile_partner_ref_target_id';
  $handler->display->display_options['filters']['field_rprofile_partner_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_rprofile_partner_ref_target_id']['expose']['operator_id'] = 'field_rprofile_partner_ref_target_id_op';
  $handler->display->display_options['filters']['field_rprofile_partner_ref_target_id']['expose']['label'] = 'Institution';
  $handler->display->display_options['filters']['field_rprofile_partner_ref_target_id']['expose']['operator'] = 'field_rprofile_partner_ref_target_id_op';
  $handler->display->display_options['filters']['field_rprofile_partner_ref_target_id']['expose']['identifier'] = 'field_rprofile_partner_ref_target_id';
  $handler->display->display_options['filters']['field_rprofile_partner_ref_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_rprofile_partner_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/workbench/content/researcher-profiles';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Researcher Profiles';
  $handler->display->display_options['menu']['weight'] = '199';
  $handler->display->display_options['menu']['context'] = 0;
  $export['workbench_profile'] = $view;

  return $export;
}
