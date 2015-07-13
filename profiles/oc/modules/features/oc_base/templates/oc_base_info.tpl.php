<?php if (variable_get('site_name')) : ?>
  <a class="footer-site-name" href="<?php print $GLOBALS['base_url']; ?>"><?php print variable_get('site_name')?></a>
<?php endif; ?>
<?php if (variable_get('oc_base_address')) : ?>
  <p class="footer-site-address"><?php print variable_get('oc_base_address')?></p>
<?php endif; ?>
<?php if (variable_get('site_mail')) : ?>
  <p class="footer-site-email"><?php print variable_get('site_mail'); ?></p>
<?php endif; ?>
<?php if (variable_get('oc_base_attribution')) : ?>
  <p class="footer-site-attribution"><small><?php print variable_get('oc_base_attribution'); ?></small></p>
<?php endif; ?>
