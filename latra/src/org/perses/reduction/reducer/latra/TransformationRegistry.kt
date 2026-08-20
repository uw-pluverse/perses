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
package org.perses.reduction.reducer.latra

import com.google.common.collect.ImmutableMap
import org.perses.grammar.c.LanguageC
import org.perses.grammar.rust.LanguageRust
import org.perses.grammar.smtlibv2.LanguageSmtLibV2
import org.perses.grammar.wasm.LanguageWebAssembly
import org.perses.program.AbstractDataKind
import org.perses.reduction.reducer.latra.c.CTransformationList
import org.perses.reduction.reducer.latra.rust.RustTransformationList
import org.perses.reduction.reducer.latra.smt.SmtTransformationList
import org.perses.reduction.reducer.latra.wat.WatCoarseGritTransformationList
import org.perses.reduction.reducer.latra.wat.WatFineGritTransformationList

object TransformationRegistry {
  val coarseGritTransformations: ImmutableMap<AbstractDataKind, AbstractLatraTransformationList> =
    ImmutableMap
      .builder<AbstractDataKind, AbstractLatraTransformationList>()
      .put(LanguageWebAssembly, WatCoarseGritTransformationList)
      .build()

  val findGritTransformations: ImmutableMap<AbstractDataKind, AbstractLatraTransformationList> =
    ImmutableMap
      .builder<AbstractDataKind, AbstractLatraTransformationList>()
      .put(LanguageC, CTransformationList)
      .put(LanguageSmtLibV2, SmtTransformationList)
      .put(LanguageRust, RustTransformationList)
      .put(LanguageWebAssembly, WatFineGritTransformationList)
      .build()
}
