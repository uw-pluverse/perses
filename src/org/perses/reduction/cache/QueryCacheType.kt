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
package org.perses.reduction.cache

enum class QueryCacheType {
  AUTO,
  COMPACT_QUERY_CACHE,
  COMPACT_QUERY_CACHE_FORMAT_SENSITIVE,
  PERSES_FAST_LINEAR_SCAN_NO_COMPRESSION,
  PERSES_LEXEME_ID,
  CONFIG_BASED,
  ORIG_CONTENT_STRING_BASED,
  CONTENT_LEXEME_LIST_BASE,
  CONTENT_SHA512,
  CONTENT_SHA512_FORMAT,
  CONTENT_ZIP,
  RCC_MEM_LIT,
  DISK_CACHE,
}
