<?php
/**
 * @file
 * oc_partner.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function oc_partner_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'partner_list';
  $context->description = '';
  $context->tag = 'partner';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'institutions_list:page' => 'institutions_list:page',
        'oc_partner_map:page_1' => 'oc_partner_map:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'oc_partner-list-map-toggle' => array(
          'module' => 'oc_partner',
          'delta' => 'list-map-toggle',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('partner');
  $export['partner_list'] = $context;

  return $export;
}
