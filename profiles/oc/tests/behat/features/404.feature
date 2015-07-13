Feature: Page not found
  For people to know they've followed a broken link
  As any user
  I should be able to see an error page

  Background:
    Given I am on "random string with 20 characters"

  @api
  Scenario: Server should send a 404 status
    Then print current URL
    And the response status code should be 404

  @api
  Scenario: User should see the title "Page not found"
    Then I should see the heading "Page not found"

  @api
  Scenario: User should not see any content
    Then I should not see the ".view" element