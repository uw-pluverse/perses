package org.perses.listener;

import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import java.io.File;

@RunWith(JUnit4.class)
public class TestScriptExecutionListenerTest {

  @Test
  public void testResultFileIsAbsolute() {
    File file = new File("__this_file_should_not_exist__");
    try {
      new TestScriptExecutionListener(file);
    } catch (NullPointerException e) {
      Assert.fail();
    } catch (IllegalArgumentException e) {
      // Swallow.
    }
  }
}
