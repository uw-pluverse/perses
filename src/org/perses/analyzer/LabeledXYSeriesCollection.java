/*
 * Copyright (C) 2018-2020 University of Waterloo.
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

package org.perses.analyzer;

import org.jfree.chart.labels.XYItemLabelGenerator;
import org.jfree.data.xy.XYDataset;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;

import java.util.ArrayList;
import java.util.List;

public class LabeledXYSeriesCollection {

  private final XYSeriesCollection collection;

  private final XYSeries series;

  private final List<String> labels;

  public LabeledXYSeriesCollection(String seriesName) {
    this.collection = new XYSeriesCollection();
    this.series = new XYSeries(seriesName);
    this.collection.addSeries(this.series);
    this.labels = new ArrayList<>();
  }

  public void add(double x, double y, String label) {
    this.series.add(x, y);
    this.labels.add(label);
  }

  public XYItemLabelGenerator createLabelGenerator() {
    return new XYItemLabelGenerator() {
      @Override
      public String generateLabel(XYDataset dataset, int series, int item) {
        return labels.get(item);
      }
    };
  }

  public XYSeriesCollection getCollection() {
    return collection;
  }
}
