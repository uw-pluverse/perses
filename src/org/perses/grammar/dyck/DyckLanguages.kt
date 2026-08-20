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
package org.perses.grammar.dyck

import com.google.common.collect.ImmutableSet
import org.perses.program.EnumFormatControl
import org.perses.program.LanguageKind

// The Dyck languages differ only in their name; the single extension is the name with dashes turned
// into underscores, and every other trait is shared. Each object keeps its own class name so
// LanguageKind.toString (used by --list-langs / --list-parser-facades) still renders e.g.
// "LanguageBraceDyck{name=dyck-brace, ...}".
sealed class DyckLanguageKind(
  name: String,
) : LanguageKind(
    name = name,
    extensions = ImmutableSet.of(name.replace('-', '_')),
    defaultCodeFormatControl = EnumFormatControl.COMPACT_ORIG_FORMAT,
    origCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
    defaultFormatterCommandCreators = createPotentialCodeFormatterList(),
    allowedCodeFormatControl =
      ImmutableSet.of(
        EnumFormatControl.ORIG_FORMAT,
        EnumFormatControl.COMPACT_ORIG_FORMAT,
      ),
    hidden = true,
  )

object LanguageBraceDyck : DyckLanguageKind("dyck-brace")

object LanguageBraceParenthesisDyck : DyckLanguageKind("dyck-brace-parenthesis")

object LanguageBraceParenthesisBracketDyck : DyckLanguageKind("dyck-brace-parenthesis-bracket")

object LanguagePristineBraceDyck : DyckLanguageKind("pristine-dyck-brace")

object LanguagePristineBraceParenthesisDyck : DyckLanguageKind("pristine-dyck-brace-parenthesis")

object LanguagePristineBraceParenthesisBracketDyck :
  DyckLanguageKind("pristine-dyck-brace-parenthesis-bracket")

object LanguageAdaptiveDyck : DyckLanguageKind("dyck-adaptive")

object LanguagePristineAdaptiveDyck : DyckLanguageKind("pristine-dyck-adaptive")
