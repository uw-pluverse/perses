/*
 * Copyright (C) 2003-2017 Chengnian Sun.
 *
 * This file is part of Perses.
 *
 * Perses is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * Perses is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.
 */

package org.perses;

import com.beust.jcommander.JCommander;
import com.google.common.base.Preconditions;
import org.antlr.runtime.RecognitionException;
import org.perses.reduction.ReducerFactory;
import org.perses.reduction.ReductionDriver;

import java.io.IOException;
import java.io.InputStream;
import java.util.concurrent.ExecutionException;
import java.util.logging.LogManager;

public class Main {

  static {
    try (InputStream stream = Main.class.getResourceAsStream("/org/perses/logging.properties")) {
      LogManager.getLogManager().readConfiguration(stream);
    } catch (IOException e) {
      System.err.println("fail to customize the logging message. " + e);
      e.printStackTrace();
    }
  }

  public static void main(String[] args)
      throws IOException, ExecutionException, InterruptedException {
    final CommandOptions cmd = new CommandOptions(ReducerFactory.getDefaultReductionAlgName());
    final JCommander commander = cmd.createCommander(Main.class);
    commander.parse(args);
    if (cmd.help) {
      commander.usage();
      return;
    }

    if (cmd.isListAllReductionAlgorithms()) {
      System.out.println("All available reduction algorithms: ");
      System.out.println(ReducerFactory.printAllReductionAlgorithms());
      return;
    }

    if (cmd.countTokens) {

      return;
    }

    cmd.validate();

    Preconditions.checkState(
        ReducerFactory.isValidReducerName(cmd.getReductionAlgorithmName()),
        "Invalid reduction algorithm %s",
        cmd.getReductionAlgorithmName());

    try (ReductionDriver driver = new ReductionDriver(cmd)) {
      driver.reduce();
    }
  }
}
