<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function oci_site_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'oci_site';
  $context->description = '';
  $context->tag = 'oci_site';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'masquerade-0' => array(
          'module' => 'masquerade',
          'delta' => 0,
          'region' => 'content',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('oci_site');
  $export['oci_site'] = $context;

  return $export;
}
