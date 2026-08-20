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
package org.perses.analyzer.sizetrend

import com.fasterxml.jackson.annotation.JsonProperty
import com.fasterxml.jackson.annotation.JsonPropertyOrder
import com.fasterxml.jackson.dataformat.csv.CsvMapper
import com.fasterxml.jackson.module.kotlin.kotlinModule
import java.nio.file.Path

@JsonPropertyOrder("elapsed_seconds", "current_program_size", "action_description")
data class Snapshot(
  @field:JsonProperty("elapsed_seconds")
  val elapsedSeconds: Int,
  @field:JsonProperty("current_program_size")
  val currentProgramSize: Int,
  @field:JsonProperty("action_description")
  val actionDescription: String,
) {
  fun isFixpointIterationEnd(): Boolean = actionDescription.contains("Fixpoint Iteration End")
}

class SizeTrendDataManager {
  private val mapper =
    CsvMapper().apply {
      registerModule(kotlinModule())
    }
  private val schema = mapper.schemaFor(Snapshot::class.java).withHeader()

  fun loadSnapshots(path: Path): List<Snapshot> =
    mapper
      .readerFor(Snapshot::class.java)
      .with(schema)
      .readValues<Snapshot>(path.toFile())
      .readAll()
}
