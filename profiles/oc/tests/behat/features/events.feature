Feature: Events
  For people to check available events
  As any user
  I should be able to see a list of events
  As an editor
  I should be able to create and edit events

  Background:
    Given I am at "events"

  @api
  Scenario: User should see the title "Events"
    Then I should see the heading "Events"

  @api
  Scenario: User should see a list of events
    Then I should see the ".view-events" element
    And I should see the ".view-events" element inside the "#content" element

  @api
  Scenario: Editor should be able to create an event
    Given I am logged in as a user with the "editor" role
    When I am viewing an "event" node:
      | title            | FooCon 2015            |
      | body             | Open bar!              |
      | field_event_date | 2015-06-23, 2015-06-24 |
      | status           | 1                      |
    Then I should see the heading "FooCon 2015"
    And I should see "Open bar!"

  @api
  Scenario: Editor should be able to edit an event
    Given I am logged in as a user with the "editor" role
    Then I should be able to edit an "event" node