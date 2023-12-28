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
package org.perses.util

import com.google.common.flogger.FluentLogger
import java.util.logging.Level

inline fun FluentLogger.ktInfo(msg: () -> String) {
  ktAt(Level.INFO, msg)
}

inline fun FluentLogger.ktWarning(msg: () -> String) {
  ktAt(Level.WARNING, msg)
}

inline fun FluentLogger.ktSevere(msg: () -> String) {
  ktAt(Level.SEVERE, msg)
}

inline fun FluentLogger.ktFine(msg: () -> String) {
  ktAt(Level.FINE, msg)
}

inline fun FluentLogger.ktFiner(msg: () -> String) {
  ktAt(Level.FINER, msg)
}

inline fun FluentLogger.ktFinest(msg: () -> String) {
  ktAt(Level.FINEST, msg)
}

inline fun FluentLogger.ktConfig(msg: () -> String) {
  ktAt(Level.CONFIG, msg)
}

inline fun FluentLogger.ktAt(level: Level, msg: () -> String) {
  at(level).ifEnabled { it.log(msg()) }
}

inline fun FluentLogger.Api.ifEnabled(action: (FluentLogger.Api) -> Unit) {
  if (isEnabled) {
    action(this)
  }
}
