<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>

<div id="page">

  <header class="header" id="header" role="banner">
    <div id="header-inner">
  
      <div id="navigation">
        <a class="navigation-toggle" href="#navigation">
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
        </a>
        <?php print render($page['menu']); ?>
        
      </div><!-- /#navigation -->

      <div class="branding">
      <?php if ($logo): ?>
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>
      <?php endif; ?>
  
      <?php if ($site_name || isset($oc_site_slogan) || isset($oc_site_mission)): ?>
        <div class="header__name-and-slogan" id="name-and-slogan">
          <?php if ($site_name): ?>
            <h1 class="header__site-name" id="site-name">
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="header__site-link" rel="home"><span><?php print $site_name; ?></span></a>
            </h1>
          <?php endif; ?>
  
          <?php if (isset($oc_site_slogan)): ?>
            <div class="header__site-slogan" id="site-slogan"><?php print $oc_site_slogan; ?></div>
          <?php endif; ?>
          
          <?php if (isset($oc_site_mission)): ?>
            <div class="header__site-mission" id="site-mission"><?php print $oc_site_mission; ?></div>
          <?php endif; ?>
          
        </div>
      <?php endif; ?>
      </div>
  
      <?php print render($page['header']); ?>

    </div>
  </header>

  <div id="main">
    <div class="inner">

      <?php
        // Render the help and highlight regions to see if there's anything in them.
        $help  = render($page['help']);
        $highlighted = render($page['highlighted']);
      ?>

      <?php if ($messages || $help || $highlighted): ?>
        <div id="above-content">
          <?php print $messages; ?>
          <?php print $help; ?>
          <?php print $highlighted; ?>
        </div>
      <?php endif; ?>

      <div id="content" class="column" role="main">
        <div class="content__above">
          <?php print $breadcrumb; ?>
          <a id="main-content"></a>
          <?php print render($title_prefix); ?>
          <?php if ($title): ?>
            <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
          <?php endif; ?>
          <?php print render($title_suffix); ?>
          <?php if($tabs): ?> <div id="tabs-wrapper"><?php print render($tabs); ?></div><?php endif; ?>
          <?php if ($action_links): ?>
            <ul class="action-links"><?php print render($action_links); ?></ul>
          <?php endif; ?>
        </div>
        <?php print render($page['content_top']); ?>
        <?php print render($page['content']); ?>
        <?php print render($page['content_bottom']); ?>
        <?php print $feed_icons; ?>
      </div>

      <?php
        // Render the sidebars to see if there's anything in them.
        $sidebar_first  = render($page['sidebar_first']);
        $sidebar_second = render($page['sidebar_second']);
      ?>

      <?php if ($sidebar_first || $sidebar_second): ?>
        <aside class="sidebars">
          <?php print $sidebar_first; ?>
          <?php print $sidebar_second; ?>
        </aside><!-- /.sidebars -->
      <?php endif; ?>

      <?php
        // Render the postscript regions to see if there's anything in them.
        $postscript_first  = render($page['postscript_first']);
        $postscript_second = render($page['postscript_second']);
        $postscript_third = render($page['postscript_third']);
      ?>

      <?php if ($postscript_first || $postscript_second || $postscript_third): ?>
        <aside id="postscript" <?php if ($postscript_third) print 'class="third"'; ?>>
          <?php print $postscript_first; ?>
          <?php print $postscript_second; ?>
          <?php print $postscript_third; ?>
        </aside><!-- /.postscript -->
      <?php endif; ?>

    </div>
  </div><!-- /#main -->
  
  <div id="menu-secondary-wrapper">
    <?php print render($page['menu_secondary']); ?>
  </div>

  <div id="footer-wrapper">
    <?php print render($page['footer']); ?>
    <?php print render($page['closure']); ?>
  </div>

</div><!-- /#page -->

<?php print render($page['bottom']); ?>
