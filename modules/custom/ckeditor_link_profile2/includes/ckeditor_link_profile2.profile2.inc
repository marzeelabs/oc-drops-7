<?php

// @todo make this somehow configurable, this is now very tied into our OC work
define('CKEDITOR_LINK_PROFILE2_TYPE', 'researcher_profile');
define('CKEDITOR_LINK_PROFILE2_BASE', 'profile-researcher_profile');

/**
 * Implementation of hook_ckeditor_link_TYPE_autocomplete().
 */
function ckeditor_link_profile2_ckeditor_link_profile2_autocomplete($string) {
  $matches = array();

  $result = db_select('users')
    ->fields('users', array('uid', 'name'))
    ->condition('name', '%'. db_like($string) .'%', 'LIKE')
    ->range(0, 10)
    // ->addTag('user_access'); // Make a proper access hook
    ->execute();

  foreach ($result as $user) {
    $profile = profile2_load_by_user($user->uid, CKEDITOR_LINK_PROFILE2_TYPE);
    if ($profile) {
      $matches[CKEDITOR_LINK_PROFILE2_BASE . '/'. $user->uid] = $profile->label();
    }
  }

  return $matches;
}

/**
 * Implementation of hook_ckeditor_link_TYPE_url().
 */
function ckeditor_link_profile2_ckeditor_link_profile2_url($path, $langcode) {
  if (!preg_match('`^' . CKEDITOR_LINK_PROFILE2_BASE . '/(\d+)$`', $path, $matches)) {
    return;
  }

  $uid = $matches[1];

  return ckeditor_link_url(CKEDITOR_LINK_PROFILE2_BASE . "/" . $uid, $langcode);
}
