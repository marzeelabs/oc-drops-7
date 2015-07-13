Feature: Work Packages
  For people to know which work packages are projects divided into
  As any user
  I should be able to see the work packages pages
  As an editor
  I should be able to create and edit work packages

  Background:
    Given I am at "work-packages"

  @api
  Scenario: User should see the title "Work Packages"
    Then I should see the heading "Work Packages"

  @api
  Scenario: User should see the page content
    Then I should see the ".view-work-packages" element
    And I should see the ".view-work-packages" element inside the "#content" element

  @api
  Scenario: Editor should be able to create work packages
    Given I am logged in as a user with the "editor" role
    When I am viewing a "wp" node:
      | title        | Management of Foo WP1     |
      | body         | Extracting Bar out of Foo |
      | status       | 1                         |
    Then I should see the heading "Management of Foo WP1"
    And I should see "Extracting Bar out of Foo"

  @api
  Scenario: Editor should be able to edit work packages
    Given I am logged in as a user with the "editor" role
    Then I should be able to edit a "wp" node