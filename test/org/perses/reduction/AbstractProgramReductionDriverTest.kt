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

import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.program.EnumFormatControl
import org.perses.reduction.cache.QueryCacheType
import java.lang.IllegalArgumentException

@RunWith(JUnit4::class)
class AbstractProgramReductionDriverTest {

  @Test
  fun testComputeQueryCacheType() {
    AbstractProgramReductionDriver.computeQueryCacheType(
      QueryCacheType.AUTO,
      EnumFormatControl.SINGLE_TOKEN_PER_LINE,
    ).let {
      assertThat(it).isEqualTo(QueryCacheType.COMPACT_QUERY_CACHE)
    }

    AbstractProgramReductionDriver.computeQueryCacheType(
      QueryCacheType.AUTO,
      EnumFormatControl.ORIG_FORMAT,
    ).let {
      assertThat(it).isEqualTo(QueryCacheType.COMPACT_QUERY_CACHE_FORMAT_SENSITIVE)
    }

    AbstractProgramReductionDriver.computeQueryCacheType(
      QueryCacheType.AUTO,
      EnumFormatControl.COMPACT_ORIG_FORMAT,
    ).let {
      assertThat(it).isEqualTo(QueryCacheType.COMPACT_QUERY_CACHE_FORMAT_SENSITIVE)
    }

    AbstractProgramReductionDriver.computeQueryCacheType(
      QueryCacheType.COMPACT_QUERY_CACHE_FORMAT_SENSITIVE,
      EnumFormatControl.COMPACT_ORIG_FORMAT,
    ).let {
      assertThat(it).isEqualTo(QueryCacheType.COMPACT_QUERY_CACHE_FORMAT_SENSITIVE)
    }

    AbstractProgramReductionDriver.computeQueryCacheType(
      QueryCacheType.CONTENT_SHA512,
      EnumFormatControl.SINGLE_TOKEN_PER_LINE,
    ).let {
      assertThat(it).isEqualTo(QueryCacheType.CONTENT_SHA512)
    }

    Assert.assertThrows(IllegalArgumentException::class.java) {
      AbstractProgramReductionDriver.computeQueryCacheType(
        QueryCacheType.COMPACT_QUERY_CACHE_FORMAT_SENSITIVE,
        EnumFormatControl.SINGLE_TOKEN_PER_LINE,
      )
    }.let {
      assertThat(it.message).isEqualTo(
        "Cache type ${QueryCacheType.COMPACT_QUERY_CACHE_FORMAT_SENSITIVE} " +
          "is not compatible with the code format ${EnumFormatControl.SINGLE_TOKEN_PER_LINE}",
      )
    }
  }
}
