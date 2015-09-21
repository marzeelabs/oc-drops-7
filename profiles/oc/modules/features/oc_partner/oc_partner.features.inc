<?php
/**
 * @file
 * oc_partner.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oc_partner_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "snippet" && $api == "default_snippet") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function oc_partner_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function oc_partner_image_default_styles() {
  $styles = array();

  // Exported image style: oc_institution_medium.
  $styles['oc_institution_medium'] = array(
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 180,
          'height' => 100,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      5 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => 'ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 200,
            'height' => 110,
            'xpos' => 'left',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'oc_institution_medium',
  );

  // Exported image style: oc_institution_small.
  $styles['oc_institution_small'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 160,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => -10,
      ),
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 45,
          'upscale' => 0,
        ),
        'weight' => -9,
      ),
    ),
    'label' => 'oc_institution_small',
  );

  // Exported image style: oc_institution_tiny.
  $styles['oc_institution_tiny'] = array(
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 80,
          'height' => 36,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'oc_institution_tiny',
  );

  // Exported image style: oc_thumbnail.
  $styles['oc_thumbnail'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
          'height' => 100,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'oc_thumbnail',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function oc_partner_node_info() {
  $items = array(
    'partner' => array(
      'name' => t('Institution'),
      'base' => 'node_content',
      'description' => t('Use <em>institutions</em> to represent a research center (e.g. the Center for Genomic Regulation in Barcelona, Spain), a university (e.g. the Universidad Politecnica de Catalunya) or a company (e.g. Your Company, LLC). The institution will be linked from various other parts of the site, e.g. from the Researcher or from the Project.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
