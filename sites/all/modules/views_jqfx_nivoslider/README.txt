Views jQFX: Nivo Slider
----------------------------
This module is a Views jQFX addon that integrates the Nivo Slider plugin with views.
The Views jQFX module is a dependency.

Installation
----------------------------
1) If you have not already done so, get and install the Views jQFX module from the drupal project page.
2) Place this module in your modules directory and enable it at admin/modules.
   It will appear in the views section.
3) Download the Nivo Slider plugin and place it in your sites/all/libraries directory.
   To get the plugin to go the project page (http://nivo.dev7studios.com).
   The final directory structure should look like:
     'sites/all/libraries/nivo-slider/license.txt'
     'sites/all/libraries/nivo-slider/jquery.nivo.slider.js'
     'sites/all/libraries/nivo-slider/jquery.nivo.slider.pack.js'
     'sites/all/libraries/nivo-slider/themes/'
     etc...
4) Create or edit your content type.
   Captions are created from the title tag attributes of the images in the content type you wish to display.
   If you want to display captions you must have the ability to add this attribute to you image fields.
   To enable image attributes navigate to admin->structure->content types
   Select 'manage fields' in the content type(s) that will be displayed in the Nivo Slider (or create a new content type).
   Edit the image field that you want to display and be sure that the 'title' box is checked.
   This will provide a textfield for adding information to uploaded images when creating or editing a node.
   If this is a new content type an image field will need to be created for it.
   It is possible to create links from the images.
   Install project link (http://drupal.org/project/link).
   Add a link field to your content type.
5) Create the nodes that you wish to display under admin->content->add
   Upload ONE image per node and fill in the title tag for the caption.
   Add your image link in the link field.
6) Create a node view.
   If you are new to views you may want to find a tutorial for it.
   There are many out there.
   Only the images in the node view will be displayed in the Nivo Slider.
   Navigate to admin->structure->views->add
   Name your view (ie. jQFX Nivo slider).
   Check the 'Create a page' and/or 'Create a block' view
   with display format 'jQFX' of 'fields'.
   Enter the maximum number of items to display.
   Next to the fields, click 'add'.
   Check any image fields you wish to apply (ie. Content: Image)
   then click 'Add and configure fields'.
   Select Formatter 'Image', chose a style.
   Then click 'Apply all displays'.
   Add your filters, arguments, etc for the content.
7) Next to 'Format: jQFX' click 'settings'.
   Under jQFX type->FX settings, select 'Nivo Slider'.
   This will open the fieldset for your Nivo Slider settings options.
   Choose your settings. They should be pretty self explainatory.
   Then click 'Apply all displays' and save your view.

Theming notes
----------------------------
  The Nivo slider plugin version 2.6 (tested) comes with three prepackaged themes.
  They are Default, Orman, and Pascal
  The css files are located at /nivo-slider/themes/[THEME-NAME]/{THEME-NAME].css
  Using a stock (not custom) theme adds the class "theme-[THEME-NAME]"
  to the Nivo slider wrapper.
  Custom themes add the class "theme-custom".
  Because of this stock themes won't work by loading them via custom theme path.

Nivo slider thumbnails
----------------------------
  The only appropriate stock theme for thumbnails is default.
  It works via "search and replace". In the settings menu:
  "Search" for the image style preset you are using in the slideshow.
  "Replace" with the image style preset you'd like to use for thumbnails.
  The buttons css gets overridden by the /views_jqfx_nivoslider/theme/thumbnails.css file.
  It is set up for 50x50 thumbnails.
  You can prevent thumbnail.css from being loaded by specifying a custom theme.
   
The Full Nivo Slider Options List .Every option except 'controlNavThumbsFromRel' is available.
===========================================================================================================
Name                      Type         Default          Description
-----------------------------------------------------------------------------------------------------------
effect                    String       random           Specify sets like: 'fold, fade, sliceDown'
slices                    Number       15               Number of slices used in the transition
boxCols                   Number       8                Number of columns used in the box style transitions
boxRows                   Number       4                Number of rows used in the box style transitions
animSpeed                 Number       500              Slide transition speed in ms
pauseTime                 Number       3000             Pause between transitions in ms
startSlide                Number       0                Set starting Slide (0 index)
directionNav              Boolean      true             Next & Prev
directionNavHide          Boolean      true             Only show on hover
controlNav                Boolean      true             1,2,3...
controlNavThumbs          Boolean      false            Use thumbnails for Control Nav
controlNavThumbsFromRel   Boolean      false            Use image rel for thumbs
controlNavThumbsSearch    String       .jpg             Replace this with...
controlNavThumbsReplace   String       _thumb.jpg       ...this in thumb Image src
keyboardNav               Boolean      true             Use left & right arrows
pauseOnHover              Boolean      true             Stop animation while hovering
manualAdvance             Boolean      false            Force manual transitions
captionOpacity            Number       0.8              Universal caption opacity
beforeChange              Function     function(){}
afterChange               Function     function(){}
slideshowEnd              Function     function(){}     Triggers after all slides have been shown
lastSlide                 Function     function(){}     Triggers when last slide is shown
afterLoad                 Function     function(){}     Triggers when slider has loaded
   
Please post any comments, questions, or bugs in the issues queue of the Views jQFX: Nivo Slider project page on Drupal
