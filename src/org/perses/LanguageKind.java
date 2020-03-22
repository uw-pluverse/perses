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
import com.google.common.io.Files;

import java.io.File;

/** Infer the programming language for a source file based on its file extension. */
public enum LanguageKind {
  C(ImmutableList.of("c"), FormatSensitivity.INSENSITIVE),
  SCALA(ImmutableList.of("scala", "sc"), FormatSensitivity.SENSITIVE),
  GO(ImmutableList.of("go"), FormatSensitivity.SENSITIVE),
  JAVA(ImmutableList.of("java"), FormatSensitivity.INSENSITIVE),
  UNKNOWN(ImmutableList.of(), FormatSensitivity.SENSITIVE);

  private static ImmutableMap<String, LanguageKind> EXTENSION_MAP;

  static {
    final ImmutableMap.Builder<String, LanguageKind> builder = ImmutableMap.builder();
    for (LanguageKind kind : LanguageKind.values()) {
      kind.extensions.forEach(ext -> builder.put(ext, kind));
    }
    EXTENSION_MAP = builder.build();
  }

  private final ImmutableList<String> extensions;
  private final boolean formatSensitive;

  LanguageKind(ImmutableList<String> extensions, boolean formatSensitive) {
    this.extensions = extensions;
    this.formatSensitive = formatSensitive;
  }

  public boolean isFormatSensitive() {
    return formatSensitive;
  }

  public static LanguageKind computeLanguageKind(File file) {
    final String ext = Files.getFileExtension(file.getName());
    final LanguageKind kind = EXTENSION_MAP.get(ext);
    return kind == null ? UNKNOWN : kind;
  }

  private static class FormatSensitivity {
    private static final boolean SENSITIVE = true;
    private static final boolean INSENSITIVE = false;
  }
}
