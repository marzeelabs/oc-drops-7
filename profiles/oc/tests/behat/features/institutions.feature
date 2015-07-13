Feature: Institutions
  For people know which institutions are on the network
  As any user
  I should be able to see a list of institutions
  As an editor
  I should be able to create and edit institutions

  Background:
    Given I am at "institutions"

  @api
  Scenario: User should see the title "Institutions"
    Then I should see the heading "Institutions"

  @api
  Scenario: User should see a list of institutions
    Then I should see the ".view-institutions-list" element
    And I should see the ".view-institutions-list" element inside the "#content" element

  @api
  Scenario: Editor should be able to create an institution
    Given I am logged in as a user with the "editor" role
    When I am viewing a "partner" node:
      | title  | College of Foo |
      | body   | Bar et baz     |
      | status | 1              |
    Then I should see the heading "College of Foo"
    And I should see "Bar et baz"

  @api
  Scenario: Editor should be able to edit an institution
    Given I am logged in as a user with the "editor" role
    Then I should be able to edit a "partner" node