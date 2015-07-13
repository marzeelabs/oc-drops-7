Feature: News
  For people to be able to follow the news
  As any user
  I should be able to see a list of news articles
  As an editor
  I should be able to create and edit news articles

  Background:
    Given I am at "news"

  @api
  Scenario: User should see the title "News"
    Then I should see the heading "News"

  @api
  Scenario: User should see a list of news
    Then I should see the ".view-news" element
    And I should see the ".view-news" element inside the "#content" element

  @api
  Scenario: Editor should be able to create news
    Given I am logged in as a user with the "editor" role
    When I am viewing an "article" node:
      | title              | Foo proven to be Bar  |
      | field_article_date | 2015-06-23            |
      | body               | Baz and Qux in study. |
      | status             | 1                     |
    Then I should see the heading "Foo proven to be Bar"
    And I should see "Baz and Qux in study."

  @api
  Scenario: Editor should be able to edit news
    Given I am logged in as a user with the "editor" role
    Then I should be able to edit an "article" node