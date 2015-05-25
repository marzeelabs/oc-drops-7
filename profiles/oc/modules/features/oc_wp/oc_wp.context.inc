<?php
/**
 * @file
 * oc_wp.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function oc_wp_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'work_package_list';
  $context->description = '';
  $context->tag = 'work_package';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'wp' => 'wp',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'views' => array(
      'values' => array(
        'work_packages:page' => 'work_packages:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-work_packages-block_1' => array(
          'module' => 'views',
          'delta' => 'work_packages-block_1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('work_package');
  $export['work_package_list'] = $context;

  return $export;
}
