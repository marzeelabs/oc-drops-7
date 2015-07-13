<?php

class OCPages extends OCMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import pages nodes.');

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
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'oc_pages') . '/import/pages.csv', array(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('page');

    $this->addFieldMapping('title', 'title');
    // $this->addFieldMapping('path', 'path');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')->defaultValue('full_html');

    $this->addFieldMapping('field_page_blocks', 'blocks')
       ->separator('|');

    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addFieldMapping('workbench_moderation_state_new')->defaultValue('published');
  }

  public function prepareRow($row) {
    if ($row->blocks) {
      $bids = array();
      $blocks = explode('|', $row->blocks);
      foreach ($blocks as $delta) {
        $block = $this->_block_load('bean', $delta, 'zen_oc');
        $bids[] = $block->bid;
      }
      $row->blocks = implode('|', $bids);
    }
  }

  /**
   * Load a block in a given theme.
   */
  private function _block_load($module, $delta, $theme) {
    if (isset($delta)) {
      $block = db_query('SELECT * FROM {block} WHERE module = :module AND delta = :delta AND theme = :theme', array(':module' => $module, ':delta' => $delta, ':theme' => $theme))->fetchObject();
    }

    // If the block does not exist in the database yet return a stub block
    // object.
    if (empty($block)) {
      $block = new stdClass();
      $block->module = $module;
      $block->delta = $delta;
    }

    return $block;
  }

}


class OCPagesMenus extends OCMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Creates sample menues.');

    $this->dependencies = array('OCPages');

    // the csv file contains the header.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'oc_pages') . '/import/menus.csv', array(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationMenuLinks();

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'mlid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'ID of destination link',
          ),
        ),
      MigrateDestinationMenuLinks::getKeySchema()
      );


    $this->addFieldMapping('menu_name')->defaultValue('main-menu'); // Always Main menu

    $this->addFieldMapping('plid', 'ref_parent')->sourceMigration($this->getMachineName());
    $this->addFieldMapping('link_path', 'path');          // path of the link
    $this->addFieldMapping('router_path')->defaultValue('node/%');
    $this->addFieldMapping('link_title', 'title');        // Title of the menu item
    $this->addFieldMapping('external')->defaultValue('0'); // Internal
    $this->addFieldMapping('expanded')->defaultValue('0');
    $this->addFieldMapping('weight','weight');            // weight
    $this->addFieldMapping('customized')->defaultValue('1'); // not customized
    $this->addFieldMapping('has_children')->defaultValue('0');  // Will be overridden automatically
    $this->addFieldMapping('depth')->defaultValue('1'); // Will be overridden automatically

    $this->addUnmigratedDestinations(array('module', 'hidden','options','p1', 'p2', 'p3', 'p4', 'p5', 'p6', 'p7', 'p8', 'p9', 'updated'));
  }


  function prepareRow($row) {
    // Convert the alias to the node path.
    $node_path = drupal_lookup_path('source', $row->path);
    if(FALSE == $node_path) {
      // return FALSE;
    } else {
      $row->path = $node_path;
    }
  }

  protected function createStub($migration) {
    // if ref_parent is 0, that means it has no parent, so don't create a stub
    if (!$migration->sourceValues->ref_parent) {
      return FALSE;
    }
    $menu_link = array (
      'menu_name' => $migration->sourceValues->menu_name,
      'link_path' => 'stub-path',
      'router_path' => 'stub-path',
      'link_title' => t('Stub title'),
    );

    $mlid = menu_link_save($menu_link);
    if ($mlid) {
      return array($mlid);
    }
    else {
      return FALSE;
    }
  }

}
