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
package org.perses.grammar.c;

import com.google.common.io.Files;
import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

@RunWith(JUnit4.class)
public class PnfCParserFacadeTest {

  @Test
  public void testGoldenPnfCGrammar() throws IOException {
    PnfCParserFacade facade = new PnfCParserFacade();
    String content = facade.getAntlrGrammar().asCombined().getGrammar().getSourceCode();
    String golden =
        Files.asCharSource(
                new File("test/org/perses/grammar/c/golden_pnf_c.g4"), StandardCharsets.UTF_8)
            .read();
    Truth.assertThat(content).isEqualTo(golden);
  }
}
