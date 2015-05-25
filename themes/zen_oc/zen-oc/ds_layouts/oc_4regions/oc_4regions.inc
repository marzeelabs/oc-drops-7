<?php

/**
 * @file
 * Display Suite OC 4regions configuration.
 */

function ds_oc_4regions() {
  return array(
    'label' => t('OC 4regions'),
    'regions' => array(
      'before' => t('Before'),
      'primary' => t('Primary'),
      'secondary' => t('Secondary'),
      'after' => t('After'),
    ),
    // Uncomment if you want to include a CSS file for this layout (oc_4regions.css)
    // 'css' => TRUE,
    // Uncomment if you want to include a preview for this layout (oc_4regions.png)
    'image' => TRUE,
  );
}
