<?php
/**
 * @file
 * The UI and menu includes.
 *
 * Provides the default options array and generates and
 * validates the settings form.
 */

/**
 * Implements hook_views_jqfx_jqfx_types().
 */
function views_jqfx_nivoslider_views_jqfx_jqfx_types() {
  $options = array(
    'views_jqfx_nivoslider' => t('Nivo Slider'),
  );
  return $options;
}

/**
 * Implements hook_views_jqfx_option_definition().
 */
function views_jqfx_nivoslider_views_jqfx_option_definition() {
  // Set our default options.
  $options['views_jqfx_nivoslider'] = array(
    'contains' => array(
      // Display options
      'style'                      => array('default' => 'default'),
      'pack_js'                    => array('default' => TRUE),
      'caption_opacity'            => array('default' => '0.8'),
      'start_slide'                => array('default' => '0'),
      // Transition options
      'transition'                 => array(
        'contains'                   => array(
          'effect'                     => array('default' => 'random'),
          'slices'                     => array('default' => '15'),
          'box_cols'                   => array('default' => '8'),
          'box_rows'                   => array('default' => '4'),
          'anim_speed'                 => array('default' => '500'),
          'pause_time'                 => array('default' => '3000'),
        ),
      ),
      // Navigation options
      'navigation'                 => array(
        'contains'                   => array(
          'direction_nav'              => array('default' => TRUE),
          'direction_nav_hide'         => array('default' => TRUE),
          'control_nav'                => array('default' => TRUE),
          'control_nav_thumbs'         => array('default' => TRUE),
          'control_nav_thumbs_search'  => array('default' => 'large'),
          'control_nav_thumbs_replace' => array('default' => 'thumbnail'),
          'keyboard_nav'               => array('default' => TRUE),
          'pause_on_hover'             => array('default' => TRUE),
          'manual_advance'             => array('default' => FALSE),
        ),
      ),
      // Advanced options
      'advanced'                   => array(
        'contains'                   => array(
          'before_change'              => array('default' => NULL),
          'after_change'               => array('default' => NULL),
          'slideshow_end'              => array('default' => NULL),
          'last_slide'                 => array('default' => NULL),
          'after_load'                 => array('default' => NULL),
        ),
      ),
    ),
  );
  return $options;
}

/**
 * Implements hook_views_jqfx_views_jqfx_type_form().
 */
function views_jqfx_nivoslider_views_jqfx_jqfx_type_form(&$form, &$form_state, &$view) {
  ctools_include('dependent');

  // Display options
  $styles = views_jqfx_nivoslider_styles();
  $form['views_jqfx_nivoslider']['style'] = array(
    '#type' => 'select',
    '#title' => t('Style'),
    '#description' => t('Default is styled for flexible image sizes and button or optional 50x50 thumbnail navigation. The Orman theme comes styled for a 568x268 image preset and button navigation. The Pascal theme comes styled for a 630x235 image preset and button navigation.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['style'],
    '#options' => $styles,
  );
  $form['views_jqfx_nivoslider']['pack_js'] = array(
    '#type' => 'select',
    '#title' => t('Use packed javascript'),
    '#description' => t('Enabling this loads the packed version of the Nivo Slider plugin.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['pack_js'],
    '#options' => array(
      FALSE => t('Disabled'),
      TRUE => t('Enabled'),
    ),
  );
  $form['views_jqfx_nivoslider']['caption_opacity'] = array(
    '#type' => 'textfield',
    '#title' => t('Caption Opacity'),
    '#description' => t('Universal caption opacity.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['caption_opacity'],
  );
  $form['views_jqfx_nivoslider']['start_slide'] = array(
    '#type' => 'textfield',
    '#title' => t('Start slide'),
    '#description' => t('Set starting Slide (0 index).'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['start_slide'],
  );

  // Transition options
  $form['views_jqfx_nivoslider']['transition'] = array(
    '#type' => 'fieldset',
    '#title' => t('Image transition options'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $effect = array(
    'random' => t('Random'),
    'sliceDown' => t('Slice down'),
    'sliceDownLeft' => t('Slice down left'),
    'sliceDownRight' => t('Slice down right'),
    'sliceUp' => t('Slice up'),
    'sliceUpLeft' => t('Slice up left'),
    'sliceUpRight' => t('Slice up right'),
    'sliceUpDown' => t('Slice up down'),
    'sliceUpDownLeft' => t('Slice up down left'),
    'fold' => t('Fold'),
    'fade' => t('Fade'),
    'slideInLeft' => t('Slide in left'),
    'slideInRight' => t('Slide in right'),
    'boxRandom' => t('Box random'),
    'boxRain' => t('Box rain'),
    'boxRainReverse' => t('Box rain reverse'),
    'boxRainGrow' => t('Box rain grow'),
    'boxRainGrowReverse' => t('Box rain grow reverse'),
  );
  $form['views_jqfx_nivoslider']['transition']['effect'] = array(
    '#type' => 'select',
    '#title' => t('Effect'),
    '#description' => t('The transition effect between images'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['transition']['effect'],
    '#options' => $effect,
  );
  $form['views_jqfx_nivoslider']['transition']['slices'] = array(
    '#type' => 'textfield',
    '#title' => t('Slices'),
    '#description' => t('The number of slices used in the transitions.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['transition']['slices'],
  );
  $form['views_jqfx_nivoslider']['transition']['box_cols'] = array(
    '#type' => 'textfield',
    '#title' => t('Box columns'),
    '#description' => t('The number of columns used in the box style transitions.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['transition']['box_cols'],
  );
  $form['views_jqfx_nivoslider']['transition']['box_rows'] = array(
    '#type' => 'textfield',
    '#title' => t('Box rows'),
    '#description' => t('The number of rows used in the box style transitions.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['transition']['box_rows'],
  );
  $form['views_jqfx_nivoslider']['transition']['anim_speed'] = array(
    '#type' => 'textfield',
    '#title' => t('Animation Speed'),
    '#description' => t('Animation speed in milliseconds'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['transition']['anim_speed'],
  );
  $form['views_jqfx_nivoslider']['transition']['pause_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Pause Time'),
    '#description' => t('Pause time in milliseconds.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['transition']['pause_time'],
  );

  // Navigation options
  $form['views_jqfx_nivoslider']['navigation'] = array(
    '#type' => 'fieldset',
    '#title' => t('Navigation options'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['views_jqfx_nivoslider']['navigation']['direction_nav'] = array(
    '#type' => 'select',
    '#title' => t('Direction Navigator'),
    '#description' => t('Previous and next navigation.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['navigation']['direction_nav'],
    '#options' => array(
      FALSE => t('Disabled'),
      TRUE => t('Enabled'),
    ),
  );
  $form['views_jqfx_nivoslider']['navigation']['direction_nav_hide'] = array(
    '#type' => 'select',
    '#title' => t('Direction Navigator Hide'),
    '#description' => t('Only show direction navigator on mouse over.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['navigation']['direction_nav_hide'],
    '#process' => array('ctools_dependent_process'),
    '#dependency' => array('edit-style-options-views-jqfx-nivoslider-navigation-direction-nav' => array(TRUE)),
    '#options' => array(
      FALSE => t('Disabled'),
      TRUE => t('Enabled'),
    ),
  );
  $form['views_jqfx_nivoslider']['navigation']['control_nav'] = array(
    '#type' => 'select',
    '#title' => t('Control Navigator'),
    '#description' => t('Chose navigation buttons/thumbs.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['navigation']['control_nav'],
    '#options' => array(
      FALSE => t('Disabled'),
      TRUE => t('Buttons'),
      'thumbnails' => t('Thumbnails'),
    ),
  );
  $presets = array();
  foreach (image_styles() as $p) {
    $presets[$p['name']] = $p['name'];
  }
  $form['views_jqfx_nivoslider']['navigation']['control_nav_thumbs_search'] = array(
    '#type' => 'select',
    '#title' => t('Slide image style preset'),
    '#description' => t('Select the image style preset that was chosen for the slide images in your view setting.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['navigation']['control_nav_thumbs_search'],
    '#process' => array('ctools_dependent_process'),
    '#dependency' => array('edit-style-options-views-jqfx-nivoslider-navigation-control-nav' => array('thumbnails')),
    '#options' => $presets,
  );
  $form['views_jqfx_nivoslider']['navigation']['control_nav_thumbs_replace'] = array(
    '#type' => 'select',
    '#title' => t('Thumbnail image style preset'),
    '#description' => t('The image style preset to be used for the thumbnail images. The default css is styled for 50x50 images.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['navigation']['control_nav_thumbs_replace'],
    '#process' => array('ctools_dependent_process'),
    '#dependency' => array('edit-style-options-views-jqfx-nivoslider-navigation-control-nav' => array('thumbnails')),
    '#options' => $presets,
  );
  $form['views_jqfx_nivoslider']['navigation']['keyboard_nav'] = array(
    '#type' => 'select',
    '#title' => t('Keyboard Navigator'),
    '#description' => t('Use left and right arrows.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['navigation']['keyboard_nav'],
    '#options' => array(
      FALSE => t('Disabled'),
      TRUE => t('Enabled'),
    ),
  );
  $form['views_jqfx_nivoslider']['navigation']['pause_on_hover'] = array(
    '#type' => 'select',
    '#title' => t('Pause on Hover'),
    '#description' => t('Stop animation while hovering.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['navigation']['pause_on_hover'],
    '#options' => array(
      FALSE => t('Disabled'),
      TRUE => t('Enabled'),
    ),
  );
  $form['views_jqfx_nivoslider']['navigation']['manual_advance'] = array(
    '#type' => 'select',
    '#title' => t('Manual Advance'),
    '#description' => t('Force manual transitions.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['navigation']['manual_advance'],
    '#options' => array(
      FALSE => t('Disabled'),
      TRUE => t('Enabled'),
    ),
  );

  // Advanced functions fieldset
  $form['views_jqfx_nivoslider']['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced options'),
    '#description' => t('These must be entered in the form of a %function. They will pass raw javascript to your Nivo Slider (Caution: experts only!).', array('%function' => 'function(){}')),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['views_jqfx_nivoslider']['advanced']['before_change'] = array(
    '#type' => 'textarea',
    '#title' => t('Before change'),
    '#description' => t('A function that triggers before a slide change.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['advanced']['before_change'],
  );
  $form['views_jqfx_nivoslider']['advanced']['after_change'] = array(
    '#type' => 'textarea',
    '#title' => t('After change'),
    '#description' => t('A function that triggers after a slide change.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['advanced']['after_change'],
  );
  $form['views_jqfx_nivoslider']['advanced']['slideshow_end'] = array(
    '#type' => 'textarea',
    '#title' => t('Slideshow end'),
    '#description' => t('A function that triggers after all slides have been shown.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['advanced']['slideshow_end'],
  );
  $form['views_jqfx_nivoslider']['advanced']['last_slide'] = array(
    '#type' => 'textarea',
    '#title' => t('Last slide'),
    '#description' => t('A function that triggers when last slide is shown.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['advanced']['last_slide'],
  );
  $form['views_jqfx_nivoslider']['advanced']['after_load'] = array(
    '#type' => 'textarea',
    '#title' => t('After load'),
    '#description' => t('A function that triggers when slider has loaded.'),
    '#default_value' => $view->options['views_jqfx_nivoslider']['advanced']['after_load'],
  );
}

// Validate the form options.
function views_jqfx_nivoslider_views_jqfx_options_form_validate(&$form, &$form_state, &$view) {
  if (!is_numeric($form_state['values']['style_options']['views_jqfx_nivoslider']['slices'])) {
    form_error($form['views_jqfx_nivoslider']['slices'], t('!setting must be numeric!', array('Slices')));
  }
  if (!is_numeric($form_state['values']['style_options']['views_jqfx_nivoslider']['box_cols'])) {
    form_error($form['views_jqfx_nivoslider']['box_cols'], t('!setting must be numeric!', array('Box columns')));
  }
  if (!is_numeric($form_state['values']['style_options']['views_jqfx_nivoslider']['box_rows'])) {
    form_error($form['views_jqfx_nivoslider']['box_rows'], t('!setting must be numeric!', array('Box rows')));
  }
  if (!is_numeric($form_state['values']['style_options']['views_jqfx_nivoslider']['anim_speed'])) {
    form_error($form['views_jqfx_nivoslider']['anim_speed'], t('!setting must be numeric!', array('Animation speed')));
  }
  if (!is_numeric($form_state['values']['style_options']['views_jqfx_nivoslider']['pause_time'])) {
    form_error($form['views_jqfx_nivoslider']['pause_time'], t('!setting must be numeric!', array('Pause time')));
  }
  if (!is_numeric($form_state['values']['style_options']['views_jqfx_nivoslider']['start_slide'])) {
    form_error($form['views_jqfx_nivoslider']['start_slide'], t('!setting must be numeric!', array('Start slide')));
  }
  if (!is_numeric($form_state['values']['style_options']['views_jqfx_nivoslider']['caption_opacity'])) {
    form_error($form['views_jqfx_nivoslider']['caption_opacity'], t('!setting must be numeric!', array('Universal caption opacity')));
  }
}
