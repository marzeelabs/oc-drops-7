Feature: OC site
  To be able to customize the website
  As an editor
  I should be able to edit the website information

  Background:
    Given I am logged in as a user with the "administrator" role
    And I am at "admin/oc"

  @api
  Scenario: Editor should be able to edit the Site name
    When I fill in "Site name" with "Open Consortium - random string"
    And I press "edit-submit"
    And I am on the homepage
    Then I should see a title containing "Open Consortium"

  @api
  Scenario: Editor should be able to enable footer logos
    When I check the box "Marie Curie Actions"
    And I press "edit-submit"
    And I am on the homepage
    Then I should see the ".footer-logos img[src$='marie-curie.png']" element

  @api
  Scenario: Editor should be able to disable footer logos
    When I uncheck the box "Marie Curie Actions"
    And I press "edit-submit"
    And I am on the homepage
    Then I should not see the ".footer-logos img[src$='marie-curie.png']" element