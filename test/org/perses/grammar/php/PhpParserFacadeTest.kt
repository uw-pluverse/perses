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
package org.perses.grammar.php

import com.google.common.truth.Truth
import org.junit.Ignore
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility

@RunWith(JUnit4::class)
class PhpParserFacadeTest {
  private val facade = PhpParserFacade()

  @Ignore
  @Test
  fun test() {
    val program =
      """
      <?php
      echo "start", "\n";
      echo "hello world", "\n";
      echo "finish", "\n";
      ?>
      """.trimIndent()
    val origParseTree = facade.parseWithOrigParser(program)
    val origTokens = TestUtility.extractTokenTexts(origParseTree.tree)
    Truth.assertThat(origTokens).isEmpty()
  }

  @Test
  fun testRoundTripParser() {
    val program =
      arrayOf(
        """
<?php
(function() {
    ob_start();
    echo "<p>ok</p>";
    echo ob_get_clean();
})();
?>
        """.trimIndent(),
        """
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Example</title>
</head>
<body>
  <p><?php echo date("Y-m-d H:i:s"); ?></p>
</body>
</html>
        """.trimIndent(),
        """
<?php
echo "<!DOCTYPE html>";
echo "<html><body>";
if (date("H") < 12) {
    echo "hi";
} else {
    echo "hello";
}
echo "</body></html>";
?>
        """.trimIndent(),
      )
    for (prog in program) {
      val origParseTree = facade.parseWithOrigParser(prog)
      val origTokens = TestUtility.extractTokenTexts(origParseTree.tree)
      val joined = origTokens.joinToString(separator = "")
      val normalizedProgram = prog.replace(Regex("\\s+"), "")
      val normalizedJoined = joined.replace(Regex("\\s+"), "")

      Truth.assertThat(normalizedJoined).isEqualTo(normalizedProgram)
    }
  }
}
