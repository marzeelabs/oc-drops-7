<?php

class OCWorkPackagesMigration extends OCMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import work package nodes.');

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
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'oc_wp') . '/import/work_packages.csv', array(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('wp');
    $this->dependencies = array('OCUsers', 'OCProfiles', 'OCPartners', 'OCProjects');


    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')->defaultValue('full_html');

    $this->addFieldMapping('field_wp_projects', 'projects')
      ->separator('|')
      ->sourceMigration('OCProjects');

    $this->addFieldMapping('field_wp_institution', 'institution')
      ->sourceMigration('OCPartners');

    $this->addFieldMapping('field_wp_profile', 'leading_partners')
      ->separator('|');

    $this->addFieldMapping('field_wp_profilecontrib', 'contributing_partners')
      ->separator('|');

    $this->addFieldMapping('status')->defaultValue(1);

    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
  }

  public function prepareRow($current_row) {
    $this->usersToProfiles($current_row, 'leading_partners');
    $this->usersToProfiles($current_row, 'contributing_partners');
  }

}
