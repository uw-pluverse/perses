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
package org.perses.fuzzer;

import com.google.common.collect.ImmutableList;
import java.io.IOException;
import org.perses.fuzzer.compilers.AbstractCompilerConfigurationFacade;
import org.perses.util.cmd.AbstractMain;
import org.perses.util.cmd.CommandLineProcessor;

public class Main extends AbstractMain<CommandOptions> {

  private ImmutableList<AbstractCompilerConfigurationFacade> facades;

  public Main(CommandOptions cmd) {
    super(cmd);
  }

  @Override
  protected void internalRun() {
    try (FuzzerDriver driver =
        new FuzzerDriver(
            getCmd(),
            new AdditionalFuzzerControl(getCmd().generalFlags.maxNumberOfTestingIterations))) {
      facades = driver.getFacades();
      driver.run();
    }
  }

  public ImmutableList<AbstractCompilerConfigurationFacade> getFacades() {
    return facades;
  }

  public static void main(String[] args) throws IOException {
    CommandLineProcessor<CommandOptions> processor =
        new CommandLineProcessor<>(CommandOptions::new, Main.class.getCanonicalName(), args);
    if (processor.process() == CommandLineProcessor.HelpRequestProcessingDecision.EXIT) {
      return;
    }
    new Main(processor.getCmd()).run();
  }
}
