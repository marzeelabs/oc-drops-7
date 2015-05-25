<?php
/**
 * @file
 * oc_pages.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function oc_pages_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'page';
  $context->description = '';
  $context->tag = 'page';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'page' => 'page',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-pages_blocks-block' => array(
          'module' => 'views',
          'delta' => 'pages_blocks-block',
          'region' => 'sidebar_first',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('page');
  $export['page'] = $context;

  return $export;
}
