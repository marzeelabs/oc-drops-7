<?php

/**
 * Implements hook_field_info().
 *
 * Provides the description of the field.
 */
function fonticon_field_info() {
  return array(
    // We name our field as the associative name of the array.
    'fonticon_field' => array(
      'label' => t('Font Icon'),
      'description' => t('Stores a font icon.'),
      'default_widget' => 'fonticon_select',
      'default_formatter' => 'fonticon_icon',
    ),
  );
}

/**
 * Implements hook_field_validate().
 */
function fonticon_field_validate($entity_type, $entity, $field, $instance, $langcode, $items, &$errors) {
}

/**
 * Implements hook_field_is_empty().
 */
function fonticon_field_is_empty($item, $field) {
  return empty($item['name']);
}

/**
 * Implements hook_field_formatter_info().
 */
function fonticon_field_formatter_info() {
  return array(
    'fonticon_icon' => array(
      'label' => t('Fonticon formatter'),
      'field types' => array('fonticon_field'),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function fonticon_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  switch ($display['type']) {
    case 'fonticon_field':
      foreach ($items as $delta => $item) {
        $element[$delta] = array(
          '#type' => 'fonticon_icon',
          '#icon' => $item['value'],
        );
      }
      break;
  }

  return $element;
}

/**
 * Implements hook_field_widget_info().
 */
function fonticon_field_widget_info() {
  return array(
    'fonticon_select' => array(
      'label' => t('Select list'),
      'field types' => array('fonticon_field'),
    ),
  );
}

/**
 * Implements hook_field_widget_form().
 */
function fonticon_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $value = isset($items[$delta]['name']) ? $items[$delta]['name'] : '';

  $widget = $element;
  $widget['#delta'] = $delta;

  $options[''] = t('- None -');
  $options += drupal_map_assoc(array_keys(fonticon_list()));

  switch ($instance['widget']['type']) {

    case 'fonticon_select':
      $widget = array(
        '#type' => 'select',
        '#title' => t('Icon'),
        '#description' => t('The actual icon displayed depends on the theme that will be used. !link', array('!link' => l(t('View the list of icons for your current theme.'), 'help/fonticon', array('attributes' => array('target' => '_blank'))))),
        '#options' => $options,
        '#default_value' => $value,
      );
      break;

  }

  $element['name'] = $widget;
  return $element;
}
