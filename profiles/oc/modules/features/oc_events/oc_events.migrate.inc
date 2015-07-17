<?php

class OCEvents extends OCMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import event nodes.');

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
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'oc_events') . '/import/events.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('event');

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')
      ->defaultValue('full_html');

    $this->addFieldMapping('field_event_date', 'date')
      ->separator('|');

    $this->addFieldMapping('field_event_tags', 'tags')
      ->separator('|');
    $this->addFieldMapping('field_event_tags:create_term')
      ->defaultValue(TRUE);

    // Address
    $this->addFieldMapping('field_event_address', 'country');
    $this->addFieldMapping('field_event_address:thoroughfare', 'address');
    $this->addFieldMapping('field_event_address:locality', 'city');
    $this->addFieldMapping('field_event_address:postal_code', 'postal_code');

    // Images
    $this->addFieldMapping('field_event_imageteaser', 'image_teaser');
    $this->addFieldMapping('field_event_imageteaser:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_event_imageteaser:source_dir')
      ->defaultValue(drupal_get_path('module', 'oc_events') . '/import/images');

    $this->addFieldMapping('field_event_images', 'images')
      ->separator('|');
    $this->addFieldMapping('field_event_images:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_event_images:source_dir')
      ->defaultValue(drupal_get_path('module', 'oc_events') . '/import/images');

    // Files
    $this->addFieldMapping('field_event_files', 'files')
      ->separator('|');
    $this->addFieldMapping('field_event_files:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_event_files:source_dir')
      ->defaultValue(drupal_get_path('module', 'oc_events') . '/import/files');

    $this->addFieldMapping('status')->defaultValue(1);

    $this->addFieldMapping('uid', 'uid')->defaultValue(1);
    $this->addFieldMapping('is_new', 'is_new')->defaultValue(TRUE);
  }

  function csvcolumns() {
    return array(
      array('title', 'Title'),
      array('date', 'Date'),
      array('country', 'Country'),
      array('city', 'City'),
      array('address', 'Address'),
      array('postal_code', 'Postal Code'),
      array('body', 'Body'),
      array('tags', 'Tags'),
      array('image_teaser', 'Image Teaser'),
      array('images', 'Images'),
      array('files', 'Files'),
    );
  }

  public function prepareRow($current_row) {
    // Add support for date range fields, based on DateExampleMigration
    if (isset($current_row->date)) {
      $components = split(':', $current_row->date);
      if (count($components) == 2) {
        $data = array(
          'from' => $components[0],
          'to' => $components[1],
        );
        $current_row->date = drupal_json_encode($data);
      }
    }
  }

  public function complete($entity, $row) {
    $icons = array(
      'Conference' => 'location',
      'Workshop' => 'workshop',
      'Meeting' => 'chat',
    );

    $this->processTaxonomyIcons($row->tags, 'tags', $icons, 'field_tags_fonticon');
  }
}
