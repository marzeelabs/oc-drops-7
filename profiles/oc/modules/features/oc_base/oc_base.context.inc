<?php
/**
 * @file
 * oc_base.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function oc_base_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'oc_base_front_page';
  $context->description = 'Sets the front page blocks.';
  $context->tag = 'site';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-news-block' => array(
          'module' => 'views',
          'delta' => 'news-block',
          'region' => 'postscript_first',
          'weight' => '-10',
        ),
        'views-events-block_2' => array(
          'module' => 'views',
          'delta' => 'events-block_2',
          'region' => 'postscript_second',
          'weight' => '-9',
        ),
        'bean-oc-about' => array(
          'module' => 'bean',
          'delta' => 'oc-about',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sets the front page blocks.');
  t('site');
  $export['oc_base_front_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'oc_menu_blocks';
  $context->description = 'Sitewide menus';
  $context->tag = 'site';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => '1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide menus');
  t('site');
  $export['oc_menu_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'oc_menu_blocks_anon';
  $context->description = 'Sitewide menus for the anonymous user.';
  $context->tag = 'site';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-3' => array(
          'module' => 'menu_block',
          'delta' => '3',
          'region' => 'menu',
          'weight' => '-10',
        ),
        'menu-menu-anonymous-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-anonymous-menu',
          'region' => 'menu_secondary',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide menus for the anonymous user.');
  t('site');
  $export['oc_menu_blocks_anon'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'oc_menu_blocks_auth';
  $context->description = 'Sitewide menus for the authenticated user.';
  $context->tag = 'site';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-3' => array(
          'module' => 'menu_block',
          'delta' => '3',
          'region' => 'menu',
          'weight' => '-10',
        ),
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'menu_secondary',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide menus for the authenticated user.');
  t('site');
  $export['oc_menu_blocks_auth'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'oc_theme_footer';
  $context->description = 'Sets the footer blocks.';
  $context->tag = 'site';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'oc_base-oc-site-info' => array(
          'module' => 'oc_base',
          'delta' => 'oc-site-info',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'oc_base-oc-site-logos' => array(
          'module' => 'oc_base',
          'delta' => 'oc-site-logos',
          'region' => 'footer',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sets the footer blocks.');
  t('site');
  $export['oc_theme_footer'] = $context;

  return $export;
}
