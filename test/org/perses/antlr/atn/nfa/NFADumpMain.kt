/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.antlr.atn.nfa

import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.antlr.atn.OrigCLexer
import org.perses.util.Util
import java.nio.file.Paths
import kotlin.io.path.absolute
import kotlin.io.path.bufferedWriter

object NFADumpMain {

  @JvmStatic
  fun main(args: Array<String>) {
    require(args.size == 1)
    val outputFile = Paths.get(args.single()).absolute()
    Util.ensureDirExists(outputFile.parent)
    val atn = LexerAtnWrapper(OrigCLexer::class.java)
    outputFile.bufferedWriter().use { stream ->
      atn.metaTokenInfoDB.asSequence()
        .map { token ->
          Pair(token, MutableNFA.copyOf(atn.getOriginalStartState(token.tokenType)))
        }.forEach { (token, nfa) ->
          stream.append("Token: ${token.symbolicName}").append('\n')
          stream.append(nfa.printTopology()).append('\n')
        }
    }
  }
}
