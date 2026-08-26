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
package org.perses.reduction.reducer.sfc

/**
 * How many structures a hole of a [RuleAlternativeTemplate] is filled with.
 *
 * These are the quantifiers a grammar spells, plus [EXACTLY_ONE] for an unquantified symbol,
 * which is why the grammar layer's own enums (`AstTag`, `RuleType`) are not reused here: neither
 * has a member for the unquantified case.
 */
enum class Quantifier(
  /** How the quantifier is spelled in a grammar, and in [TemplateElement.Hole.toString]. */
  val suffix: String,
) {
  /** The symbol carries no quantifier, so the hole takes exactly one structure. */
  EXACTLY_ONE(""),

  /** `?`: the hole takes one structure, or stays empty. */
  OPTIONAL("?"),

  /** `*`: the hole takes every reusable structure at once, or stays empty. */
  STAR("*"),

  /** `+`: the hole takes every reusable structure at once, and cannot stay empty. */
  PLUS("+"),
}
