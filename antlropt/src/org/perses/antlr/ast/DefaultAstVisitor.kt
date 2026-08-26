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
package org.perses.antlr.ast

// Base for collectors that care about a few node types and ignore the rest. A visitor that must
// handle every node type should extend AbstractAstVisitor directly so a new node type fails to
// compile instead of being silently skipped.
open class DefaultAstVisitor : AbstractAstVisitor() {
  override fun visit(ast: PersesTokenSetAst) {}

  override fun visit(ast: PersesRangeAst) {}

  override fun visit(ast: PersesTerminalAst) {}

  override fun visit(ast: PersesSequenceAst) {}

  override fun visit(ast: PersesPlusAst) {}

  override fun visit(ast: PersesStarAst) {}

  override fun visit(ast: PersesOptionalAst) {}

  override fun visit(ast: PersesNotAst) {}

  override fun visit(ast: PersesLexerCommandAst) {}

  override fun visit(ast: PersesLexerCharSet) {}

  override fun visit(ast: PersesEpsilonAst) {}

  override fun visit(ast: PersesAlternativeBlockAst) {}

  override fun visit(ast: PersesActionAst) {}

  override fun visit(ast: PersesRuleElementOption) {}

  override fun visit(ast: PersesFragmentLexerRuleAst) {}

  override fun visit(ast: PersesParserRuleAst) {}

  override fun visit(ast: PersesLexerRuleAst) {}

  override fun visit(ast: PersesRuleReferenceAst) {}

  override fun visit(ast: PersesRuleElementLabel) {}

  override fun visit(ast: PersesGrammar) {}

  override fun visit(ast: PersesUndefinedRuleElement) {}
}
