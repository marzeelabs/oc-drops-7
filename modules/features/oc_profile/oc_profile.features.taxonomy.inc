<?php
/**
 * @file
 * oc_profile.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function oc_profile_taxonomy_default_vocabularies() {
  return array(
    'researcher_profile_type' => array(
      'name' => 'Researcher Profile Type',
      'machine_name' => 'researcher_profile_type',
      'description' => 'Will be used to provide to organize the researchers in different listings. E.g. the network partners page will list all researchers that are partners in the project, or the contact page will list researchers that are contact persons for this consortium.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
