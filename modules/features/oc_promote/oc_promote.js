(function ($) {
  Drupal.behaviors.oc_promote = {
    attach: function (context, settings) {

      // See http://www.woothemes.com/flexslider/ for more options
      $('.flexslider-promoted').flexslider({
        animation: "fade",
        animationSpeed: 1200,

        // Primary Controls
        controlNav: true,               //Boolean: Create navigation for paging control of each clide? Note: Leave true for manualControls usage
        directionNav: true,             //Boolean: Create navigation for previous/next navigation? (true/false)
        prevText: "&#x2190;",           //String: Set the text for the "previous" directionNav item
        nextText: "&#x2192;",               //String: Set the text for the "next" directionNav item

      });

    }
  };
})(jQuery);
