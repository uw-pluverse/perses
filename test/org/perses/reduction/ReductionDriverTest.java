package org.perses.reduction;

import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.CommandOptions;

@RunWith(JUnit4.class)
public class ReductionDriverTest {

  @Test
  public void testCreateConfiguration() {
    CommandOptions cmd = new CommandOptions(ReducerFactory.getDefaultReductionAlgName());
    cmd.setSourceFile("t.c");
    cmd.setTestScript("r.sh");
    try {
      ReductionDriver.createConfiguration(cmd);
    } catch (IllegalArgumentException e) {
      // Keep this. This is just capture a bug when only "t.c" and "r.sh" were given without parent
      // folders.
      Truth.assertThat(e.getMessage()).contains("The file should be a regular file");
    }
  }
}
