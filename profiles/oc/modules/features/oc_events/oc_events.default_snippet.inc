<?php
/**
 * @file
 * oc_events.default_snippet.inc
 */

/**
 * Implements hook_default_snippet().
 */
function oc_events_default_snippet() {
  $export = array();

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Events block - footer';
  $snippet->name = 'events_block_footer';
  $snippet->title = '';
  $export['events_block_footer'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Events block - header';
  $snippet->name = 'events_block_header';
  $snippet->title = '';
  $export['events_block_header'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Events page - footer';
  $snippet->name = 'events_page_footer';
  $snippet->title = '';
  $export['events_page_footer'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Events page - header';
  $snippet->name = 'events_page_header';
  $snippet->title = '';
  $export['events_page_header'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Past Events block - footer';
  $snippet->name = 'past_events_block_footer';
  $snippet->title = '';
  $export['past_events_block_footer'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Past Events block - header';
  $snippet->name = 'past_events_block_header';
  $snippet->title = '';
  $export['past_events_block_header'] = $snippet;

  return $export;
}
