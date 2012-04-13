/**
 *  @file
 *  This will pass the settings and initiate the Nivo Slider.
 *  It also sets a maximum height and width for the container dimensions.
 */
(function($) {
Drupal.behaviors.viewsJqfxNivoslider = {
  attach: function (context) {
    for (id in Drupal.settings.viewsJqfxNivoslider) {
      $('#' + id + ':not(.viewsJqfxNivoslider-processed)', context).addClass('viewsJqfxNivoslider-processed').each(function () {
        var _settings = Drupal.settings.viewsJqfxNivoslider[$(this).attr('id')];
        var nivo = $(this);
        // Fix sizes
        nivo.data('hmax', 0).data('wmax', 0);
        $('img', nivo).each(function () {
          hmax =  (nivo.data('hmax') > $(this).height()) ? nivo.data('hmax') : $(this).height();
          wmax =  (nivo.data('wmax') > $(this).width()) ? nivo.data('hmax') : $(this).width();
          nivo.width(wmax).height(hmax).data('hmax', hmax).data('wmax', wmax);
        });
        // Need to pass these settings as functions.
        if (_settings['beforeChange']) {
          var nivoBeforeChange = _settings['beforeChange'];
          eval("_settings['beforeChange'] = " + nivoBeforeChange);
        }
        if (_settings['afterChange']) {
          var nivoAfterChange = _settings['afterChange'];
          eval("_settings['afterChange'] = " + nivoAfterChange);
        }
        if (_settings['slideshowEnd']) {
          var nivoSlideshowEnd = _settings['slideshowEnd'];
          eval("_settings['slideshowEnd'] = " + nivoSlideshowEnd);
        }
        if (_settings['lastSlide']) {
          var nivoLastSlide = _settings['lastSlide'];
          eval("_settings['lastSlide'] = " + nivoLastSlide);
        }
        if (_settings['afterLoad']) {
          var nivoAfterLoad = _settings['afterLoad'];
          eval("_settings['afterLoad'] = " + nivoAfterLoad);
        }
        // Load Nivoslider
        $(nivo).nivoSlider(_settings);
      });
    }
  }
}

})(jQuery);
