<div class="footer-logos">
  <?php foreach($variables['logos'] as $logo): ?>
    <a href="<?php echo $logo['link'] ?>" target="_blank"><img src="<?php print $logo['img'] ?>" title="<?php print $logo['title']?>"></a>
  <?php endforeach; ?>
</div>
