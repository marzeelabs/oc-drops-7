<?php
/**
 * @file
 * oc_search.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oc_search_user_default_permissions() {
  $permissions = array();

  // Exported permission: access search_api_page.
  $permissions['access search_api_page'] = array(
    'name' => 'access search_api_page',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_page',
  );

  return $permissions;
}
