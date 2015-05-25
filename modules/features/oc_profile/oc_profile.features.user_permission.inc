<?php
/**
 * @file
 * oc_profile.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oc_profile_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer profile types'.
  $permissions['administer profile types'] = array(
    'name' => 'administer profile types',
    'roles' => array(),
    'module' => 'profile2',
  );

  // Exported permission: 'administer profiles'.
  $permissions['administer profiles'] = array(
    'name' => 'administer profiles',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'edit any researcher_profile profile'.
  $permissions['edit any researcher_profile profile'] = array(
    'name' => 'edit any researcher_profile profile',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'edit own researcher_profile profile'.
  $permissions['edit own researcher_profile profile'] = array(
    'name' => 'edit own researcher_profile profile',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view any researcher_profile profile'.
  $permissions['view any researcher_profile profile'] = array(
    'name' => 'view any researcher_profile profile',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view own researcher_profile profile'.
  $permissions['view own researcher_profile profile'] = array(
    'name' => 'view own researcher_profile profile',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'profile2',
  );

  return $permissions;
}
