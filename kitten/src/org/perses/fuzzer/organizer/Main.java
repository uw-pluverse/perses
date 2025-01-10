/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.fuzzer.organizer;

import com.google.common.base.Preconditions;
import java.io.File;
import org.perses.util.DefaultLoggingConfigurations;
import org.perses.util.cmd.AbstractCommandOptions;

public class Main {

  public static void main(String[] args) {
    DefaultLoggingConfigurations.configureLogManager("INFO");

    final CommandOptions cmd = new CommandOptions();
    final AbstractCommandOptions.CmdUsagePrinter usagePrinter =
        cmd.parseArguments(Main.class.getCanonicalName(), args);

    if (cmd.help) {
      usagePrinter.printUsage();
      return;
    }
    Preconditions.checkArgument(
        cmd.findingFolder.isDirectory(),
        "The finding folder %s does not exist. PWD is %s",
        cmd.findingFolder,
        new File(".").getAbsolutePath());
    new OrganizerDriver(cmd).run();
  }
}
