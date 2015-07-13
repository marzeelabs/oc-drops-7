<?php

/**
 * Copied settings from systems form, for easy changing.
 * Added a couple of site-wide settings.
 */
function oc_base_settings_form() {

  $form['site_information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Site details'),
  );
  $form['site_information']['site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Site name'),
    '#default_value' => variable_get('site_name', 'Open Consortium'),
    '#required' => TRUE
  );
  $form['site_information']['site_slogan'] = array(
    '#type' => 'textarea',
    '#rows' => 3,
    '#title' => t('Slogan'),
    '#default_value' => variable_get('site_slogan', ''),
    '#description' => t("Will appear in Google, etc."),
  );
  $form['site_information']['oc_base_slogan'] = array(
    '#type' => 'textarea',
    '#rows' => 3,
    '#title' => t('Slogan (header)'),
    '#default_value' => variable_get('oc_base_slogan', variable_get('site_slogan', '')),
    '#description' => t("Will appear on the home page"),
  );
  $form['site_information']['oc_base_mission'] = array(
    '#type' => 'textarea',
    '#rows' => 3,
    '#title' => t('Mission (header)'),
    '#default_value' => variable_get('oc_base_mission', ''),
    '#description' => t("Will often appear on the home page below the slogan"),
  );
  $form['site_information']['site_mail'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail address'),
    '#default_value' => variable_get('site_mail', ini_get('sendmail_from')),
    '#description' => t("The <em>From</em> address in automated e-mails sent during registration and new password requests, and other notifications. (Use an address ending in your site's domain to help prevent this e-mail being flagged as spam.)"),
    '#required' => TRUE,
  );
  $form['site_information']['oc_base_address'] = array(
    '#type' => 'textarea',
    '#rows' => 3,
    '#title' => t('Postal address'),
    '#default_value' => variable_get('oc_base_address', ''),
    '#description' => t("Will usually appear in the footer."),
  );
  $form['site_information']['oc_base_attribution'] = array(
    '#type' => 'textarea',
    '#rows' => 1,
    '#title' => t('Attribution'),
    '#default_value' => variable_get('oc_base_attribution', ''),
    '#description' => t("Will usually appear in the footer. <br/>For example: \"MYPROJECT is a project in the 'Marie Curie Initial Training Networks Theme' of the European Commission's Seventh Framework Programme.\""),
  );


  foreach (oc_base_logos() as $logo => $logo_data) {
    $logos_options[$logo] = $logo_data['title'];
  }

  $form['site_information']['oc_base_logos'] = array(
    '#type' => 'checkboxes',
    '#options' => $logos_options,
    '#title' => t('Logos to be used in the footer'),
    '#default_value' => variable_get('oc_base_logos', drupal_map_assoc(array('europe', 'fp7'))),
    '#description' => t("Check the logos that need to appear in the footer. If you need more logos, please let us know."),
  );

  $system_form = system_settings_form($form);
  return $system_form;
}
