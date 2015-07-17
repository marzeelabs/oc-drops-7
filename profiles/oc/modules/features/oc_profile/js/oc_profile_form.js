(function ($) {
  var partnerLogos = Drupal.settings.oc_profile.partnerLogos,
      partnerAddresses = Drupal.settings.oc_profile.partnerAddresses;
  $("select.chosen-enable option").each(function() {
    var nid = $(this).val();

    if (nid in partnerLogos) {
      $(this).wrapInner('<span class="profile-field-rprofile-partner-ref__text"></span>');
      $(this).prepend(
        '<img class="profile-field-rprofile-partner-ref__logo" src="' + partnerLogos[nid] + '" />'
      );
      $(this).find("span").append(
        '<hr />' + partnerAddresses[nid].locality + ', ' + partnerAddresses[nid].country
      );
    }
  });
}(jQuery));