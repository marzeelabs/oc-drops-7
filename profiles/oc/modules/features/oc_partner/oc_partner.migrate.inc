<?php

class OCPartners extends OCMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import partner nodes.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'oc_partner') . '/import/partners.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('partner');

    // Default fields
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')
      ->defaultValue('full_html');

    $this->addFieldMapping('field_partner_url', 'url');

    // Address
    $this->addFieldMapping('field_partner_address', 'country');
    $this->addFieldMapping('field_partner_address:thoroughfare', 'address');
    $this->addFieldMapping('field_partner_address:locality', 'city');
    $this->addFieldMapping('field_partner_address:postal_code', 'postal_code');

    // Images
    $this->addFieldMapping('field_partner_logo', 'image');
    $this->addFieldMapping('field_partner_logo:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_partner_logo:source_dir')
      ->defaultValue(drupal_get_path('module', 'oc_partner') . '/import/images');

    $this->addFieldMapping('status')->defaultValue(1);

    $this->addFieldMapping('uid', 'uid')->defaultValue(1);
    $this->addFieldMapping('is_new', 'is_new')->defaultValue(TRUE);
  }

  function csvcolumns() {
    return array(
      array('title', 'Title'),
      array('url', 'Website'),
      array('country', 'Country'),
      array('city', 'City'),
      array('address', 'Address'),
      array('postal_code', 'Postal Code'),
      array('image', 'Image'),
      array('body', 'Body'),
    );
  }
}
