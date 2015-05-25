<?php
/**
 * @file
 * Display Suite Omega OC 2regions template.
 *
 * Available variables:
 *
 * Layout:
 * - $classes: String of classes that can be used to style this layout.
 * - $contextual_links: Renderable array of contextual links.
 * - $layout_wrapper: wrapper surrounding the layout.
 *
 * Regions:
 *
 * - $primary: Rendered content for the "Primary" region.
 * - $primary_classes: String of classes that can be used to style the "Primary" region.
 *
 * - $secondary: Rendered content for the "Secondary" region.
 * - $secondary_classes: String of classes that can be used to style the "Secondary" region.
 */
?>
<<?php print $layout_wrapper; print $layout_attributes; ?> class="oc-2regions <?php print $classes;?> clearfix">

  <!-- Needed to activate contextual links -->
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

    <<?php print $primary_wrapper; ?> class="ds-primary<?php print $primary_classes; ?>">
      <?php print $primary; ?>
    </<?php print $primary_wrapper; ?>>

    <<?php print $secondary_wrapper; ?> class="ds-secondary<?php print $secondary_classes; ?>">
      <?php print $secondary; ?>
    </<?php print $secondary_wrapper; ?>>

</<?php print $layout_wrapper ?>>

<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
