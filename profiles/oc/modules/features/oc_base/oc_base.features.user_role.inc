<?php
/**
 * @file
 * oc_base.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function oc_base_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 3,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 2,
  );

  return $roles;
}
