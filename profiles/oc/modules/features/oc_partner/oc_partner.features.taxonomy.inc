<?php
/**
 * @file
 * oc_partner.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function oc_partner_taxonomy_default_vocabularies() {
  return array(
    'partner_type' => array(
      'name' => 'Partner Type',
      'machine_name' => 'partner_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
