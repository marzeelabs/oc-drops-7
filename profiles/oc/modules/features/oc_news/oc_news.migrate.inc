<?php

class OCNews extends OCMigration {

  static private $taxonomy_icons = array(
    'Publication' => 'publication',
    'Award' => 'flag',
    'Europe' => 'world',
  );

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import news nodes.');

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
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'oc_news') . '/import/news.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('article');

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')
      ->defaultValue('full_html');

    $this->addFieldMapping('field_article_date', 'date');

    $this->addFieldMapping('field_article_tags', 'tags')
      ->separator('|');
    $this->addFieldMapping('field_article_tags:create_term')
      ->defaultValue(TRUE);

    // Images
    $this->addFieldMapping('field_article_image_teaser', 'image_teaser');
    $this->addFieldMapping('field_article_image_teaser:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_article_image_teaser:source_dir')
      ->defaultValue(drupal_get_path('module', 'oc_news') . '/import/images');

    $this->addFieldMapping('field_article_images', 'images')
      ->separator('|');
    $this->addFieldMapping('field_article_images:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_article_images:source_dir')
      ->defaultValue(drupal_get_path('module', 'oc_news') . '/import/images');

    // Files
    $this->addFieldMapping('field_article_files', 'files')
      ->separator('|');
    $this->addFieldMapping('field_article_files:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_article_files:source_dir')
      ->defaultValue(drupal_get_path('module', 'oc_news') . '/import/files');

    $this->addFieldMapping('uid', 'uid')->defaultValue(1);
    $this->addFieldMapping('is_new', 'is_new')->defaultValue(TRUE);
    $this->addFieldMapping('workbench_moderation_state_new', 'workbench_moderation_state_new')->defaultValue('published');
  }

  function csvcolumns() {
    return array(
      array('title', 'Title'),
      array('date', 'Date'),
      array('body', 'Body'),
      array('tags', 'Tags'),
      array('image_teaser', 'Image Teaser'),
      array('images', 'Images'),
      array('files', 'Files'),
    );
  }

  public function complete($entity, $row) {
    $icons = array(
      'Publication' => 'publication',
      'Award' => 'flag',
      'Europe' => 'world',
    );

    $this->processTaxonomyIcons($row->tags, 'tags', $icons, 'field_tags_fonticon');
  }
}
