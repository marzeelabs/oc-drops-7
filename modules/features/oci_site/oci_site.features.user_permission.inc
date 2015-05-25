<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function oci_site_user_default_permissions() {
  $permissions = array();

  // Exported permission: create folder content
  $permissions['create folder content'] = array(
    'name' => 'create folder content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
    ),
  );

  // Exported permission: delete any folder content
  $permissions['delete any folder content'] = array(
    'name' => 'delete any folder content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'manager',
    ),
  );

  // Exported permission: delete own folder content
  $permissions['delete own folder content'] = array(
    'name' => 'delete own folder content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'manager',
    ),
  );

  // Exported permission: edit any folder content
  $permissions['edit any folder content'] = array(
    'name' => 'edit any folder content',
    'roles' => array(),
  );

  // Exported permission: edit own folder content
  $permissions['edit own folder content'] = array(
    'name' => 'edit own folder content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'manager',
    ),
  );

  return $permissions;
}
