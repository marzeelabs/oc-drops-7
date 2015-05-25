<?php
/**
 * @file
 * oc_wp.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oc_wp_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create wp content'.
  $permissions['create wp content'] = array(
    'name' => 'create wp content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any wp content'.
  $permissions['delete any wp content'] = array(
    'name' => 'delete any wp content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own wp content'.
  $permissions['delete own wp content'] = array(
    'name' => 'delete own wp content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any wp content'.
  $permissions['edit any wp content'] = array(
    'name' => 'edit any wp content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own wp content'.
  $permissions['edit own wp content'] = array(
    'name' => 'edit own wp content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
