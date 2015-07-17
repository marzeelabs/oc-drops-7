<?php

/**
 * Implements hook_views_data_().
 */
function oc_base_views_data() {
  $data = array();

  $data['views']['oc_base_base_url'] = array(
    'title' => t('Base URL'),
    'help' => t("Provide a link to the site's base URL."),
    'field' => array(
      'handler' => 'oc_base_handler_field_base_url',
    ),
  );

  return $data;
}
