<?php

class OCUsersMigration extends OCMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import users.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'mail' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationUser::getKeySchema()
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'oc_profile') . '/import/profiles.csv', array(), array(
      'header_rows' => 1,
    ));
    $this->destination = new MigrateDestinationUser();

    // Default fields
    $this->addSimpleMappings(array('name', 'mail', 'status'));

    $this->addFieldMapping('pass', 'name');
  }
}

// class OCProfileTypeTermMigration extends Migration {
//   public function __construct() {
//     parent::__construct();
//     $this->description = t('Import Profile types into taxonomy terms.');

//     // Create a map object for tracking the relationships between source rows
//     $this->map = new MigrateSQLMap($this->machineName,
//       array(
//         'type' => array(
//           'type' => 'varchar',
//           'length' => 255,
//           'not null' => TRUE,
//         ),
//       ),
//       MigrateDestinationTerm::getKeySchema()
//     );

//   }

// }

class OCProfilesMigration extends OCMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import profiles.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'mail' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationEntityAPI::getKeySchema('profile2_type', 'researcher_profile')
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'oc_profile') . '/import/profiles.csv', array(), array(
      'header_rows' => 1,
    ));

    $this->destination = new MigrateDestinationProfile2('researcher_profile');
    $this->dependencies = array('OCUsers', 'OCPartners');

    // Connect the UID field to the mail field using the user's source migration.
    $this->addFieldMapping('uid', 'mail')
      ->sourceMigration('OCUsers');

    $this->addFieldMapping('field_rprofile_email', 'mail');
    $this->addFieldMapping('field_rprofile_telephone', 'telephone');
    $this->addFieldMapping('field_rprofile_first_name', 'first_name');
    $this->addFieldMapping('field_rprofile_last_name', 'last_name');
    $this->addFieldMapping('field_rprofile_title', 'role');

    $this->addFieldMapping('field_rprofile_photo', 'photo');
    $this->addFieldMapping('field_rprofile_photo:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_rprofile_photo:source_dir')
      ->defaultValue(drupal_get_path('module', 'oc_profile') . '/import/images');

    $this->addFieldMapping('field_rprofile_partner_ref', 'institution')
      ->sourceMigration('OCPartners');

    $this->addFieldMapping('field_rprofile_keywords', 'type');
    $this->addFieldMapping('field_rprofile_keywords:ignore_case')
      ->defaultValue(TRUE);

    $this->addFieldMapping('field_rprofile_lab', 'lab');
    $this->addFieldMapping('field_rprofile_website', 'website');
    $this->addFieldMapping('field_rprofile_short_bio', 'biography');
    $this->addFieldMapping('field_rprofile_short_bio:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_rprofile_publications', 'publications');
    $this->addFieldMapping('field_rprofile_publications:format')
      ->defaultValue('full_html');

    // Adress
    $this->addFieldMapping('field_rprofile_address', 'country');
    $this->addFieldMapping('field_rprofile_address:thoroughfare', 'address');
    $this->addFieldMapping('field_rprofile_address:locality', 'city');
    $this->addFieldMapping('field_rprofile_address:postal_code', 'postal_code');

    $this->addFieldMapping('field_rprofile_members', 'members')
      ->separator('|');
  }

  public function prepareRow($current_row) {
    $this->usersToProfiles($current_row, 'members');
  }

}
