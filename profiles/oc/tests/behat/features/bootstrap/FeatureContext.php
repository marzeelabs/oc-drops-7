<?php

use Behat\Behat\Context\ClosuredContextInterface,
  Behat\Behat\Context\TranslatedContextInterface,
  Behat\Behat\Context\BehatContext,
  Behat\Behat\Exception\PendingException;
use Behat\Gherkin\Node\PyStringNode,
  Behat\Gherkin\Node\TableNode;
use Drupal\DrupalExtension\Context\DrupalContext;

use Symfony\Component\Process\Process;
use Behat\Behat\Context\Step\Given;
use Behat\Behat\Context\Step\When;
use Behat\Behat\Context\Step\Then;
use Behat\Behat\Event\ScenarioEvent;
use Behat\Behat\Event\StepEvent;
use Behat\Mink\Exception\ElementNotFoundException;

require 'vendor/autoload.php';

//
// Require 3rd-party libraries here:
//
//   require_once 'PHPUnit/Autoload.php';
//   require_once 'PHPUnit/Framework/Assert/Functions.php';
//

/**
 * Features context.
 */
class FeatureContext extends DrupalContext {
  /**
   * Initializes context.
   * Every scenario gets its own context object.
   *
   * @param array $parameters context parameters (set them up through behat.yml)
   */
  public function __construct(array $parameters) {
    // Initialize your context here
  }

  /**
   * Private function for the whoami step.
   */
  private function whoami() {
    $element = $this->getSession()->getPage();
    // Go to the user page.
    $this->getSession()->visit($this->locatePath('/user'));
    if ($find = $element->find('css', 'h1')) {
      $page_title = $find->getText();
      if ($page_title) {
        return str_replace('hello, ', '', strtolower($page_title));
      }
    }
    return FALSE;
  }

  /**
   * Helper function to fetch user details stored in behat.local.yml.
   *
   * @param string $type
   *   The user type, e.g. drupal.
   *
   * @param string $name
   *   The username to fetch the password for.
   *
   * @return string
   *   The matching password or FALSE on error.
   */
  public function fetchUserDetails($type, $name) {
    $property_name = $type . '_users';
    try {
      $property = $this->$property_name;
      $details = $property[$name];
      return $details;
    } catch (Exception $e) {
      throw new Exception("Non-existant user/password for $property_name:$name please check behat.local.yml.");
    }
  }

  /**
   * Helper function to generalize metatag behat tests
   */
  private function assertMetaRegionGeneric($type, $metatag, $value) {
    $element = $this->getSession()->getPage()->find('xpath', '/head/meta[@' . $type . '="' . $metatag . '"]/@content');

    if ($element && $value == $element->getText()) {
      $result = $value;
    }

    if (empty($result)) {
      throw new \Exception(sprintf('No link to "%s" on the page %s', $metatag, $this->getSession()->getCurrentUrl()));
    }
  }

  /**
   * @Transform /^(.*)?random string(?: with (\d+) characters)?(.*)?$/
   */
  public function generateRandomString($start = "", $length = 10, $finish = "") {
    $length ? $length = $length : $length = 10;
    $allowedChars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    $allowedCharsCount = strlen($allowedChars); // store for efficiency
    $randomString = "";

    for ($i=0; $i < $length; $i++) {
      $randomString .= $allowedChars[mt_rand(0, $allowedCharsCount - 1)];
    }

    return $start . $randomString . $finish;
  }

  /**
   * @Given /^(?:|I )wait for AJAX loading to finish$/
   *
   * Wait for the jQuery AJAX loading to finish. ONLY USE FOR DEBUGGING!
   */
  public function iWaitForAJAX() {
    $this->getSession()->wait(5000, 'jQuery.active === 0');
  }

  /**
   * @Given /^(?:|I )wait(?:| for) (\d+) seconds?$/
   *
   * Wait for the given number of seconds. ONLY USE FOR DEBUGGING!
   */
  public function iWaitForSeconds($arg1) {
    sleep($arg1);
  }

  /**
   * Authenticates a user.
   *
   * @Given /^I am logged in as "([^"]*)" with the password "([^"]*)"$/
   */
  public function iAmLoggedInAsWithThePassword($username, $passwd) {
    $user = $this->whoami();

    if (strtolower($user) == strtolower($username)) {
      // Already logged in.
      return;
    }

    $element = $this->getSession()->getPage();
    if (empty($element)) {
      throw new Exception('Page not found');
    }

    // Go to the user login page.
    $this->getSession()->visit($this->locatePath('/user/login'));

    // If I see this, I'm not logged in at all so log the user in.
    $element->fillField('Username', $username);
    $element->fillField('Password', $passwd);
    $submit = $element->findButton('Log in');
    if (empty($submit)) {
      throw new Exception('No submit button at ' . $this->getSession()->getCurrentUrl());
    }

    // Log in.
    $submit->click();
    $user = $this->getSession()->getPage()->find('css', '.title')->getText();
    if (strtolower($user) != strtolower($username)) {
      throw new Exception('Could not log user in.');
    }

    // Successfully logged in.
    return;
  }

  /**
   * @Given /^I upload an image to media$/
   */
  public function iUploadAnImageToMedia() {
    $page = $this->getSession()->getPage();
    $page->clickLink("Browse");
    $iframe = $page->find('css', '#mediaBrowser');

    if ( empty($iframe) ) {
      throw new Exception("Media iframe not found");
    } else {
      $this->getSession()->switchToIFrame("mediaBrowser");
    }

    if ($this->getMinkParameter('files_path')) {
      $fullPath = rtrim(realpath($this->getMinkParameter('files_path')), DIRECTORY_SEPARATOR) . DIRECTORY_SEPARATOR . "themes/zen_oc/zen-oc/screenshot.png";
    } else {
      throw new Exception("Cannot find files_path");
    }

    if ( is_file($fullPath) ) {
      $page->attachFileToField("files[upload]", $fullPath);
    } else {
      throw new Exception("The sample file cannot be found at " . $fullPath);
    }

    $page->pressButton("edit-upload-upload-button");
    $page->pressButton("edit-next");
    $page->pressButton("edit-submit");
    $this->getSession()->switchToIFrame();

    if ( empty($page->find('css', '.media-thumbnail img')) ) {
      throw new Exception("Image not uploaded!");
    }

    $page->pressButton("edit-submit");
  }

  /**
   * @When /^I (?:follow|click) the "(?P<region>[^"]*)"(?:| region)$/
   *
   * @throws \Exception
   *   If region cannot be found.
   */
  public function assertRegionFollow($region) {
    $regionObj = $this->getRegion($region);
    $regionObj->click();
  }

  /**
   * @Then /^I (?:should |)see a title containing "([^"]*)"$/
   */
  public function iShouldSeeATitleContaining($title) {
    $element = $this->getSession()->getPage()->find('css', 'title');

    if ( empty($element) ) {
      throw new Exception("The page title was not found!");
    }

    if ( strpos($element->getText(), $title) === FALSE ) {
      throw new Exception("The page title does not contain '" . $title . "'!");
    }
  }

  /**
   * @Then /^I (?:should |)(not |)?see the following <texts>$/
   */
  public function iShouldSeeTheFollowingTexts($negate = FALSE, TableNode $table) {
    $negate = $negate ? TRUE : FALSE;
    $page = $this->getSession()->getPage();
    $table = $table->getHash();
    foreach ($table as $key => $value) {
      $text = $table[$key]['texts'];
      if ( $page->hasContent($text) === $negate ) {
        throw new Exception("The text '" . $text . "' was" . ($negate ? " " : " not") . " found");
      }
    }
  }

  /**
   * @Then /^I (?:should |)(not |)?see the "([^"]*)" element$/
   */
  public function iShouldSeeTheElement($negate = FALSE, $element) {
    $negate = $negate ? TRUE : FALSE;
    $element = $this->getSession()->getPage()->find('css', $element);

    if ( empty($element) && !$negate ) {
      throw new Exception("The element was not found!");
    }

    if ( !empty($element) && $negate ) {
      throw new Exception("The element was found!");
    }
  }

  /**
   * @Then /^I (?:should |)(not |)?see the "([^"]*)" element inside the "([^"]*)" element$/
   */
  public function iShouldSeeTheElementInsideTheElement($child, $parent) {
    $parentElement = $this->getSession()->getPage()->find('css', $parent);

    if ( empty($parentElement) ) {
      throw new Exception("The parent element '" . $parent . "' was not found!");
    }

    $childElement = $parentElement->find('css', $child);

    if ( empty($childElement) ) {
      throw new Exception("The element '" . $child . "' was not found inside '" . $parent . "'!");
    }
  }

  /**
   * @Then /^I (?:should |)(not |)?see the following <links>$/
   */
  public function iShouldSeeTheFollowingLinks($negate = FALSE, TableNode $table) {
    $negate = $negate ? TRUE : FALSE;
    $page = $this->getSession()->getPage();
    $table = $table->getHash();
    foreach ($table as $key => $value) {
      $link = $table[$key]['links'];
      $result = $page->findLink($link);
      if( empty($result) !== $negate ) {
        throw new Exception("The link '" . $link . "' was" . ($negate ? " " : " not ") . "found");
      }
    }
  }

  /**
   * Function to check if the field specified is outlined in red or not
   *
   * @Then /^the field "([^"]*)" should be outlined in red$/
   *
   * @param string $field
   *   The form field label to be checked.
   */
  public function theFieldShouldBeOutlinedInRed($field) {
    $page = $this->getSession()->getPage();
    // get the object of the field
    $formField = $page->findField($field);
    if (empty($formField)) {
      throw new Exception('The page does not have the field with label "' . $field . '"');
    }
    // get the 'class' attribute of the field
    $class = $formField->getAttribute("class");
    // we get one or more classes with space separated. Split them using space
    $class = explode(" ", $class);
    // if the field has 'error' class, then the field will be outlined with red
    if (!in_array("error", $class)) {
      throw new Exception('The field "' . $field . '" is not outlined with red');
    }
  }

  /**
   * Find a region on the page.
   *
   * @Then /^I should see the "(?P<region>[^"]*)"(?:| region)$/
   *
   * @throws \Exception
   *   If region cannot be found.
   */
  public function assertRegion($region) {
    $regionObj = $this->getRegion($region);
  }

  /**
   * @Then /^the metatag attribute "(?P<attribute>[^"]*)" should have the value "(?P<value>[^"]*)"$/
   *
   * @throws \Exception
   *   If region or link within it cannot be found.
   */
  public function assertMetaRegion($metatag, $value) {
    $this->assertMetaRegionGeneric('name', $metatag, $value);
  }

  /**
   * @Then /^the metatag property "(?P<attribute>[^"]*)" should have the value "(?P<value>[^"]*)"$/
   *
   * @throws \Exception
   *   If region or link within it cannot be found.
   */
  public function assertMetaRegionProperty($metatag, $value) {
    $this->assertMetaRegionGeneric('property', $metatag, $value);
  }

  /**
   * Take screenshot when step fails. Works only with Selenium2Driver.
   *
   * If on a Mac, runnining from the command line, with the SHOW_SNAPSHOT
   *  environment variable set to 1, the snapshot will open in Preview.
   *
   * Screenshot is saved at [Date]/[Feature]/[Scenario]/[Step].jpg .
   *
   * @AfterStep @javascript
   */
  public function takeScreenshotAfterFailedStep(Behat\Behat\Event\StepEvent $event) {
    if ($event->getResult() === Behat\Behat\Event\StepEvent::FAILED) {
      $driver = $this->getSession()->getDriver();
      if ($driver instanceof Behat\Mink\Driver\Selenium2Driver) {
        $step = $event->getStep();
        $path = array(
          'date' => date("Ymd-Hi"),
          'feature' => $step->getParent()->getFeature()->getTitle(),
          'scenario' => $step->getParent()->getTitle(),
          'step' => $step->getType() . ' ' . $step->getText(),
        );
        $path = preg_replace('/[^\-\.\w]/', '_', $path);
        $filename = '/tmp/behat/' .  implode('/', $path) . '.jpg';

        // Create directories if needed.
        if (!@is_dir(dirname($filename))) {
          @mkdir(dirname($filename), 0775, TRUE);
        }

        file_put_contents($filename, $driver->getScreenshot());
        if (PHP_OS === "Darwin" && (bool) getenv('SHOW_SNAPSHOT') === TRUE && PHP_SAPI === "cli") {
          exec('open -a "Preview.app" ' . $filename);
        }
      }
    }
  }

}
