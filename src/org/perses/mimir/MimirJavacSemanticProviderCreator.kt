/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.mimir

import org.perses.mimir.lsp.JavacDependencyAnalyzer
import org.perses.mimir.lsp.LspSemanticToken
import org.perses.util.AutoDeletableFolder
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.name
import kotlin.io.path.nameWithoutExtension

/**
 * A semantics provider creator that uses the Javac Compiler Tree API to extract def-use info.
 */
class MimirJavacSemanticProviderCreator : AbstractMimirSemanticProviderCreator() {
  override fun computeDefUseMap(
    sourceFilePath: Path,
  ): Map<LspSemanticToken, List<LspSemanticToken>> =
    if (sourceFilePath.name.endsWith(".java")) {
      JavacDependencyAnalyzer(sourceFilePath).defUseMap
    } else {
      AutoDeletableFolder.createTempDir(this::class.simpleName!!).use {
        val target = it.file.resolve(sourceFilePath.nameWithoutExtension + ".java")
        Files.copy(sourceFilePath, target)
        JavacDependencyAnalyzer(target).defUseMap
      }
    }
}
