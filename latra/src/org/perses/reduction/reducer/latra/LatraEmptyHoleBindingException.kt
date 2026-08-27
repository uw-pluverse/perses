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

/**
 * Thrown when a hole is used for rewriting but is bound to nothing. This is a recoverable
 * state, not a template error: a non-mustMatch global-replace clause that matches nothing
 * deliberately binds its holes to empty lists. It extends [LatraException] so that
 * [FullFunctionalLatraRewriterBuilder.build] abandons the transformation gracefully
 * instead of crashing the reducer.
 */
class LatraEmptyHoleBindingException : LatraException {
  constructor() : super()

  constructor(message: String?) : super(message)

  constructor(message: String?, cause: Throwable?) : super(message, cause)

  constructor(cause: Throwable?) : super(cause)
}
