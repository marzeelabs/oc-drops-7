<?php

class OCProjectsMigration extends OCMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import project nodes.');

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
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'oc_project') . '/import/projects.csv', array(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('project');
    $this->dependencies = array('OCUsers', 'OCProfiles', 'OCPartners');


    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')->defaultValue('full_html');

    $this->addFieldMapping('field_project_goal', 'goal');

    $this->addFieldMapping('field_project_supervisor', 'supervisor')
      ->separator('|');

    $this->addFieldMapping('field_project_host', 'host')
      ->sourceMigration('OCPartners');

    $this->addFieldMapping('field_project_period', 'period');
    $this->addFieldMapping('field_project_type', 'type');

    $this->addFieldMapping('field_project_nrpositions', 'positions');

    $this->addFieldMapping('field_project_contact', 'contact');

    $this->addFieldMapping('status')->defaultValue(1);

    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
  }

  public function prepareRow($current_row) {
    $this->usersToProfiles($current_row, 'supervisor');
    $this->processDates($current_row, 'period');
  }

}
