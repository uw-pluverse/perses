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
package org.perses.reduction

import org.perses.program.LanguageKind
import org.perses.program.TokenizedProgram
import org.perses.reduction.cache.AbstractQueryCache
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.spartree.AbstractNodeActionSetCache
import org.perses.spartree.SparTreeNodeFactory

class ReducerContext(
  ioManager: TokenReductionIOManager,
  val configuration: ReductionConfiguration,
  executorService: TestScriptExecutorService,
  val listenerManager: AsyncReductionListenerManager,
  val queryCache: AbstractQueryCache,
  val nodeActionSetCache: AbstractNodeActionSetCache,
  val actionSetProfiler: AbstractActionSetProfiler,
  val sparTreeNodeFactory: SparTreeNodeFactory,
) : AbstractReducerContext<TokenizedProgram, LanguageKind, TokenReductionIOManager, ReducerContext>(
  ioManager,
  executorService,
)
