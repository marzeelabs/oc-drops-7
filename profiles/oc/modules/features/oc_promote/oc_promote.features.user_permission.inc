<?php
/**
 * @file
 * oc_promote.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oc_promote_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create featured_content content'.
  $permissions['create featured_content content'] = array(
    'name' => 'create featured_content content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any featured_content content'.
  $permissions['delete any featured_content content'] = array(
    'name' => 'delete any featured_content content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own featured_content content'.
  $permissions['delete own featured_content content'] = array(
    'name' => 'delete own featured_content content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any featured_content content'.
  $permissions['edit any featured_content content'] = array(
    'name' => 'edit any featured_content content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own featured_content content'.
  $permissions['edit own featured_content content'] = array(
    'name' => 'edit own featured_content content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
