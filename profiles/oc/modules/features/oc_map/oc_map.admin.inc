<?php

/**
 * Copied settings from systems form, for easy changing.
 * Added a couple of site-wide settings.
 */
function oc_map_settings_form() {
  $form['oc_map_layer'] = array(
    '#type' => 'textfield',
    '#size' => 100,
    '#title' => t('Custom map layer'),
    '#description' => t('The map layer that will be used for all maps. This can be something like <em>http://{s}.tiles.mapbox.com/v3/marzeelabs.map-hr93fuy4/{z}/{x}/{y}.png</em> or <em>http://{s}.tile.stamen.com/toner/{z}/{x}/{y}.png</em>'),
    '#default_value' => variable_get('oc_map_layer', OC_MAP_DEFAULT_LAYER),
  );

  $system_form = system_settings_form($form);

  $system_form['#validate'][] = 'oc_map_settings_form_validate';
  $system_form['#submit'][] = 'oc_map_settings_form_submit';

  return $system_form;
}

/**
 * Validation handler.
 */
function oc_map_settings_form_validate($form, &$form_state) {
  // @todo validate whether these are correct URL's
}

/**
 * Submit handler.
 */
function oc_map_settings_form_submit($form, &$form_state) {
  // Clear the leaflet caches
  cache_clear_all('leaflet_map_info', 'cache');
}


