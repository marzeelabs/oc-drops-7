<?php
/**
 * @file
 * oc_project.default_snippet.inc
 */

/**
 * Implements hook_default_snippet().
 */
function oc_project_default_snippet() {
  $export = array();

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Jobs page - footer';
  $snippet->name = 'jobs_page_footer';
  $snippet->title = '';
  $export['jobs_page_footer'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Jobs page - header';
  $snippet->name = 'jobs_page_header';
  $snippet->title = '';
  $export['jobs_page_header'] = $snippet;

  return $export;
}
