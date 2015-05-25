<?php

// Little hack to properly load parent classes. If not e.g. migrate won't work properly
require_once drupal_get_path('module', 'crumbs') . '/plugins/crumbs.taxonomy.inc';

class _taxonomy_CrumbsMultiPlugin_termReference_profile2 extends _taxonomy_CrumbsMultiPlugin_termReference {

  protected $entityType = 'profile2';

  /**
   * Match "profile/%" router path.
   */
  function findParent($path, $item) {
    $split= explode('/', $path);
    if (isset($split[0]) && $split[0] == 'profile-researcher_profile' && isset($item['map'][1])) {
      $profile = $item['map'][1];
      $parent_path = $this->_findParentPath($profile);

      if ($parent_path) {
        $terms_split = explode('/', $parent_path);
        if (isset($terms_split[2])) {
          $tid = $terms_split[2];
          $term = taxonomy_term_load($tid);
          $term_name_clean = str_replace(' ', '-', strtolower($term->name));
          return array('profile2' => 'network/' . $term_name_clean);
        }
      }
    }
  }
}
