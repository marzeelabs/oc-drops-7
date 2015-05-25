<?php
/**
 * @file
 * oc_events.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function oc_events_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_archive';
  $context->description = '';
  $context->tag = 'event';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'events:page_1' => 'events:page_1',
        'events:page_4' => 'events:page_4',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-events-block_3' => array(
          'module' => 'views',
          'delta' => 'events-block_3',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('event');
  $export['events_archive'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_list';
  $context->description = '';
  $context->tag = 'event';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'events:page_4' => 'events:page_4',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-events-block_1' => array(
          'module' => 'views',
          'delta' => 'events-block_1',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('event');
  $export['events_list'] = $context;

  return $export;
}
