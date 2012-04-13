<?php
/**
 * @file
 * Theme & preprocess functions for the Views jQFX: Nivo Slider module.
 */

function template_preprocess_views_jqfx_nivoslider(&$vars) {
  // Initialize our $images array.
  $vars['images'] = array();

  // Strip all images from the $rows created by the original view query.
  foreach ($vars['rows'] as $item) {
    if (preg_match('@(<\s*img\s+[^>]*>)@i', $item, $matches)) {
      $image = $matches[1];
      // If our image is in an anchor tag, use its URL.
      if (preg_match('@<\s*a\s+href\s*=\s*"\s*([^"]+)\s*"[^>]*>[^<]*' . preg_quote($image) . '[^<]*<\s*/a\s*>@i', $item, $urls)) {
        $url = $urls[1];
      }
      // Or look to see if we have any other links in our views items.
      elseif (preg_match('@href\s*=\s*"([^"]+)"@i', $item, $urls)) {
        $url = $urls[1];
      }
      // Otherwise we have no $url.
      else $url = NULL;

      // Our image gets wrapped with the $url anchor if it is present.
      if ($url) {
        $image = '<a href="' . $url . '">' . $image . '</a>';
      }

      // Add the image to our image array to display.
      $vars['images'][] = $image;
    }
  }

  $options = $vars['options']['views_jqfx_nivoslider'];

  // Add our slider wrapper with the theme name in the class per nivo standards
  $vars['wrapper'] = 'class="slider-wrapper theme-' . $options['style'] . '"';

  _views_jqfx_nivoslider_add_js($options, 'views-jqfx-nivoslider-images-' . $vars['id']);

}

function _views_jqfx_nivoslider_add_js($options, $id) {

  // Get the path to our plugin.
  $path = libraries_get_path('nivo-slider');

  // Load the plugin javascript and css
  if ($options['pack_js']) {
    drupal_add_js($path . '/jquery.nivo.slider.pack.js');
  }
  else drupal_add_js($path . '/jquery.nivo.slider.js');
  drupal_add_css($path . '/nivo-slider.css');

  // Load the theme css
  drupal_add_css($path . "/themes/" . $options['style'] . "/" . $options['style'] . ".css");

  // Add the module js
  $drupal_path = drupal_get_path('module', 'views_jqfx_nivoslider');
  drupal_add_js($drupal_path . '/js/views_jqfx_nivoslider.js');

  // Get the javascript settings.
  $settings = array(
    // Display stuff
    'captionOpacity'   => (float) $options['caption_opacity'],
    'startSlide'       => (int) $options['start_slide'],
    // Transition stuff
    'effect'           => $options['transition']['effect'],
    'slices'           => (int) $options['transition']['slices'],
    'boxCols'          => (int) $options['transition']['box_cols'],
    'boxRows'          => (int) $options['transition']['box_rows'],
    'animSpeed'        => (int) $options['transition']['anim_speed'],
    'pauseTime'        => (int) $options['transition']['pause_time'],
    // Navigate stuff
    'directionNav'     => (bool) $options['navigation']['direction_nav'],
    'directionNavHide' => (bool) $options['navigation']['direction_nav_hide'],
    'controlNav'       => (bool) $options['navigation']['control_nav'],
    'keyboardNav'      => (bool) $options['navigation']['keyboard_nav'],
    'pauseOnHover'     => (bool) $options['navigation']['pause_on_hover'],
    'manualAdvance'    => (bool) $options['navigation']['manual_advance'],
  );

  // Since controlNav and controlNavThumbs are both boolean we need to translate our 'select' control_nav menu options.
  if ($options['navigation']['control_nav'] == 'thumbnails') {
    $settings['controlNavThumbs'] = TRUE;
    $settings['controlNavThumbsSearch'] = $options['navigation']['control_nav_thumbs_search'];
    $settings['controlNavThumbsReplace'] = $options['navigation']['control_nav_thumbs_replace'];
    // A few lines of custom css to style our thumbs
    drupal_add_css($drupal_path . '/theme/thumbnails.css');
  }

  // These are all raw javascript function options that will break the Nivo Slider if they are passed empty. Make sure they are set first.
  if ($options['advanced']['before_change']) {
    $settings['beforeChange'] = $options['advanced']['before_change'];
  }
  if ($options['advanced']['after_change']) {
    $settings['afterChange'] = $options['advanced']['after_change'];
  }
  if ($options['advanced']['slideshow_end']) {
    $settings['slideshowEnd'] = $options['advanced']['slideshow_end'];
  }
  if ($options['advanced']['last_slide']) {
    $settings['lastSlide'] = $options['advanced']['last_slide'];
  }
  if ($options['advanced']['after_load']) {
    $settings['afterLoad'] = $options['advanced']['after_load'];
  }

  // Add the settings array.
  drupal_add_js(array('viewsJqfxNivoslider' => array($id => $settings)), 'setting');
}
