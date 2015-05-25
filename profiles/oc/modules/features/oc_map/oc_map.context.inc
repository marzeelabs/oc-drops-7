<?php
/**
 * @file
 * oc_map.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function oc_map_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'oc_partner_map';
  $context->description = '';
  $context->tag = 'map';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'oc_profile_partners:page' => 'oc_profile_partners:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-oc_partner_map-block_1' => array(
          'module' => 'views',
          'delta' => 'oc_partner_map-block_1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('map');
  $export['oc_partner_map'] = $context;

  return $export;
}
