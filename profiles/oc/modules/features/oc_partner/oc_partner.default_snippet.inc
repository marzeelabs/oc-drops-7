<?php
/**
 * @file
 * oc_partner.default_snippet.inc
 */

/**
 * Implements hook_default_snippet().
 */
function oc_partner_default_snippet() {
  $export = array();

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Institutions page - footer';
  $snippet->name = 'institutions_page_footer';
  $snippet->title = '';
  $export['institutions_page_footer'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Institutions page - header';
  $snippet->name = 'institutions_page_header';
  $snippet->title = '';
  $export['institutions_page_header'] = $snippet;

  return $export;
}
