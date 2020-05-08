package org.perses.program;

import com.google.common.io.MoreFiles;
import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Paths;

@RunWith(JUnit4.class)
public class SourceFileTest {

  @Test
  public void testSourceFile() throws IOException {
    String pathname = "test_data/delta_1/t.c";
    SourceFile source = new SourceFile(new File(pathname));
    Truth.assertThat(source.getBaseName()).isEqualTo("t.c");
    Truth.assertThat(source.getFileContent())
        .isEqualTo(MoreFiles.asCharSource(Paths.get(pathname), StandardCharsets.UTF_8).read());
    Truth.assertThat(source.getLanguageKind()).isEqualTo(LanguageKind.C);
    Truth.assertThat(source.getFile()).isEqualTo(new File(pathname));
  }
}
