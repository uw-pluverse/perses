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

import com.google.common.base.Preconditions
import com.google.common.flogger.FluentLogger
import org.jfree.chart.ChartFactory
import org.jfree.chart.ChartUtils
import org.jfree.chart.JFreeChart
import org.perses.listener.IProfileEvent
import java.io.IOException
import java.io.UncheckedIOException
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths

class LevelReductionSpeedAnalysis(eventFile: Path) : AbstractHddPerformanceAnalysis(eventFile) {
  private fun exportChart(chart: JFreeChart, fileNameSuffix: String) {
    try {
      val file = eventFile
        .parent
        .resolve(eventFile.fileName.toString() + fileNameSuffix + ".jpg")
      logger.atInfo().log("Exporting chart to %s", file)
      ChartUtils.saveChartAsJPEG(file.toFile(), chart, 1920, 1080)
    } catch (e: IOException) {
      throw UncheckedIOException(e)
    }
  }

  private fun createChart(
    title: String,
    xTitle: String,
    yTitle: String,
    seriesName: String,
    dataset: LabeledXYSeriesCollection,
  ): JFreeChart {
    //    final XYChart chart = new XYChart(1920, 1080);
    //    ChartFactory.createLineChart(title, xTitle, yTitle) chart.setTitle
    // (title);
    val chart = ChartFactory.createXYLineChart(
      title + seriesName,
      xTitle,
      yTitle,
      dataset.collection,
    )
    val plot = chart.xyPlot
    //    plot.addDomainMarker(new ValueMarker());
    val renderer = plot.renderer
    renderer.defaultItemLabelGenerator = dataset.createLabelGenerator()
    renderer.defaultItemLabelsVisible = true
    return chart
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
  private fun exportTimeProgramSizeChart(
    starts: List<IProfileEvent.LevelReductionEvent>,
    ends: List<IProfileEvent.LevelReductionEvent>,
  ) {
    logger.atInfo().log("Generating chart of time-program-tokenCount relation.")
    val size = starts.size
    val dataset = LabeledXYSeriesCollection("Level Reduction Speed")
    var startTime: Long = 0
    for (i in 0 until size) {
      if (i == 0) {
        val start = starts[i]
        startTime = start.timeInMilliseconds
        dataset.add(0.0, start.programSize.toDouble(), "L0")
      }
      val end = ends[i]
      dataset.add(
        (
          (end.timeInMilliseconds - startTime) / 1000
          ).toDouble(),
        end.programSize.toDouble(),
        "L" + end.level,
      )
    }
    val chart = createChart(
      "Level Reduction Rate",
      "Time " + "(seconds)",
      "Program Size (tokens)",
      "Level Reduction Speed",
      dataset,
    )
    exportChart(chart, "-level-reduction-rate-over_time")
  }

  override fun performAnalysis() {
    if (events.size == 0) {
      return
    }
    logger.atInfo().log("Analyzing data")
    val starts: MutableList<IProfileEvent.LevelReductionEvent> = ArrayList()
    val ends: MutableList<IProfileEvent.LevelReductionEvent> = ArrayList()
    for (event in events) {
      if (event is IProfileEvent.LevelReductionEvent) {
        val levelEvent = event
        if (levelEvent.isStartEvent) {
          starts.add(levelEvent)
        } else {
          ends.add(levelEvent)
        }
      }
    }
    Preconditions.checkState(starts.size == ends.size)
    exportTimeProgramSizeChart(starts, ends)
    //    this.exportLevelProgramSizeChart(starts, ends);
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    @JvmStatic
    fun main(args: Array<String>) {
      if (args.size != 1) {
        System.err.println("Usage: <main> <event binary file>")
        System.exit(1)
      }
      val eventFile = Paths.get(args[0])
      if (Files.notExists(eventFile) || !Files.isRegularFile(eventFile)) {
        System.err.println("The event file does not exist: $eventFile")
        System.exit(1)
      }
      LevelReductionSpeedAnalysis(eventFile).analyze()
    }
  }
}
