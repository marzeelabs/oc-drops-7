<?php
/**
 * @file
 * oc_profile.default_snippet.inc
 */

/**
 * Implements hook_default_snippet().
 */
function oc_profile_default_snippet() {
  $export = array();

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Profiles pages - footer';
  $snippet->name = 'profiles_pages_footer';
  $snippet->title = '';
  $export['profiles_pages_footer'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Profiles pages - header';
  $snippet->name = 'profiles_pages_header';
  $snippet->title = '';
  $export['profiles_pages_header'] = $snippet;

  return $export;
}
