/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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
package org.perses;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableMap;
import com.google.common.collect.Iterators;
import com.google.common.io.Files;
import org.perses.program.EnumFormatControl;

import java.io.File;
import java.util.HashSet;

import static com.google.common.base.Preconditions.checkState;

/** Infer the programming language for a source file based on its file extension. */
public enum LanguageKind {
  C(
      ImmutableList.of("c"),
      EnumFormatControl.SINGLE_TOKEN_PER_LINE,
      EnumFormatControl.ORIG_FORMAT,
      EnumFormatControl.COMPACT_ORIG_FORMAT),
  SCALA(
      ImmutableList.of("scala", "sc"),
      EnumFormatControl.COMPACT_ORIG_FORMAT,
      EnumFormatControl.ORIG_FORMAT),
  GO(ImmutableList.of("go"), EnumFormatControl.COMPACT_ORIG_FORMAT, EnumFormatControl.ORIG_FORMAT),
  JAVA(
      ImmutableList.of("java"),
      EnumFormatControl.SINGLE_TOKEN_PER_LINE,
      EnumFormatControl.ORIG_FORMAT,
      EnumFormatControl.COMPACT_ORIG_FORMAT),
  RUST(
      ImmutableList.of("rs"), EnumFormatControl.COMPACT_ORIG_FORMAT, EnumFormatControl.ORIG_FORMAT),
  UNKNOWN(ImmutableList.of(), EnumFormatControl.ORIG_FORMAT);

  private static ImmutableMap<String, LanguageKind> EXTENSION_MAP;

  static {
    final ImmutableMap.Builder<String, LanguageKind> builder = ImmutableMap.builder();
    for (LanguageKind kind : LanguageKind.values()) {
      kind.extensions.forEach(ext -> builder.put(ext, kind));
    }
    EXTENSION_MAP = builder.build();
  }

  private final ImmutableList<String> extensions;
  private final ImmutableList<EnumFormatControl> allowedCodeFormats;

  LanguageKind(
      ImmutableList<String> extensions,
      EnumFormatControl defaultFormat,
      EnumFormatControl... otherFormats) {
    this.extensions = extensions;
    this.allowedCodeFormats =
        ImmutableList.<EnumFormatControl>builder()
            .add(defaultFormat)
            .addAll(Iterators.forArray(otherFormats))
            .build();
    checkState(new HashSet<>(allowedCodeFormats).size() == allowedCodeFormats.size());
  }

  public EnumFormatControl getDefaultCodeFormatControl() {
    return allowedCodeFormats.get(0);
  }

  public boolean isCodeFormatAllowed(EnumFormatControl codeFormat) {
    return allowedCodeFormats.contains(codeFormat);
  }

  public static LanguageKind computeLanguageKind(File file) {
    final String ext = Files.getFileExtension(file.getName());
    final LanguageKind kind = EXTENSION_MAP.get(ext);
    return kind == null ? UNKNOWN : kind;
  }
}
