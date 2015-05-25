<?php
/**
 * @file
 * oc_map.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function oc_map_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'oc_partner_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'oc_partner_map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Institutions on the map';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_partner_location' => 'field_partner_location',
    'field_partner_address' => 'field_partner_address',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_partner_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_partner_address' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_partner_location']['id'] = 'field_partner_location';
  $handler->display->display_options['fields']['field_partner_location']['table'] = 'field_data_field_partner_location';
  $handler->display->display_options['fields']['field_partner_location']['field'] = 'field_partner_location';
  $handler->display->display_options['fields']['field_partner_location']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_partner_location']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_partner_location']['group_column'] = 'wkt';
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_partner_address']['id'] = 'field_partner_address';
  $handler->display->display_options['fields']['field_partner_address']['table'] = 'field_data_field_partner_address';
  $handler->display->display_options['fields']['field_partner_address']['field'] = 'field_partner_address';
  $handler->display->display_options['fields']['field_partner_address']['label'] = '';
  $handler->display->display_options['fields']['field_partner_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_partner_address']['type'] = 'locality';
  $handler->display->display_options['fields']['field_partner_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_partner_address']['group_column'] = 'country';
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_partner_address_1']['id'] = 'field_partner_address_1';
  $handler->display->display_options['fields']['field_partner_address_1']['table'] = 'field_data_field_partner_address';
  $handler->display->display_options['fields']['field_partner_address_1']['field'] = 'field_partner_address';
  $handler->display->display_options['fields']['field_partner_address_1']['label'] = '';
  $handler->display->display_options['fields']['field_partner_address_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_address_1']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_partner_address_1']['type'] = 'country';
  $handler->display->display_options['fields']['field_partner_address_1']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Summary';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<b>[title]</b><br/>
Partner: [field_rprofile_last_name]<br/>
at <i>[field_partner_address], [field_partner_address_1]</i>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'partner' => 'partner',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['data_source'] = 'field_partner_location';
  $handler->display->display_options['style_options']['name_field'] = 'title';
  $handler->display->display_options['style_options']['description_field'] = 'nothing';
  $handler->display->display_options['style_options']['view_mode'] = 'map';
  $handler->display->display_options['style_options']['map'] = 'oc_map-multiple-markers';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['data_source'] = 'field_partner_location';
  $handler->display->display_options['style_options']['name_field'] = 'title';
  $handler->display->display_options['style_options']['description_field'] = '#rendered_entity';
  $handler->display->display_options['style_options']['view_mode'] = 'teaser';
  $handler->display->display_options['style_options']['map'] = 'oc_map-multiple-markers';
  $handler->display->display_options['style_options']['height'] = '500';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'institutions/map';
  $export['oc_partner_map'] = $view;

  $view = new view();
  $view->name = 'oc_profile_map';
  $view->description = 'A map of researchers';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'OC Profile Map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Map';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['data_source'] = 'field_rprofile_location';
  $handler->display->display_options['style_options']['name_field'] = 'pid';
  $handler->display->display_options['style_options']['description_field'] = '#rendered_entity';
  $handler->display->display_options['style_options']['view_mode'] = 'teaser';
  $handler->display->display_options['style_options']['map'] = 'oc_map-multiple-markers';
  $handler->display->display_options['style_options']['height'] = '600';
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
  /* Field: Profile: Location */
  $handler->display->display_options['fields']['field_rprofile_location']['id'] = 'field_rprofile_location';
  $handler->display->display_options['fields']['field_rprofile_location']['table'] = 'field_data_field_rprofile_location';
  $handler->display->display_options['fields']['field_rprofile_location']['field'] = 'field_rprofile_location';
  $handler->display->display_options['fields']['field_rprofile_location']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_rprofile_location']['settings'] = array(
    'data' => 'full',
  );
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'field_rprofile_keywords_tid';
  $handler->display->display_options['arguments']['name']['default_action'] = 'default';
  $handler->display->display_options['arguments']['name']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['name']['title'] = 'Map: %1';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['name']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['name']['validate_options']['type'] = 'name';
  $handler->display->display_options['arguments']['name']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'researcher_profile' => 'researcher_profile',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'network/%/map';
  $handler->display->display_options['menu']['title'] = 'Map';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $export['oc_profile_map'] = $view;

  return $export;
}
