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

import org.jfree.chart.ChartFactory
import org.jfree.chart.ChartPanel
import org.jfree.chart.labels.XYToolTipGenerator
import org.jfree.chart.plot.PlotOrientation
import org.jfree.data.xy.XYDataset
import org.jfree.data.xy.XYSeries
import org.jfree.data.xy.XYSeriesCollection
import java.awt.BorderLayout
import java.awt.Color
import java.awt.Dimension
import java.nio.file.Path
import javax.swing.BorderFactory
import javax.swing.JCheckBox
import javax.swing.JFrame
import javax.swing.JPanel
import javax.swing.JScrollPane
import org.perses.analyzer.differential.Main as DiffMain

class SizeTrendWindow(
  private val inputFiles: List<Path>,
) : JFrame() {
  private var lastDirectory: java.io.File? =
    run {
      val saved = prefs.get(PREF_LAST_DIR, null)
      if (saved != null) {
        val file = java.io.File(saved)
        if (file.exists()) file else null
      } else {
        inputFiles.firstOrNull()?.toFile()?.parentFile
      }
    }

  private val dataManager = SizeTrendDataManager()
  private val dataset = XYSeriesCollection()
  private val snapshotsBySeries = mutableListOf<List<Snapshot>>()
  private val checkboxes = mutableListOf<JCheckBox>()
  private val checkboxContainer =
    JPanel(java.awt.GridLayout(0, 1)).apply {
      border = BorderFactory.createTitledBorder("Visible Plots")
    }

  private data class SeriesEntry(
    val name: String,
    val snapshots: List<Snapshot>,
    val lastSnapshot: Snapshot,
    val series: XYSeries,
    val color: Color,
    var isSelected: Boolean = true,
  )

  private val seriesEntries = mutableListOf<SeriesEntry>()
  private var totalPlotsAdded = 0

  private val modernColors =
    listOf(
      Color(0x1F77B4), // Blue
      Color(0xFF7F0E), // Orange
      Color(0x2CA02C), // Green
      Color(0xD62728), // Red
      Color(0x9467BD), // Purple
      Color(0x8C564B), // Brown
      Color(0xE377C2), // Pink
      Color(0x7F7F7F), // Gray
      Color(0xBCBD22), // Olive
      Color(0x17BECF), // Cyan
      Color(0xAEC7E8), // Light Blue
      Color(0xFFBB78), // Light Orange
      Color(0x98DF8A), // Light Green
      Color(0xFF9896), // Light Red
      Color(0xC5B0D5), // Light Purple
      Color(0xC49C94), // Light Brown
      Color(0xF7B6D2), // Light Pink
      Color(0xC7C7C7), // Light Gray
      Color(0xDBDB8D), // Light Olive
      Color(0x9EDAE5), // Light Cyan
    )

  private var renderer =
    object : org.jfree.chart.renderer.xy.XYStepRenderer() {
      fun isFixpointIterationEnd(
        series: Int,
        item: Int,
      ): Boolean {
        val snapshot = snapshotsBySeries.getOrNull(series)?.getOrNull(item) ?: return false
        return snapshot.isFixpointIterationEnd()
      }

      fun getFixpointEndItemShape(): java.awt.Shape {
        val height = 50.0
        val width = 4.0
        // A long vertical line (implemented as a thin, very tall rectangle centered at the point)
        return java.awt.geom.Rectangle2D
          .Double(-1.0, -height / 2, width, height)
      }

      override fun getItemShapeVisible(
        series: Int,
        item: Int,
      ) = true

      override fun getItemShape(
        series: Int,
        item: Int,
      ): java.awt.Shape =
        if (isFixpointIterationEnd(series, item)) {
          getFixpointEndItemShape()
        } else {
          // A small hit area for regular points (invisible but trigger tooltips)
          java.awt.geom.Rectangle2D
            .Double(-3.0, -3.0, 6.0, 6.0)
        }

      override fun drawItem(
        g2: java.awt.Graphics2D,
        state: org.jfree.chart.renderer.xy.XYItemRendererState,
        dataArea: java.awt.geom.Rectangle2D,
        info: org.jfree.chart.plot.PlotRenderingInfo?,
        plot: org.jfree.chart.plot.XYPlot,
        domainAxis: org.jfree.chart.axis.ValueAxis,
        rangeAxis: org.jfree.chart.axis.ValueAxis,
        dataset: XYDataset,
        series: Int,
        item: Int,
        crosshairState: org.jfree.chart.plot.CrosshairState?,
        pass: Int,
      ) {
        if (!isSeriesVisible(series)) return

        // Pass 0: Draw lines
        if (pass == 0) {
          super.drawItem(
            g2,
            state,
            dataArea,
            info,
            plot,
            domainAxis,
            rangeAxis,
            dataset,
            series,
            item,
            crosshairState,
            pass,
          )
          return
        }

        // Pass 1: Handle shapes/markers and entities (tooltips)
        if (pass == 1) {
          val isFixpoint = isFixpointIterationEnd(series, item)
          val x = dataset.getXValue(series, item)
          val y = dataset.getYValue(series, item)
          val transX = domainAxis.valueToJava2D(x, dataArea, plot.domainAxisEdge)
          val transY = rangeAxis.valueToJava2D(y, dataArea, plot.rangeAxisEdge)

          val shape = getItemShape(series, item)
          val transform =
            java.awt.geom.AffineTransform
              .getTranslateInstance(transX, transY)
          val transformedShape = transform.createTransformedShape(shape)

          if (transformedShape.intersects(dataArea)) {
            if (isFixpoint) {
              val oldPaint = g2.paint
              g2.paint = seriesEntries[series].color
              g2.fill(transformedShape)
              g2.paint = oldPaint
            }

            // Always add entity for tooltips (including for invisible regular points)
            val entities = state.entityCollection
            if (entities != null) {
              val generator = getSeriesToolTipGenerator(series) ?: defaultToolTipGenerator
              val tip = generator?.generateToolTip(dataset, series, item)
              val entity =
                org.jfree.chart.entity.XYItemEntity(
                  transformedShape,
                  dataset,
                  series,
                  item,
                  tip,
                  null,
                )
              entities.add(entity)
            }
          }
        }
      }
    }.apply {
      stepPoint = 1.0 // Horizontal then Vertical
      defaultShapesVisible = true
    }

  private val thicknessValueField =
    javax.swing.JTextField("2.0", 5).apply {
      isEditable = true
    }

  init {
    title = "Program Size Trend Plotter"
    defaultCloseOperation = EXIT_ON_CLOSE
    minimumSize = Dimension(1000, 700)
    extendedState = MAXIMIZED_BOTH

    inputFiles.forEach { addPlot(it) }

    val chart =
      ChartFactory.createXYLineChart(
        "Program Size Reduction Trend",
        "Time (seconds)",
        "Program Size (tokens)",
        dataset,
        PlotOrientation.VERTICAL,
        false, // Legend disabled - we will use checkboxes instead
        true, // Tooltips
        false, // URLs
      )

    chart.antiAlias = true
    chart.setTextAntiAlias(true)
    chart.renderingHints[java.awt.RenderingHints.KEY_TEXT_ANTIALIASING] =
      java.awt.RenderingHints.VALUE_TEXT_ANTIALIAS_ON
    chart.renderingHints[java.awt.RenderingHints.KEY_ANTIALIASING] =
      java.awt.RenderingHints.VALUE_ANTIALIAS_ON
    chart.backgroundPaint = Color.WHITE

    chart.title.font = java.awt.Font("Dialog", java.awt.Font.BOLD, 18)

    val plot = chart.xyPlot
    plot.isDomainPannable = true
    plot.isRangePannable = true
    plot.backgroundPaint = Color.WHITE
    plot.isDomainGridlinesVisible = true
    plot.isRangeGridlinesVisible = true
    plot.domainGridlinePaint = Color.LIGHT_GRAY
    plot.rangeGridlinePaint = Color.LIGHT_GRAY

    // Improve Axis Fonts
    plot.domainAxis.labelFont = java.awt.Font("Dialog", java.awt.Font.BOLD, 14)
    plot.rangeAxis.labelFont = java.awt.Font("Dialog", java.awt.Font.BOLD, 14)
    plot.domainAxis.tickLabelFont = java.awt.Font("Dialog", java.awt.Font.PLAIN, 12)
    plot.rangeAxis.tickLabelFont = java.awt.Font("Dialog", java.awt.Font.PLAIN, 12)

    renderer.defaultToolTipGenerator = SnapshotToolTipGenerator(snapshotsBySeries)
    plot.renderer = renderer

    val chartPanel =
      ChartPanel(chart).apply {
        isMouseWheelEnabled = true
      }

    // Top panel for controls
    val controlPanel =
      JPanel(BorderLayout()).apply {
        border = BorderFactory.createEmptyBorder(5, 5, 5, 5)
      }

    // Selection buttons will use the class fields directly

    val selectionButtons =
      JPanel(java.awt.FlowLayout(java.awt.FlowLayout.LEFT)).apply {
        add(
          javax.swing.JButton("Select All").apply {
            addActionListener {
              seriesEntries.forEach { it.isSelected = true }
              refreshUI()
            }
          },
        )
        add(
          javax.swing.JButton("Deselect All").apply {
            addActionListener {
              seriesEntries.forEach { it.isSelected = false }
              refreshUI()
            }
          },
        )
        add(
          javax.swing.JButton("Add Plot").apply {
            addActionListener {
              val chooser =
                javax.swing.JFileChooser().apply {
                  isMultiSelectionEnabled = true
                  fileFilter = javax.swing.filechooser.FileNameExtensionFilter("CSV Files", "csv")
                  currentDirectory = lastDirectory
                }
              if (chooser.showOpenDialog(this@SizeTrendWindow) ==
                javax.swing.JFileChooser.APPROVE_OPTION
              ) {
                lastDirectory = chooser.currentDirectory
                lastDirectory?.let { prefs.put(PREF_LAST_DIR, it.absolutePath) }
                for (file in chooser.selectedFiles) {
                  addPlot(file.toPath())
                }
                revalidate()
                repaint()
              }
            }
          },
        )
        add(
          javax.swing.JButton("Launch Diff").apply {
            addActionListener {
              DiffMain.main(arrayOf())
            }
          },
        )
      }

    // aesthetics and visibility handled in refreshUI

    // thicknessValueField already initialized as a field

    fun updateThickness(newThickness: Float) {
      val stroke = java.awt.BasicStroke(newThickness)
      for (j in 0 until dataset.seriesCount) {
        renderer.setSeriesStroke(j, stroke)
      }
      thicknessValueField.text = String.format("%.1f", newThickness)
    }

    thicknessValueField.addActionListener {
      val newVal = thicknessValueField.text.toFloatOrNull() ?: 2.0f
      updateThickness(newVal)
    }

    val thicknessPanel =
      JPanel(BorderLayout()).apply {
        border = BorderFactory.createTitledBorder("Line Aesthetics")
        val composite =
          JPanel(java.awt.FlowLayout(java.awt.FlowLayout.LEFT)).apply {
            add(
              javax.swing.JButton("-").apply {
                addActionListener {
                  val curr = thicknessValueField.text.toFloatOrNull() ?: 2.0f
                  updateThickness((curr - 0.1f).coerceAtLeast(0.1f))
                }
              },
            )
            add(thicknessValueField)
            add(
              javax.swing.JButton("+").apply {
                addActionListener {
                  val curr = thicknessValueField.text.toFloatOrNull() ?: 2.0f
                  updateThickness((curr + 0.1f).coerceAtMost(20.0f))
                }
              },
            )
          }
        add(javax.swing.JLabel("Thickness (pixels):"), BorderLayout.NORTH)
        add(composite, BorderLayout.CENTER)
      }

    val controlsSplit =
      javax.swing
        .JSplitPane(
          javax.swing.JSplitPane.HORIZONTAL_SPLIT,
          checkboxContainer,
          thicknessPanel,
        ).apply {
          dividerLocation = 700
          dividerSize = 8
          border = null
        }

    controlPanel.add(selectionButtons, BorderLayout.NORTH)
    controlPanel.add(controlsSplit, BorderLayout.CENTER)

    val topScroll =
      JScrollPane(controlPanel).apply {
        verticalScrollBarPolicy = JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED
        horizontalScrollBarPolicy = JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED
        border = null
      }

    val preferredHeight = controlPanel.preferredSize.height + 25
    val mainSplit =
      javax.swing.JSplitPane(javax.swing.JSplitPane.VERTICAL_SPLIT, topScroll, chartPanel).apply {
        dividerLocation = preferredHeight.coerceAtMost(400)
        dividerSize = 10
        border = null
      }

    contentPane.setLayout(BorderLayout())
    contentPane.add(mainSplit, BorderLayout.CENTER)

    pack()
    setLocationRelativeTo(null)
  }

  private fun addPlot(path: Path) {
    try {
      val snapshots = dataManager.loadSnapshots(path)
      val lastSnapshot = snapshots.lastOrNull() ?: Snapshot(0, 0, "")
      val formattedName =
        "${path.fileName} " +
          "(${lastSnapshot.elapsedSeconds}s, " +
          "${lastSnapshot.currentProgramSize})"

      val series = XYSeries(formattedName)
      for (snapshot in snapshots) {
        series.add(snapshot.elapsedSeconds.toDouble(), snapshot.currentProgramSize.toDouble())
      }

      val color = getColorForSeries(totalPlotsAdded++)
      seriesEntries.add(SeriesEntry(formattedName, snapshots, lastSnapshot, series, color))
      refreshUI()
    } catch (e: Exception) {
      javax.swing.JOptionPane.showMessageDialog(
        this,
        "Failed to add plot: ${e.message}",
        "Error",
        javax.swing.JOptionPane.ERROR_MESSAGE,
      )
    }
  }

  private fun refreshUI() {
    seriesEntries.sortWith(
      compareBy({
        it.lastSnapshot.elapsedSeconds
      }, { it.lastSnapshot.currentProgramSize }),
    )

    dataset.removeAllSeries()
    snapshotsBySeries.clear()
    checkboxes.clear()
    checkboxContainer.removeAll()

    for (entry in seriesEntries) {
      dataset.addSeries(entry.series)
      snapshotsBySeries.add(entry.snapshots)

      val seriesIndex = dataset.seriesCount - 1
      renderer.setSeriesPaint(seriesIndex, entry.color)
      val thickness = thicknessValueField.text.toFloatOrNull() ?: 2.0f
      renderer.setSeriesStroke(seriesIndex, java.awt.BasicStroke(thickness))
      renderer.setSeriesVisible(seriesIndex, entry.isSelected)

      val row = JPanel(java.awt.FlowLayout(java.awt.FlowLayout.LEFT, 5, 0))
      val color = renderer.lookupSeriesPaint(seriesIndex) as Color
      val swatch = javax.swing.JLabel(ColorIcon(color))
      val checkbox =
        JCheckBox(entry.name, entry.isSelected).apply {
          addActionListener {
            entry.isSelected = isSelected
            renderer.setSeriesVisible(seriesIndex, isSelected)
          }
        }
      checkboxes.add(checkbox)
      row.add(swatch)
      row.add(checkbox)
      checkboxContainer.add(row)
    }

    checkboxContainer.revalidate()
    checkboxContainer.repaint()
  }

  private class ColorIcon(
    private val color: Color,
  ) : javax.swing.Icon {
    override fun paintIcon(
      c: java.awt.Component?,
      g: java.awt.Graphics?,
      x: Int,
      y: Int,
    ) {
      val g2 = g as java.awt.Graphics2D
      g2.color = color
      g2.fillRect(x, y + 2, 12, 12)
      g2.color = Color.BLACK
      g2.drawRect(x, y + 2, 12, 12)
    }

    override fun getIconWidth() = 16

    override fun getIconHeight() = 16
  }

  private class SnapshotToolTipGenerator(
    private val allSnapshots: List<List<Snapshot>>,
  ) : XYToolTipGenerator {
    override fun generateToolTip(
      dataset: XYDataset,
      series: Int,
      item: Int,
    ): String? {
      val snapshot = allSnapshots.getOrNull(series)?.getOrNull(item) ?: return null
      return buildString {
        append("<html>")
        append("<div style='padding: 5px;'>")
        append("<b>Series:</b> ${dataset.getSeriesKey(series)}<br>")
        append("<b>Time:</b> ${snapshot.elapsedSeconds}s<br>")
        append("<b>Size:</b> ${snapshot.currentProgramSize} tokens<br>")
        if (snapshot.actionDescription.isNotEmpty()) {
          append("<hr>")
          append("<b>Action:</b> ${snapshot.actionDescription}")
        }
        append("</div>")
        append("</html>")
      }
    }
  }

  private fun getColorForSeries(index: Int): Color {
    if (index < modernColors.size) return modernColors[index]
    // Procedural color generation (Golden Ratio distribution for hue)
    val hue = (index * 0.618033988749895f) % 1.0f
    // Keep saturation and brightness in a range that looks modern
    return Color.getHSBColor(hue, 0.6f, 0.8f)
  }

  companion object {
    private val prefs =
      java.util.prefs.Preferences
        .userNodeForPackage(SizeTrendWindow::class.java)
    private val PREF_LAST_DIR = "${SizeTrendWindow::class.qualifiedName}.last_plot_directory"
  }
}
