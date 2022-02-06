/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.grammar.adhoc;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import org.perses.PersesConstants;
import org.perses.util.cmd.AbstractMain;

public class InstallerMain extends AbstractMain<CommandOptions> {

  public InstallerMain(String[] args) {
    super(args);
  }

  @Override
  protected CommandOptions createCommandOptions() {
    return new CommandOptions();
  }

  @Override
  protected void internalRun() {
    final PersesConstants persesConstants;
    if (cmd.outputFlags.getOutput() != null) {
      try {
        // FIXME: here is a resource leak.
        final Path tempDir = Files.createTempDirectory(InstallerMain.class.getCanonicalName());
        persesConstants = PersesConstants.createCustomizedConstants(tempDir);
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    } else {
      persesConstants = PersesConstants.createDefaultConstants();
    }

    new AdhocGrammarInstaller(cmd, persesConstants).run();
  }

  @Override
  protected HelpRequestProcessingDecision processHelpRequests() {
    if (cmd.outputFlags.getPrintLanguageKindExample()) {
      System.out.println("An example of a language kind configuration in YAML format.");
      System.out.println(LanguageAdhoc.INSTANCE.toYamlString());
      return HelpRequestProcessingDecision.EXIT;
    }
    return super.processHelpRequests();
  }

  public static void main(String[] args) {
    new InstallerMain(args).run();
  }
}
