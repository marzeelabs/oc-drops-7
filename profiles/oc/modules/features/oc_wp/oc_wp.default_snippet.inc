<?php
/**
 * @file
 * oc_wp.default_snippet.inc
 */

/**
 * Implements hook_default_snippet().
 */
function oc_wp_default_snippet() {
  $export = array();

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Work Packages page - footer';
  $snippet->name = 'work_packages_page_footer';
  $snippet->title = '';
  $export['work_packages_page_footer'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Work Packages page - header';
  $snippet->name = 'work_packages_page_header';
  $snippet->title = '';
  $export['work_packages_page_header'] = $snippet;

  return $export;
}
