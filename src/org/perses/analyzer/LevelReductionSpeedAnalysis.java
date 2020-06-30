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

import com.google.common.base.Preconditions;
import com.google.common.flogger.FluentLogger;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartUtils;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.XYPlot;
import org.jfree.chart.renderer.xy.XYItemRenderer;
import org.perses.PersesRuntimeException;
import org.perses.listener.IProfileEvent;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/** Created by neo on 12/26/16. */
public class LevelReductionSpeedAnalysis extends AbstractHddPerformanceAnalysis {
  private static final FluentLogger logger = FluentLogger.forEnclosingClass();

  public LevelReductionSpeedAnalysis(File eventFile) {
    super(eventFile);
  }

  public static void main(String[] args) {
    if (args.length != 1) {
      System.err.println("Usage: <main> <event binary file>");
      System.exit(1);
    }

    final File eventFile = new File(args[0]);
    if (!eventFile.exists() || !eventFile.isFile()) {
      System.err.println("The event file does not exist: " + eventFile);
      System.exit(1);
    }
    new LevelReductionSpeedAnalysis(eventFile).analyze();
  }

  private void exportChart(JFreeChart chart, String fileNameSuffix) {
    try {
      File file =
          new File(
              this.eventFile.getParentFile(), this.eventFile.getName() + fileNameSuffix + ".jpg");
      logger.atInfo().log("Exporting chart to %s", file);
      ChartUtils.saveChartAsJPEG(file, chart, 1920, 1080);
    } catch (IOException e) {
      throw new PersesRuntimeException(e);
    }
  }

  private JFreeChart createChart(
      String title,
      String xTitle,
      String yTitle,
      String seriesName,
      LabeledXYSeriesCollection dataset) {
    //    final XYChart chart = new XYChart(1920, 1080);
    //    ChartFactory.createLineChart(title, xTitle, yTitle) chart.setTitle
    // (title);

    JFreeChart chart =
        ChartFactory.createXYLineChart(title, xTitle, yTitle, dataset.getCollection());
    final XYPlot plot = chart.getXYPlot();
    //    plot.addDomainMarker(new ValueMarker());
    final XYItemRenderer renderer = plot.getRenderer();
    renderer.setDefaultItemLabelGenerator(dataset.createLabelGenerator());
    renderer.setDefaultItemLabelsVisible(true);

    return chart;
  }
  //
  //  private void exportLevelProgramSizeChart(List<IProfileEvent
  //          .LevelReductionEvent> starts, List<IProfileEvent
  //          .LevelReductionEvent> ends) {
  //    final int tokenCount = starts.tokenCount();
  //    final double[] xData = new double[tokenCount + 1];
  //    final double[] yData = new double[tokenCount + 1];
  //    long startTime = 0;
  //    for (int i = 0; i < tokenCount; ++i) {
  //      if (i == 0) {
  //        final IProfileEvent.LevelReductionEvent start = starts.get(i);
  //        startTime = start.getTimeInMilliseconds();
  //        xData[0] = 0;
  //        yData[0] = start.getProgramSize();
  //      }
  //      final IProfileEvent.LevelReductionEvent end = ends.get(i);
  //      xData[i + 1] = end.getLevel();
  //      yData[i + 1] = end.getProgramSize();
  //    }
  //    final XYChart chart = this.createChart("Level Reduction Rate",
  // "Levels ",
  //            "Program Size (tokens)", "Level Reduction Speed", xData, yData);
  //
  //    this.exportChart(chart, "-level-reduction-rate-over-level");
  //  }

  private void exportTimeProgramSizeChart(
      List<IProfileEvent.LevelReductionEvent> starts,
      List<IProfileEvent.LevelReductionEvent> ends) {
    logger.atInfo().log("Generating chart of time-program-tokenCount relation.");
    final int size = starts.size();
    final LabeledXYSeriesCollection dataset =
        new LabeledXYSeriesCollection("Level Reduction Speed");
    long startTime = 0;
    for (int i = 0; i < size; ++i) {
      if (i == 0) {
        final IProfileEvent.LevelReductionEvent start = starts.get(i);
        startTime = start.getTimeInMilliseconds();
        dataset.add(0, start.getProgramSize(), "L0");
      }
      final IProfileEvent.LevelReductionEvent end = ends.get(i);
      dataset.add(
          (end.getTimeInMilliseconds() - startTime) / 1000,
          end.getProgramSize(),
          "L" + end.getLevel());
    }

    final JFreeChart chart =
        this.createChart(
            "Level Reduction Rate",
            "Time " + "(seconds)",
            "Program Size (tokens)",
            "Level Reduction Speed",
            dataset);

    this.exportChart(chart, "-level-reduction-rate-over_time");
  }

  @Override
  protected void performAnalysis() {
    if (this.events.size() == 0) {
      return;
    }
    logger.atInfo().log("Analyzing data");
    final List<IProfileEvent.LevelReductionEvent> starts = new ArrayList<>();
    final List<IProfileEvent.LevelReductionEvent> ends = new ArrayList<>();
    for (IProfileEvent event : this.events) {
      if (event instanceof IProfileEvent.LevelReductionEvent) {
        final IProfileEvent.LevelReductionEvent levelEvent =
            (IProfileEvent.LevelReductionEvent) event;
        if (levelEvent.isStartEvent()) {
          starts.add(levelEvent);
        } else {
          ends.add(levelEvent);
        }
      }
    }

    Preconditions.checkState(starts.size() == ends.size());
    this.exportTimeProgramSizeChart(starts, ends);
    //    this.exportLevelProgramSizeChart(starts, ends);
  }
}
