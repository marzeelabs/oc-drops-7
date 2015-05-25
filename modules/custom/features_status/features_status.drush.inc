<?php

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function features_status_drush_command() {
  $items = array();

  $items['features-state'] = array(
    'description' => "List all the available features in a particular status for your site.",
    'options' => array(
      'diff' => 'If true, print a full diff of the unclean features'
    ),
    'aliases' => array('fs'),
  );

  return $items;
}

/**
 * Get a list of the dirty features states.
 */
function drush_features_status_features_state() {
  module_load_include('inc', 'features', 'features.export');

  // Sort the Features list before compiling the output.
  $features = features_get_features(NULL, TRUE);
  ksort($features);

  $needs_review = array();
  $overridden = array();

  foreach ($features as $k => $m) {
    if ($m->status == 1) {
      switch (features_get_storage($m->name)) {
        case FEATURES_DEFAULT:
        case FEATURES_REBUILDABLE:
          break;
        case FEATURES_OVERRIDDEN:
          $overriden[] = $m->name;
          break;
        case FEATURES_NEEDS_REVIEW:
          $needs_review[] = $m->name;
          break;
      }
    }
  }

  if (!empty($needs_review)) {
    drush_print("Features in NEEDS-REVIEW: " . implode(', ', $needs_review));
  }

  if (!empty($overriden)) {
    drush_print("Features in OVERRIDDEN: " . implode(', ', $overriden));
  }

  // Print a diff log of all the unclean features if requested
  if (drush_get_option('diff', FALSE)) {
    drush_unset_option('diff');
    $all = array_merge($needs_review, $overriden);
    foreach ($all as $module) {
      drush_print("******** FEATURE: " . $module . ' ********');
      drush_invoke('fd', array($module));
    }
  }
}
