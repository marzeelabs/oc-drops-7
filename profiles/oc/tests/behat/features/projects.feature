Feature: Projects
  For people to know which job positions are available for the project
  As any user
  I should be able to see the jobs pages
  As an editor
  I should be able to create and edit jobs

  Background:
    Given I am at "jobs"

  @api
  Scenario: User should see the title "Jobs"
    Then I should see the heading "Jobs"

  @api
  Scenario: User should see the page content
    Then I should see the ".view-project-jobs" element
    And I should see the ".view-project-jobs" element inside the "#content" element

  @api
  Scenario: Editor should be able to create jobs
    Given I am logged in as a user with the "editor" role
    When I am viewing a "project" node:
      | title                | Management of Foo           |
      | body                 | Experience in Bar required. |
      | field_project_status | open                        |
      | status               | 1                           |
    Then I should see the heading "Management of Foo"
    And I should see "Experience in Bar required."

  @api
  Scenario: Editor should be able to edit jobs
    Given I am logged in as a user with the "editor" role
    Then I should be able to edit a "project" node