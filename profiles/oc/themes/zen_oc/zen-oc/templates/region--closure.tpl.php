<?php
/**
 * @file
 * Returns HTML for a region.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728112
 */
?>
<div id="<?php print $region; ?>" class="<?php print $classes; ?>">
  
  <div class="oc-power clearfix"><small>Powered by</small> <a href="http://openconsortium.eu/" target="_blank" class="oc-logo">Open Consortium</a></div>
  
  <?php if ($content): ?>
    <?php print $content; ?>
  <?php endif; ?>

</div><!-- /.region -->
