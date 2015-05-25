<?php
/**
 * @file
 * oc_profile.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function oc_profile_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'oc_profile_contact';
  $context->description = '';
  $context->tag = 'profile';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'contact' => 'contact',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-oc_profile_partners-block_1' => array(
          'module' => 'views',
          'delta' => 'oc_profile_partners-block_1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('profile');
  $export['oc_profile_contact'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'oc_profile_list';
  $context->description = '';
  $context->tag = 'profile';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'oc_profile_list:page' => 'oc_profile_list:page',
        'oc_profile_map:page' => 'oc_profile_map:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'oc_profile-list-map-toggle' => array(
          'module' => 'oc_profile',
          'delta' => 'list-map-toggle',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('profile');
  $export['oc_profile_list'] = $context;

  return $export;
}
