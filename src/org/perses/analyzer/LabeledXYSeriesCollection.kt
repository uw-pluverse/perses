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
package org.perses.analyzer

import org.jfree.chart.labels.XYItemLabelGenerator
import org.jfree.data.xy.XYSeries
import org.jfree.data.xy.XYSeriesCollection

class LabeledXYSeriesCollection(seriesName: String?) {
  private val series = XYSeries(seriesName)
  val collection = XYSeriesCollection().apply {
    addSeries(this@LabeledXYSeriesCollection.series)
  }
  private val labels = mutableListOf<String>()

  fun add(x: Double, y: Double, label: String) {
    series.add(x, y)
    labels.add(label)
  }

  fun createLabelGenerator(): XYItemLabelGenerator {
    return XYItemLabelGenerator { _, _, item -> labels[item] }
  }
}
