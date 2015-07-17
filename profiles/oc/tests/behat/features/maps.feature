Feature: Maps
  For people know where researchers and institutions are located
  As any user
  I should be able to see a map pinpointing their locations

  Background:
    Given I am not logged in

  @javascript
  Scenario: User should see a map with institutions
    When I am at "institutions/map"
    Then I should see the heading "Institutions on the map"
    And I should see the ".leaflet-tile-pane .leaflet-tile-container img.leaflet-tile-loaded" element
    And I should see the ".leaflet-objects-pane .leaflet-marker-pane img.leaflet-marker-icon" element

  @javascript
  Scenario: User should be able to create an institution and see it on the map
    Given I am logged in as "admin" with the password "admin"
    And I am at "node/add/partner"
    And I fill in "Name" with "Foo"
    And I fill in "Country" with "PT"
    And I wait for 5 seconds
    And I fill in "Address 1" with "Praça de Mouzinho de Albuquerque"
    And I fill in "Postal code" with "4100-357"
    And I fill in "City" with "Porto"
    And I press "edit-submit"
    Then I should see the heading "Foo"
    And I should see the ".leaflet-tile-pane .leaflet-tile-container img.leaflet-tile-loaded" element
    And I should see the ".leaflet-objects-pane .leaflet-marker-pane img.leaflet-marker-icon" element

  @javascript
  Scenario: User should see a map with researchers
    When I am at "network/partner/map"
    Then I should see the heading "Map of Partners"
    And I should see the ".leaflet-tile-pane .leaflet-tile-container img.leaflet-tile-loaded" element
    And I should see the ".leaflet-objects-pane .leaflet-marker-pane img.leaflet-marker-icon" element

  @javascript
  Scenario: User should be able to create a researcher profile and see it on the map
    Given I am logged in as "admin" with the password "admin"
    And I am at "admin/people/create"
    And I fill in "Username" with "Foo"
    And I fill in "E-mail address" with "random string@foo.bar"
    And I fill in "Password" with "foobar"
    And I fill in "Confirm password" with "foobar"
    And I select the radio button "Active"
    And I fill in "Country" with "PT"
    And I wait for 5 seconds
    And I fill in "Address 1" with "Praça de Mouzinho de Albuquerque"
    And I fill in "Postal code" with "4100-357"
    And I fill in "City" with "Porto"
    And I press "edit-submit"
    And I am at "users/foo"
    And I click "here"
    Then I should see the heading "Researcher Profile"
    And I should see the ".leaflet-tile-pane .leaflet-tile-container img.leaflet-tile-loaded" element
    And I should see the ".leaflet-objects-pane .leaflet-marker-pane img.leaflet-marker-icon" element
