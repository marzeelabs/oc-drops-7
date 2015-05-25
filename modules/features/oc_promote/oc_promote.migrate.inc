<?php

class OCPromote extends OCMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Import featured content nodes.');

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
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'oc_promote') . '/import/featured.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('featured_content');

    $this->addFieldMapping('title', 'title');

    // Images
    $this->addFieldMapping('field_promoted_media', 'image');
    $this->addFieldMapping('field_promoted_media:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_promoted_media:source_dir')
      ->defaultValue(drupal_get_path('module', 'oc_promote') . '/import/images');

    $this->addFieldMapping('field_promoted_text', 'text')
      ->defaultValue('full_html');

    // $this->addFieldMapping('field_promoted_content', 'link');

    $this->addFieldMapping('uid', 'uid')->defaultValue(1);
    $this->addFieldMapping('is_new', 'is_new')->defaultValue(TRUE);
  }

  function csvcolumns() {
    return array(
      array('title', 'Title'),
      array('image', 'Image'),
      array('text', 'Text'),
      // array('link', 'Link'),
    );
  }
}
