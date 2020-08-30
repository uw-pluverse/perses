package org.perses.version;

import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableMap;
import com.google.common.io.Files;

import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

public class VersionClassGenerator {

  private static final String MAJOR_VERSION = "1";
  private static final String MINOR_VERSION = "1";

  public static void main(String[] args) throws IOException {
    Preconditions.checkArgument(args.length == 2);
    final ImmutableList<String> lines =
        Files.asCharSource(new File(args[0]), StandardCharsets.UTF_8).readLines();
    final ImmutableMap<String, String> map = parse(lines);

    final File outputFile = new File(args[1]);
    writeVersionClass(map, outputFile);
  }

  private static void writeVersionClass(ImmutableMap<String, String> map, File outputFile)
      throws IOException {
    final String branch = map.get("PERSES_GIT_BRANCH");
    final String hash = map.get("PERSES_GIT_COMMIT_HASH");
    final String status = map.get("PERSES_GIT_STATUS");
    try (BufferedWriter writer = Files.newWriter(outputFile, StandardCharsets.UTF_8)) {
      line(writer, "package org.perses.version");
      line(writer, "object Version {");
      line(writer, "  val BRANCH=\"%s\"", branch);
      line(writer, "  val COMMIT_HASH=\"%s\"", hash);
      line(writer, "  val STATUS=\"%s\"", status);
      line(writer, "  val MAJOR_VERSION=\"%s\"", MAJOR_VERSION);
      line(writer, "  val MINOR_VERSION=\"%s\"", MINOR_VERSION);
      line(writer, "}");
    }
  }

  private static void line(BufferedWriter writer, String template, String... args)
      throws IOException {
    writer.append(String.format(template, args)).append("\n");
  }

  private static ImmutableMap<String, String> parse(ImmutableList<String> lines) {
    final ImmutableMap.Builder<String, String> builder = ImmutableMap.builder();
    for (String line : lines) {
      String[] segments = line.split("\\s|=");
      Preconditions.checkState(segments.length == 2);
      builder.put(segments[0].trim(), segments[1].trim());
    }
    return builder.build();
  }
}
