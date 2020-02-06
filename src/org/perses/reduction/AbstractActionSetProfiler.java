package org.perses.reduction;

import com.google.common.collect.ImmutableList;
import org.perses.tree.spar.ChildHoistingAction;

import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;

public abstract class AbstractActionSetProfiler {

  public static final AbstractActionSetProfiler NULL_PROFILER =
      new AbstractActionSetProfiler() {
        @Override
        public void onReplaceKleeneQualifiedNodeWithKleeneQualifiedChildren(
            ImmutableList<ChildHoistingAction> kleeneReplacements) {}

        @Override
        public void onReplaceNodeWithNearestCompatibleChildren(
            ImmutableList<ChildHoistingAction> replacements) {}
      };

  public abstract void onReplaceKleeneQualifiedNodeWithKleeneQualifiedChildren(
      ImmutableList<ChildHoistingAction> kleeneReplacements);

  public abstract void onReplaceNodeWithNearestCompatibleChildren(
      ImmutableList<ChildHoistingAction> replacements);

  public static final class ActionSetProfiler extends AbstractActionSetProfiler
      implements AutoCloseable {

    private BufferedWriter writer;

    public ActionSetProfiler(File file) throws IOException {
      writer = Files.newBufferedWriter(file.toPath(), StandardCharsets.UTF_8);
      Runtime.getRuntime().addShutdownHook(new Thread(() -> close()));
    }

    @Override
    public void onReplaceKleeneQualifiedNodeWithKleeneQualifiedChildren(
        ImmutableList<ChildHoistingAction> kleeneReplacements) {
      try {
        writer
            .append("onReplaceKleeneQualifiedNodeWithKleeneQualifiedChildren: size=")
            .append(String.valueOf(kleeneReplacements.size()))
            .append('\n');
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    }

    @Override
    public void onReplaceNodeWithNearestCompatibleChildren(
        ImmutableList<ChildHoistingAction> replacements) {
      try {
        writer
            .append("onReplaceNodeWithNearestCompatibleChildren: size=")
            .append(String.valueOf(replacements.size()))
            .append('\n');
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    }

    @Override
    public void close() {
      try {
        BufferedWriter local = writer;
        writer = null;
        if (local != null) {
          local.close();
        }
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    }
  }
}
