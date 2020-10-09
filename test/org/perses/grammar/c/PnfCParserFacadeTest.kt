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
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class PnfCParserFacadeTest {

  private final PnfCParserFacade facade = new PnfCParserFacade();

  @Test
  public void testGoldenPnfCGrammar() throws IOException {
    String content = facade.getAntlrGrammar().asCombined().getGrammar().getSourceCode();
    String golden =
        Files.asCharSource(
                new File("test/org/perses/grammar/c/golden_pnf_c.g4"), StandardCharsets.UTF_8)
            .read();
    assertThat(content).isEqualTo(golden);
  }

  @Test
  public void testDefaultFormatterCommand() {
    assertThat(facade.getLanguage().getDefaultFormmaterCommand()).isEqualTo("clang-format");
  }
}
