/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
import com.google.common.base.Strings;
import org.perses.reduction.ReducerFactory;
import org.perses.reduction.ReductionDriver;
import org.perses.util.DefaultLoggingConfigurations;
import org.perses.version.Version;

public class Main {

  static {
    DefaultLoggingConfigurations.configureLogManager("INFO");
  }

  public static void main(String[] args) {

    final CommandOptions cmd = new CommandOptions(ReducerFactory.getDefaultReductionAlgName());
    final JCommander commander = cmd.createJCommander(Main.class);
    commander.parse(args);
    // This method should be called as early as possible, to avoid triggering initialization of
    // logger objects.
    DefaultLoggingConfigurations.configureLogManager(cmd.verbosityFlags.verbosity.toUpperCase());

    if (cmd.help) {
      commander.usage();
      return;
    }
    if (cmd.verbosityFlags.listVerbosity) {
      DefaultLoggingConfigurations.printAllAllowedLoggingLevels();
      return;
    }

    if (cmd.algorithmControlFlags.listAllReductionAlgorithms) {
      System.out.println("All available reduction algorithms: ");
      System.out.println(ReducerFactory.printAllReductionAlgorithms());
      return;
    }

    if (cmd.version) {
      System.out.println(
          String.format("Perses V%s.%s", Version.getMAJOR_VERSION(), Version.getMINOR_VERSION()));
      if (!Strings.isNullOrEmpty(Version.getCOMMIT_HASH().trim())) {
        System.out.println("Git Version: " + Version.getCOMMIT_HASH());
      }
      if (!Strings.isNullOrEmpty(Version.getBRANCH().trim())) {
        System.out.println("Git Branch: " + Version.getBRANCH());
      }
      if (!Strings.isNullOrEmpty(Version.getSTATUS().trim())) {
        System.out.println("Git Status: " + Version.getSTATUS());
      }
      System.out.println("Built on " + Version.getBUILD_TIME());
      return;
    }

    cmd.validate();

    Preconditions.checkState(
        ReducerFactory.isValidReducerName(cmd.algorithmControlFlags.getReductionAlgorithmName()),
        "Invalid reduction algorithm %s",
        cmd.algorithmControlFlags.getReductionAlgorithmName());

    try (ReductionDriver driver = new ReductionDriver(cmd)) {
      driver.reduce();
    }
  }
}
