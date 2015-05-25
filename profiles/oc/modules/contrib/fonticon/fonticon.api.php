<?php

/**
 * @file
 * Hooks provided by the Fomticon module.
 */

/**
 * Defines fonticon mappings.
 *
 * Note that you can also define these mappings
 * directly in your theme .info file, like this:
 *   fonticon[location] = '&#xe000;'
 */
function hook_fonticon_info() {
  $info['location'] = '&#xe000;';
  $info['user'] = '&#xe001;';

  return $info;
}
