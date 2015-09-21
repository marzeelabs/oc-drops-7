<?php
/**
 * @file
 * oc_news.default_snippet.inc
 */

/**
 * Implements hook_default_snippet().
 */
function oc_news_default_snippet() {
  $export = array();

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Latest News block - footer';
  $snippet->name = 'latest_news_block_footer';
  $snippet->title = '';
  $export['latest_news_block_footer'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'Latest News block - header';
  $snippet->name = 'latest_news_block_header';
  $snippet->title = '';
  $export['latest_news_block_header'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'News page - footer';
  $snippet->name = 'news_page_footer';
  $snippet->title = '';
  $export['news_page_footer'] = $snippet;

  $snippet = new stdClass();
  $snippet->disabled = FALSE; /* Edit this to true to make a default snippet disabled initially */
  $snippet->api_version = 1;
  $snippet->admin_title = 'News page - header';
  $snippet->name = 'news_page_header';
  $snippet->title = '';
  $export['news_page_header'] = $snippet;

  return $export;
}
