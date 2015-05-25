<?php

/**
 * @file
 * Contains Batch API callbacks used during installation.
 */

/**
 * BatchAPI callback.
 *
 * @see oc_install_additional_modules()
 */
function _oc_enable_theme($theme, &$context) {
  theme_enable(array($theme));
  variable_set('theme_default', $theme);

  $context['message'] = st('Installed the default theme.');
}

/**
 * BatchAPI callback.
 *
 * @see oc_install_additional_modules()
 */
function _oc_enable_module($module, $module_name, &$context) {
  module_enable(array($module), FALSE);
  $context['message'] = st('Installed %module module.', array('%module' => $module_name));
}

/**
 * BatchAPI callback.
 *
 * @see oc_install_additional_modules()
 */
function _oc_flush_caches($operation, &$context) {
  $context['message'] = t('@operation', array('@operation' => $operation));
  drupal_flush_all_caches();
}

// /**
//  * BatchAPI callback.
//  *
//  * @see oc_import_content()
//  */
// function _oc_taxonomy_menu($operation, &$context) {
//   $context['message'] = t('@operation', array('@operation' => $operation));


//   // Set up taxonomy main menu.
//   $vocabulary_machine_name = variable_get('oc_demo_store', FALSE) ? 'collection' : 'product_category';
//   if ($collection = taxonomy_vocabulary_machine_name_load($vocabulary_machine_name)) {
//     $variable_name = _taxonomy_menu_build_variable('vocab_menu', $collection->vid);
//     variable_set($variable_name, 'main-menu');
//     $variable_name = _taxonomy_menu_build_variable('vocab_parent', $collection->vid);
//     variable_set($variable_name, '0');
//     $variable_name = _taxonomy_menu_build_variable('path', $collection->vid);
//     variable_set($variable_name, 'oc_taxonomy_term_path');
//     $variable_name = _taxonomy_menu_build_variable('rebuild', $collection->vid);
//     variable_set($variable_name, 1);
//   }
// }

/**
 * BatchAPI callback.
 *
 * @see oc_import_content()
 */
// function _oc_import_taxonomy($operation, $type, &$context) {
//   $context['message'] = t('@operation', array('@operation' => $type));
//   // $migration =  Migration::getInstance($operation);
//   // $migration->processImport();


//   $data = array(
//     'researcher_profile_type' => array(
//       'Partner',
//       'Researcher',
//       'Advisory',
//       'Contact',
//     ),
//     'project_type' => array(
//       'PhD (ESR)',
//       'Post-doc (ER)',
//     ),
//   );

//   foreach ($data as $name => $terms) {
//     $vocabulary = taxonomy_vocabulary_machine_name_load($name);

//     foreach ($terms as $term_name) {
//       $term_array = array(
//         'name' => $term_name,
//         'vid' => $vocabulary->vid,
//       );
//       $term = (object) $term_array;
//       taxonomy_term_save($term);
//     }
//   }
// }

/**
 * BatchAPI callback.
 *
 * @see oc_import_content()
 */
// function _oc_example_user($operation, &$context) {
//   $context['message'] = t('@operation', array('@operation' => $operation));

//   // Create a sample user.
//   $user = array(
//     'name' => 'Sample Customer',
//     'mail' => 'customer@example.com',
//     'pass' => 'customer',
//     'status' => 1,
//   );
//   $user = user_save(NULL, $user);

//   // Create a bIlling customer profile.
//   $billing_profile = commerce_customer_profile_new('billing', $user->uid);
//   $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['name_line'] = 'Sample Customer';
//   $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['country'] = 'US';
//   $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['thoroughfare'] = '16 Hampton Ct';
//   $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['locality'] = 'Visalia';
//   $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['administrative_area'] = 'CA';
//   $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['postal_code'] = '93277-8329';
//   commerce_customer_profile_save($billing_profile);
//   commerce_addressbook_set_default_profile($billing_profile);

//   // Create two shipping customer profile samples.
//   $shipping_profile = commerce_customer_profile_new('shipping', $user->uid);
//   $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['name_line'] = 'Sample Customer';
//   $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['country'] = 'US';
//   $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['thoroughfare'] = '2843 Sherman Ave';
//   $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['locality'] = 'Camden';
//   $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['administrative_area'] = 'NJ';
//   $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['postal_code'] = '08105-442';
//   commerce_customer_profile_save($shipping_profile);
//   commerce_addressbook_set_default_profile($shipping_profile);

//   $shipping_profile = commerce_customer_profile_new('shipping', $user->uid);
//   $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['name_line'] = 'Sample Customer';
//   $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['country'] = 'FR';
//   $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['thoroughfare'] = '27 rue des sapins';
//   $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['locality'] = 'Paris';
//   $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['postal_code'] = '75004';
//   commerce_customer_profile_save($shipping_profile);

//   // Create 3 order samples.
//   _oc_create_order($user->uid, 2 , TRUE);
//   _oc_create_order($user->uid, 5);
//   _oc_create_order($user->uid, 3);

// }

/**
 * BatchAPI callback.
 *
 * @see oc_import_content()
 */
function _oc_post_import($operation, &$context) {
  $context['message'] = t('@operation', array('@operation' => $operation));

  // _oc_setup_blocks();
}

// /**
//  * Configures the theme and assign blocks to the appropriate regions.
//  */
// function _oc_setup_blocks() {
//   $admin_theme = 'seven';
//   $default_theme = variable_get('theme_default', 'omega_oc');

//   $blocks = array(
//     array(
//       'module' => 'system',
//       'delta' => 'help',
//       'theme' => $admin_theme,
//       'status' => 1,
//       'weight' => 0,
//       'region' => 'help',
//       'pages' => '',
//       'cache' => DRUPAL_NO_CACHE,
//     ),
//     array(
//       'module' => 'system',
//       'delta' => 'help',
//       'theme' => $default_theme,
//       'status' => 1,
//       'weight' => 0,
//       'region' => 'content',
//       'pages' => '',
//       'cache' => DRUPAL_NO_CACHE,
//     ),
//     array(
//       'module' => 'system',
//       'delta' => 'main',
//       'theme' => $default_theme,
//       'status' => 1,
//       'weight' => 0,
//       'region' => 'content',
//       'pages' => '<front>', // Do not show the block on front.
//       'visibility' => 0,
//       'cache' => DRUPAL_NO_CACHE,
//     ),
//     // Masquerade block
//     array(
//       'module' => 'masquerade',
//       'delta' => 'masquerade',
//       'theme' => $default_theme,
//       'status' => 1,
//       'weight' => 100,
//       'region' => 'closure',
//       'pages' => '',
//       'cache' => DRUPAL_NO_CACHE,
//     ),
//   );

//   drupal_static_reset();
//   _block_rehash($admin_theme);
//   _block_rehash($default_theme);
//   foreach ($blocks as $record) {
//     $module = array_shift($record);
//     $delta = array_shift($record);
//     $theme = array_shift($record);
//     db_update('block')
//       ->fields($record)
//       ->condition('module', $module)
//       ->condition('delta', $delta)
//       ->condition('theme', $theme)
//       ->execute();
//   }
// }

// /**
//  * Configures the Crumbs module and enables the required plugins.
//  */
// function _oc_setup_crumbs() {
//   variable_set('crumbs_show_current_page', TRUE);
//   variable_set('crumbs_weights', oc_crumbs_get_info());
// }

/*
 * Helper function to create a sample order.
 *
 * @param $uid
 * @param $order_state
 * @param $items_number
 */
// function _oc_create_order($uid, $items_number, $is_cart = FALSE) {
//   // Create order as a cart.
//   $order = commerce_order_new($uid, 'cart');
//   commerce_order_save($order);

//   $message = message_create('commerce_order_created', array('uid' => $uid));
//   $wrapper = entity_metadata_wrapper('message', $message);
//   $wrapper->message_commerce_order->set($order);
//   $wrapper->save();

//   // Add products to the cart.
//   $line_items = array();
//   $products = entity_load('commerce_product');
//   $products_key = array_keys($products);
//   $products_number = count($products_key);
//   $count = $products_number < $items_number ? $products_number: $items_number;
//   for($i = 0; $i < $count; $i++) {
//     $product = $products[$products_key[rand(0, $products_number - 1)]];
//     $line_item = commerce_product_line_item_new($product, 1, $order->order_id);
//     commerce_line_item_save($line_item);
//     $line_items[] = array('line_item_id' => $line_item->line_item_id);

//     $message = message_create('commerce_order_cart_add', array('uid' => $uid));
//     $wrapper = entity_metadata_wrapper('message', $message);
//     $wrapper->message_commerce_order->set($order);
//     $wrapper->message_commerce_line_item->set($line_item);
//     $wrapper->save();
//   }
//   $order->commerce_line_items[LANGUAGE_NONE] = $line_items;

//   // Stop here for cart creation.
//   if ($is_cart) {
//     commerce_order_save($order);
//     return;
//   }

//   // Attach customer profile.
//   _oc_update_order_status($order, 'checkout_checkout');
//   $billing_profile_id = commerce_addressbook_get_default_profile_id($uid, 'billing');
//   $shippin_profile_id = commerce_addressbook_get_default_profile_id($uid, 'shipping');
//   if (!empty($billing_profile_id)) {
//     $order->commerce_customer_billing[LANGUAGE_NONE][0]['profile_id'] = $billing_profile_id;
//   }
//   if (!empty($shippin_profile_id)) {
//     $order->commerce_customer_shipping[LANGUAGE_NONE][0]['profile_id'] = $shippin_profile_id;
//   }

//   //@TODO Add shipping service.
//   _oc_update_order_status($order, 'checkout_shipping');

//   // Proceed to payment.
//   _oc_update_order_status($order, 'checkout_review');
//   $order->data['payment_method'] = 'oc_payment|commerce_payment_oc_payment';
//   $order->data['oc_payment'] = array(
//     'credit_card' => array(
//       'type' => 'visa',
//       'number' => '4111111111111111',
//       'exp_month' => '06',
//       'exp_year' => '2012',

//     ),
//   );
//   commerce_order_save($order);
//   $rule = rules_config_load('commerce_payment_oc_payment');
//   $payment_method = commerce_payment_method_load('oc_payment');
//   $method_instance_id = commerce_payment_method_instance_id('oc_payment', $rule);
//   $method_instance = commerce_payment_method_instance_load($method_instance_id);
//   $transaction = oc_payment_transaction($method_instance, $order, $order->commerce_order_total[LANGUAGE_NONE][0], '');

//   $message = message_create('commerce_order_payment_entered', array('uid' => $uid));
//   $wrapper = entity_metadata_wrapper('message', $message);
//   $wrapper->message_commerce_order->set($order);
//   $wrapper->message_commerce_payment->set($transaction);
//   $wrapper->save();

//   _oc_update_order_status($order, 'checkout_payment');
//   _oc_update_order_status($order, 'checkout_complete');
//   _oc_update_order_status($order, 'pending');
// }

/**
 * Helper function to update the order status and set the message.
 *
 * @param $order
 * @param $status
 */
// function _oc_update_order_status($order, $status) {
//   // We need to harcode the previous state, as the entity will not
//   // have this value on run-time.
//   $statuses = commerce_order_statuses();
//   $arguments = array(
//     '@order_status_previous' => $statuses[$order->status]['title'],
//     '@order_status' => $statuses[$status]['title'],
//   );
//   $order = commerce_order_status_update($order, $status);

//   $message = message_create('commerce_order_state', array('uid' => $order->uid, 'arguments' => $arguments));
//   $wrapper = entity_metadata_wrapper('message', $message);
//   $wrapper->message_commerce_order->set($order);
//   $wrapper->save();
// }
