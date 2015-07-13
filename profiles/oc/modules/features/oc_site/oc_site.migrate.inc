<?php

/**
 * Common features for all the migrations.
 */
abstract class OCMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);
  }

  /**
   * Utility function to map usernames to profile ids for import.
   */
  protected function usersToProfiles(&$current_row, $field, $separator = '|', $profile_type = 'researcher_profile') {
    $usernames = explode($separator, $current_row->{$field});

    $profiles = array();
    if ($usernames) {
      foreach ($usernames as $username) {
        $user = user_load_by_name($username);
        $profile = profile2_load_by_user($user, $profile_type);
        if ($profile) {
          $profiles[] = $profile->pid;
        }
      }
    }

    if ($current_row->{$field} == "" || empty($profiles)) {
      unset($current_row->{$field});
    } else {
      $current_row->{$field} = implode($separator, $profiles);
    }
  }

  protected function processDates(&$current_row, $field) {
    // Add support for date range fields, based on DateExampleMigration
    if (isset($current_row->{$field})) {
      $components = split(':', $current_row->{$field});
      if (count($components) == 2) {
        $data = array(
          'from' => $components[0],
          'to' => $components[1],
        );
        $current_row->{$field} = drupal_json_encode($data);
      }
    }
  }

  protected function processTaxonomyIcons($term_names, $vocabulary, $icons, $fonticon_field, $separator = '|') {
    foreach (explode($separator, $term_names) as $tag) {
      $terms = taxonomy_get_term_by_name($tag, $vocabulary);
      foreach ($terms as $term) {
        if (isset($icons[$tag])) {
          $icon = $icons[$tag];
          $term->{$fonticon_field} = array(
            LANGUAGE_NONE => array(
              0 => array('name' => $icon),
            ),
          );
          taxonomy_term_save($term);
        }
      }
    }
  }
}