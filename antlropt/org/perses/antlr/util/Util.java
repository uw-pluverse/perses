package org.perses.antlr.util;

import com.google.common.base.Preconditions;

import java.io.File;

public final class Util {

  public static String extractGrammarNameFromGrammarFileName(String fileName) {
    Preconditions.checkState(fileName.endsWith(".g4"));
    final File file = new File(fileName);
    final String name = file.getName();
    return name.substring(0, name.lastIndexOf(".g4"));
  }

}
