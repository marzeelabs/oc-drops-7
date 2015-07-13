<?php
/**
 * @file
 * oc_pages.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function oc_pages_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_imageblock_caption'
  $field_bases['field_imageblock_caption'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_imageblock_caption',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_imageblock_image'
  $field_bases['field_imageblock_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_imageblock_image',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'profile2_private' => FALSE,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_page_blocks'
  $field_bases['field_page_blocks'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_page_blocks',
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'profile2_private' => FALSE,
      'referenceable_modules' => array(
        'bean' => 'bean',
        'block' => 0,
        'calendar' => 0,
        'comment' => 0,
        'context_ui' => 0,
        'current_search' => 0,
        'devel' => 0,
        'diff' => 0,
        'facetapi' => 0,
        'logintoboggan' => 0,
        'masquerade' => 0,
        'menu' => 0,
        'menu_block' => 0,
        'node' => 0,
        'oc_promote' => 0,
        'oc_base' => 0,
        'search_api_page' => 0,
        'system' => 0,
        'user' => 0,
        'views' => 0,
        'webform' => 0,
        'workbench' => 0,
      ),
      'referenceable_operator' => 'AND',
      'referenceable_regions' => array(
        '' => '',
        'branding' => 0,
        'closure' => 0,
        'content' => 0,
        'footer_first' => 0,
        'footer_second' => 0,
        'footer_third' => 0,
        'header_menu' => 0,
        'menu' => 0,
        'page_bottom' => 0,
        'page_top' => 0,
        'postscript_first' => 0,
        'postscript_second' => 0,
        'postscript_third' => 0,
        'sidebar_first' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 1,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  return $field_bases;
}
