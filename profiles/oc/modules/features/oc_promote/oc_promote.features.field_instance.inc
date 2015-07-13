<?php
/**
 * @file
 * oc_promote.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function oc_promote_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-featured_content-field_promoted_content'
  $field_instances['node-featured_content-field_promoted_content'] = array(
    'bundle' => 'featured_content',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the title of the content you would like to link to, and it will turn into a "Read more" link on the featured content. Leave empty if you do not wish to link.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
      'promoted_big' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'promoted_small' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_promoted_content',
    'label' => 'Promoted Content',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-featured_content-field_promoted_media'
  $field_instances['node-featured_content-field_promoted_media'] = array(
    'bundle' => 'featured_content',
    'deleted' => 0,
    'description' => 'Select a media item to use prominently on the front page. It can be a nice image, a Youtube, or anything else that captures the user\'s attention.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 3,
      ),
      'promoted_big' => array(
        'label' => 'hidden',
        'module' => 'file_entity',
        'settings' => array(
          'file_view_mode' => 'promoted_big',
        ),
        'type' => 'file_rendered',
        'weight' => 0,
      ),
      'promoted_small' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_promoted_media',
    'label' => 'Media Teaser',
    'required' => 1,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'featured-images',
      'file_extensions' => 'jpg jpeg gif png',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 'public',
          'youtube' => 'youtube',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 'video',
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 'media_internet',
          'upload' => 'upload',
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-featured_content-field_promoted_text'
  $field_instances['node-featured_content-field_promoted_text'] = array(
    'bundle' => 'featured_content',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Write a couple of sentences to introduce this featured content. Note that you can also link to other content on the site from the "promoted content" field below.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'promoted_big' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'promoted_small' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_promoted_text',
    'label' => 'Text teaser',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 250,
        'maxlength_js_enforce' => 1,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 1,
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Enter the title of the content you would like to link to, and it will turn into a "Read more" link on the featured content. Leave empty if you do not wish to link.');
  t('Media Teaser');
  t('Promoted Content');
  t('Select a media item to use prominently on the front page. It can be a nice image, a Youtube, or anything else that captures the user\'s attention.');
  t('Text teaser');
  t('Write a couple of sentences to introduce this featured content. Note that you can also link to other content on the site from the "promoted content" field below.');

  return $field_instances;
}
