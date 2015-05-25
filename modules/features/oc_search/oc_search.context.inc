<?php
/**
 * @file
 * oc_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function oc_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'oc_search';
  $context->description = 'Search';
  $context->tag = 'search';
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
        'search_api_page-oc_search' => array(
          'module' => 'search_api_page',
          'delta' => 'oc_search',
          'region' => 'menu_secondary',
          'weight' => '-35',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search');
  t('search');
  $export['oc_search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'oc_search_page';
  $context->description = '';
  $context->tag = 'search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search' => 'search',
        'search/*' => 'search/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-standard' => array(
          'module' => 'current_search',
          'delta' => 'standard',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-zIH8EsYFkvWKeMtTZTGLEm1GrYlAarmk' => array(
          'module' => 'facetapi',
          'delta' => 'zIH8EsYFkvWKeMtTZTGLEm1GrYlAarmk',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-006i2ydH3VyJuB1m9c18xr81tXcAwDVN' => array(
          'module' => 'facetapi',
          'delta' => '006i2ydH3VyJuB1m9c18xr81tXcAwDVN',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('search');
  $export['oc_search_page'] = $context;

  return $export;
}
