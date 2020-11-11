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
package org.perses.reduction;

import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.CommandOptions;
import org.perses.grammar.ParserFacadeFactory;

@RunWith(JUnit4.class)
public class ReductionDriverTest {

  @Test
  public void testCreateConfiguration() {
    CommandOptions cmd = new CommandOptions(ReducerFactory.getDefaultReductionAlgName());
    cmd.compulsoryFlags.inputFile = "t.c";
    cmd.compulsoryFlags.testScript = "r.sh";
    try {
      ReductionDriver.createConfiguration(cmd, ParserFacadeFactory.builderWithBuiltinLanguages().build());
    } catch (RuntimeException e) {
      // Keep this. This is just capture a bug when only "t.c" and "r.sh" were given without parent
      // folders.
      Truth.assertThat(e.getMessage()).contains("The file should be a regular file");
    }
  }
}
