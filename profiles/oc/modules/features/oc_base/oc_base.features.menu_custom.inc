<?php
/**
 * @file
 * oc_base.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function oc_base_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-anonymous-menu.
  $menus['menu-anonymous-menu'] = array(
    'menu_name' => 'menu-anonymous-menu',
    'title' => 'Anonymous Menu',
    'description' => 'The <em>Anonymous</em> menu contains links for anonymous users.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Anonymous Menu');
  t('The <em>Anonymous</em> menu contains links for anonymous users.');


  return $menus;
}
