Feature: Frontpage
  To have people being interested in the site
  As any user
  I should be able to see an appealing homepage
  As an editor
  I should be able to create and edit featured content

  Background:
    Given I am on the homepage

  @api
  Scenario: User should see the name of the website
    Then I should see a title containing "Open Consortium"

  @api
  Scenario: User should see the default featured content slides
    Then I should see the following <texts>
      | texts                                                        |
      | Consortium members wins prestigious ERC Starting Grant Award |
      | Open Consortium Linux workshop                               |
      | New European research network coordinated in Barcelona       |

  @api
  Scenario: Editor should be able to edit featured content
    Given I am logged in as a user with the "editor" role
    Then I should be able to edit a "featured_content" node

  @javascript
  Scenario: Editor should be able to create featured content
    Given I am logged in as "admin" with the password "admin"
    And I am at "node/add/featured-content"
    And I fill in "Title" with "Foo"
    And I fill in "Text teaser" with "Foo Bar"
    And I upload an image to media
    And I wait for 5 seconds
    When I am on the homepage
    Then I should see the following <texts>
      | texts   |
      | Foo Bar |
    And I should see the ".node-featured-content img[src*='screenshot']" element
