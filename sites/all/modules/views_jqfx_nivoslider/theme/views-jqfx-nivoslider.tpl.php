<?php
/**
 *  @file
 *  Outputs the view.
 *
 */
?>

<div id="views-jqfx-nivoslider-<?php print $id; ?>" <?php print $wrapper; ?>>

  <div class="ribbon"></div>

  <div id="views-jqfx-nivoslider-images-<?php print $id; ?>" class=<?php print $classes; ?>>
    <?php foreach ($images as $image): ?>
     <?php print $image ."\n"; ?>
    <?php endforeach; ?>
  </div>

</div>

