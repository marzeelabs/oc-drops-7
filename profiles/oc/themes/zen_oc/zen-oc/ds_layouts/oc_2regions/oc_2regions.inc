<?php

/**
 * @file
 * Display Suite OC 2regions configuration.
 */

function ds_oc_2regions() {
  return array(
    'label' => t('OC 2regions'),
    'regions' => array(
      'primary' => t('Primary'),
      'secondary' => t('Secondary'),
    ),
    // Uncomment if you want to include a CSS file for this layout (oc_2regions.css)
    // 'css' => TRUE,
    // Uncomment if you want to include a preview for this layout (oc_2regions.png)
    'image' => TRUE,
  );
}
