Feature: Pages
  For people to know more details about the Consortium
  As any user
  I should be able to see the Project pages
  As an editor
  I should be able to create and edit pages

  Background:
    Given I am at "content/about-project"

  @api
  Scenario: User should see the title "About the project"
    Then I should see the heading "About the project"

  @api
  Scenario: User should see the page content
    Then I should see the ".node-page" element
    And I should see the ".node-page" element inside the "#content" element

  @api
  Scenario: Editor should be able to see a link to content block creation when creating a page
    Given I am logged in as a user with the "editor" role
    When I am at "node/add/page"
    Then I should see the following <links>
    | links               |
    | Create a new block. |