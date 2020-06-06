package org.perses.program;

import com.google.common.io.Files;
import com.google.common.truth.Truth;
import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import java.io.File;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.nio.charset.StandardCharsets;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class ScriptFileTest {

  private File tempFile;

  @Before
  public void setup() throws IOException {
    tempFile = File.createTempFile("prefix_for_" + getClass().getSimpleName(), ".sh");
    tempFile.deleteOnExit();
  }

  @After
  public void teardown() {
    tempFile.delete();
  }

  @Test
  public void testEmptyShebangForEmptyFile() {
    write("");
    try {
      assertThat(readShebang()).isEmpty();
      Assert.fail();
    } catch (IllegalStateException e) {
    }
  }

  @Test
  public void testEmptyShebangForNoShebang() {
    write("#");
    try {
      assertThat(readShebang()).isEmpty();
      Assert.fail();
    } catch (IllegalStateException e) {
    }

    write("!");
    try {
      assertThat(readShebang()).isEmpty();
      Assert.fail();
    } catch (IllegalStateException e) {
    }

    write("#\nt");
    try {
      assertThat(readShebang()).isEmpty();
      Assert.fail();
    } catch (IllegalStateException e) {
    }

    write("#!\nt");
    try {
      assertThat(readShebang()).isEmpty();
      Assert.fail();
    } catch (IllegalStateException e) {
    }
  }

  @Test
  public void testShebangWithWhitespacesTrimmed() {
    write("#!/usr/bin/env bash      \na");
    assertThat(readShebang()).isEqualTo("/usr/bin/env bash");
  }

  private String readShebang() {
    return new ScriptFile(tempFile).getShebang();
  }

  private void write(String string) {
    try {
      Files.asCharSink(tempFile, StandardCharsets.UTF_8).write(string);
    } catch (IOException e) {
      throw new UncheckedIOException(e);
    }
  }
}
