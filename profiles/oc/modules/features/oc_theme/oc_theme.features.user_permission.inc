<?php
/**
 * @file
 * oc_theme.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oc_theme_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'system',
  );

  return $permissions;
}
