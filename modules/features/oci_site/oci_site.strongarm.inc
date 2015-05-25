<?php

/**
 * Implementation of hook_strongarm().
 */
function oci_site_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_footer';
  $strongarm->value = 'Powered by <a href="http://openconsortium.eu" target="_blank">Open Consortium</a>.';
  $export['site_footer'] = $strongarm;

  return $export;
}
