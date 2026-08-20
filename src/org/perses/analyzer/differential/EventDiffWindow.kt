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
package org.perses.analyzer.differential

import org.jfree.chart.ChartFactory
import org.jfree.chart.ChartPanel
import org.jfree.chart.annotations.XYTitleAnnotation
import org.jfree.chart.block.BlockBorder
import org.jfree.chart.labels.XYToolTipGenerator
import org.jfree.chart.plot.PlotOrientation
import org.jfree.chart.title.LegendTitle
import org.jfree.chart.ui.RectangleAnchor
import org.jfree.chart.ui.RectangleInsets
import org.jfree.data.xy.XYDataset
import org.jfree.data.xy.XYSeries
import org.jfree.data.xy.XYSeriesCollection
import org.perses.listener.DifferentialEvents
import java.awt.BorderLayout
import java.awt.Color
import java.awt.Dimension
import java.awt.FlowLayout
import java.awt.Font
import java.io.File
import javax.swing.BorderFactory
import javax.swing.JCheckBox
import javax.swing.JFrame
import javax.swing.JLabel
import javax.swing.JPanel
import javax.swing.JScrollPane
import javax.swing.JSplitPane
import javax.swing.JTabbedPane
import javax.swing.JTextField
import javax.swing.JTree
import javax.swing.event.TreeExpansionEvent
import javax.swing.event.TreeExpansionListener
import javax.swing.event.TreeSelectionEvent
import javax.swing.event.TreeSelectionListener
import javax.swing.tree.DefaultMutableTreeNode
import javax.swing.tree.TreePath

class EventDiffWindow(
  private val leftPath: String,
  private val leftEvents: List<DifferentialEvents.NodeReductionEvent>,
  private val rightPath: String,
  private val rightEvents: List<DifferentialEvents.NodeReductionEvent>,
) : JFrame() {
  private var leftNodeMap: Map<NodeId, DefaultMutableTreeNode> = emptyMap()
  private var rightNodeMap: Map<NodeId, DefaultMutableTreeNode> = emptyMap()

  private val leftTree: JTree
  private val rightTree: JTree

  private val leftScroll: JScrollPane
  private val rightScroll: JScrollPane
  private var syncEnabled = true
  private var hideEmptyEdits = false

  init {
    title = "Algorithm Run Comparator (Swing + Kotlin)"
    defaultCloseOperation = EXIT_ON_CLOSE
    minimumSize = Dimension(1200, 800)
    extendedState = MAXIMIZED_BOTH

    // Create Trees
    setupTree("Run A", leftEvents).let {
      leftTree = it.first
      leftNodeMap = it.second
      leftScroll = JScrollPane(leftTree)
    }

    setupTree("Run B", rightEvents).let {
      rightTree = it.first
      rightNodeMap = it.second
      rightScroll = JScrollPane(rightTree)
    }

    // HACK 2: Synchronize Expansion/Collapse
    val syncListener = SyncExpansionListener()
    leftTree.addTreeExpansionListener(syncListener)
    rightTree.addTreeExpansionListener(syncListener)

    // HACK 3: Synchronize Selection
    val selectionListener = SyncSelectionListener()
    leftTree.addTreeSelectionListener(selectionListener)
    rightTree.addTreeSelectionListener(selectionListener)

    // Tool Panel
    val syncCheckBox =
      JCheckBox("Sync Selection/Expansion", syncEnabled).apply {
        addActionListener {
          syncEnabled = isSelected
        }
      }
    val toolPanel =
      JPanel(FlowLayout(FlowLayout.LEFT)).apply {
        add(syncCheckBox)
        add(
          JCheckBox("Hide empty edits", hideEmptyEdits).apply {
            addActionListener {
              hideEmptyEdits = isSelected
              refreshTrees()
            }
          },
        )
        border = BorderFactory.createMatteBorder(0, 0, 1, 0, Color.LIGHT_GRAY)
      }

    val leftTreePanel =
      JPanel(BorderLayout()).apply {
        add(createHeader(leftPath), BorderLayout.NORTH)
        add(leftScroll, BorderLayout.CENTER)
      }
    val rightTreePanel =
      JPanel(BorderLayout()).apply {
        add(createHeader(rightPath), BorderLayout.NORTH)
        add(rightScroll, BorderLayout.CENTER)
      }

    val treeSplit =
      JSplitPane(JSplitPane.HORIZONTAL_SPLIT, leftTreePanel, rightTreePanel).apply {
        resizeWeight = 0.5
        dividerSize = 10
        border = null
      }

    val topSectionPanel =
      JPanel(BorderLayout()).apply {
        add(toolPanel, BorderLayout.NORTH)
        add(treeSplit, BorderLayout.CENTER)
      }

    val leftStats = createStatisticsPanel(leftEvents)
    val rightStats = createStatisticsPanel(rightEvents)
    val statsSplit =
      JSplitPane(JSplitPane.HORIZONTAL_SPLIT, leftStats, rightStats).apply {
        resizeWeight = 0.5
        dividerSize = 10
        border = null
      }

    val plotPanel =
      createAccumulatedTokensPlot(
        "Run A: ${File(leftPath).name}",
        leftEvents,
        "Run B: ${File(rightPath).name}",
        rightEvents,
      )
    val statsPlotSplit =
      JSplitPane(JSplitPane.VERTICAL_SPLIT, statsSplit, plotPanel).apply {
        resizeWeight = 0.4
        dividerSize = 10
        border = null
      }

    val tabbedPane = JTabbedPane()
    tabbedPane.addTab("Event Diff", topSectionPanel)
    tabbedPane.addTab("Statistics", statsPlotSplit)

    contentPane.add(tabbedPane, BorderLayout.CENTER)
  }

  private fun refreshTrees() {
    val filteredLeft =
      if (hideEmptyEdits) {
        leftEvents.filter { it.deletedTokenCount > 0 }
      } else {
        leftEvents
      }
    val filteredRight =
      if (hideEmptyEdits) {
        rightEvents.filter { it.deletedTokenCount > 0 }
      } else {
        rightEvents
      }

    updateTreeModel(leftTree, "Run A", filteredLeft, true)
    updateTreeModel(rightTree, "Run B", filteredRight, false)
  }

  private fun updateTreeModel(
    tree: JTree,
    title: String,
    events: List<DifferentialEvents.NodeReductionEvent>,
    isLeft: Boolean,
  ) {
    val (model, nodeMap) = EventDiffTreeModelBuilder.createEventTreeModel(title, events)
    tree.model = model
    if (isLeft) {
      leftNodeMap = nodeMap
    } else {
      rightNodeMap = nodeMap
    }

    // Expand iteration nodes by default
    val rootNode = model.root as DefaultMutableTreeNode
    for (i in 0 until rootNode.childCount) {
      val child = rootNode.getChildAt(i) as DefaultMutableTreeNode
      tree.expandPath(TreePath(child.path))
    }
  }

  private inner class SyncExpansionListener : TreeExpansionListener {
    private var isSyncing = false

    private fun syncExpansion(
      e: TreeExpansionEvent,
      expand: Boolean,
    ) {
      if (isSyncing || !syncEnabled) return
      val sourceTree = e.source as JTree
      val targetTree = if (sourceTree == leftTree) rightTree else leftTree
      val targetNodeMap = if (sourceTree == leftTree) rightNodeMap else leftNodeMap

      val sourcePath = e.path ?: return
      val sourceNode = sourcePath.lastPathComponent as DefaultMutableTreeNode
      if (sourceNode.level != 2) return

      isSyncing = true
      try {
        val targetNode =
          EventDiffTreeModelBuilder.findCorrespondingNode(
            sourceNode,
            targetNodeMap,
          )
        if (targetNode != null) {
          val targetPath = TreePath(targetNode.path)
          if (expand) {
            targetTree.expandPath(targetPath)
          } else {
            targetTree.collapsePath(targetPath)
          }
        }
      } finally {
        isSyncing = false
      }
    }

    override fun treeExpanded(e: TreeExpansionEvent) {
      syncExpansion(e, true)
    }

    override fun treeCollapsed(e: TreeExpansionEvent) {
      syncExpansion(e, false)
    }
  }

  private inner class SyncSelectionListener : TreeSelectionListener {
    private var isSyncing = false

    override fun valueChanged(e: TreeSelectionEvent) {
      if (isSyncing || !syncEnabled) return
      val sourceTree = e.source as JTree
      val targetTree = if (sourceTree == leftTree) rightTree else leftTree
      val targetNodeMap = if (sourceTree == leftTree) rightNodeMap else leftNodeMap

      val selectedPath = e.path ?: return
      val selectedNode = selectedPath.lastPathComponent as DefaultMutableTreeNode
      if (selectedNode.level != 2) return

      val sourceScroll = if (sourceTree == leftTree) leftScroll else rightScroll
      val targetScroll = if (sourceTree == leftTree) rightScroll else leftScroll

      val sourceNodeBounds = sourceTree.getPathBounds(selectedPath) ?: return
      val relativeY = sourceNodeBounds.y - sourceScroll.verticalScrollBar.value

      isSyncing = true
      try {
        val targetNode =
          EventDiffTreeModelBuilder.findCorrespondingNode(
            selectedNode,
            targetNodeMap,
          )
        if (targetNode != null) {
          val targetPath = TreePath(targetNode.path)
          targetTree.selectionPath = targetPath

          // Align the target node to the same relative position
          val targetNodeBounds = targetTree.getPathBounds(targetPath)
          if (targetNodeBounds != null) {
            targetScroll.verticalScrollBar.value = targetNodeBounds.y - relativeY
          } else {
            targetTree.scrollPathToVisible(targetPath)
          }
        }
      } finally {
        isSyncing = false
      }
    }
  }

  private fun setupTree(
    title: String,
    events: List<DifferentialEvents.NodeReductionEvent>,
  ): Pair<JTree, Map<NodeId, DefaultMutableTreeNode>> {
    val (model, nodeMap) = EventDiffTreeModelBuilder.createEventTreeModel(title, events)
    val tree =
      JTree(model).apply {
        isRootVisible = false
        showsRootHandles = true
        rowHeight = 25
      }

    // Expand iteration nodes by default
    val rootNode = model.root as DefaultMutableTreeNode
    for (i in 0 until rootNode.childCount) {
      val child = rootNode.getChildAt(i) as DefaultMutableTreeNode
      tree.expandPath(TreePath(child.path))
    }

    return tree to nodeMap
  }

  // Wrap in Panels with Path labels
  private fun createHeader(path: String): JPanel {
    val file = File(path)
    val nameLabel =
      JLabel(" File: ${file.name}").apply {
        font = font.deriveFont(Font.BOLD)
        border = BorderFactory.createEmptyBorder(5, 5, 2, 5)
      }
    val dirField =
      JTextField(" Dir: ${file.parent ?: "."}").apply {
        isEditable = false
        background = null
        border = null
        foreground = Color.GRAY
      }
    val dirScroll =
      JScrollPane(dirField).apply {
        horizontalScrollBarPolicy = JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED
        verticalScrollBarPolicy = JScrollPane.VERTICAL_SCROLLBAR_NEVER
        border = BorderFactory.createEmptyBorder(0, 5, 5, 5)
      }
    return JPanel(BorderLayout()).apply {
      add(nameLabel, BorderLayout.NORTH)
      add(dirScroll, BorderLayout.CENTER)
    }
  }

  private fun createStatisticsPanel(events: List<DifferentialEvents.NodeReductionEvent>): JPanel {
    val stats = EventDiffStatistics.calculate(events)

    val statsLabel =
      JLabel(
        buildString {
          append("<html>")
          append("<div style='padding: 5px;'>")
          append("<b>Total Summary:</b>")
          append(
            "<table style='width: 100%; border: 1px solid #ccc; border-collapse: collapse; margin-bottom: 10px;'>",
          )
          append("<tr style='background-color: #eee;'>")
          append("<th style='border: 1px solid #ccc; text-align: right; padding: 3px;'>Nodes</th>")
          append("<th style='border: 1px solid #ccc; text-align: right; padding: 3px;'>Tokens</th>")
          append(
            "<th style='border: 1px solid #ccc; text-align: right; padding: 3px;'>Speed (t/s)</th>",
          )
          append("<th style='border: 1px solid #ccc; text-align: right; padding: 3px;'>Succ%</th>")
          append("<th style='border: 1px solid #ccc; text-align: right; padding: 3px;'>Tok/I</th>")
          append("<th style='border: 1px solid #ccc; text-align: right; padding: 3px;'>Time/I</th>")
          append("<th style='border: 1px solid #ccc; text-align: right; padding: 3px;'>Time/U</th>")
          append(
            "<th style='border: 1px solid #ccc; text-align: right; padding: 3px;'>Test Time (avg/med [min-max] ±std)</th>",
          )
          append(
            "<th style='border: 1px solid #ccc; text-align: right; padding: 3px;'>Edits (I/U)</th>",
          )
          append(
            "<th style='border: 1px solid #ccc; text-align: right; padding: 3px;'>Total Time</th>",
          )
          append("</tr>")
          append("<tr>")
          append(
            "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>${stats.totalEvents}</td>",
          )
          append(
            "<td style='border: 1px solid #ccc; padding: 3px; text-align: right; color: #008000;'><b>${stats.totalTokensDeleted}</b></td>",
          )
          append(
            "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>${"%.2f".format(
              stats.totalReductionSpeed,
            )}</td>",
          )
          append(
            "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>${"%.1f".format(
              stats.totalSuccessRate * 100,
            )}%</td>",
          )
          append(
            "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>${"%.1f".format(
              stats.totalTokensPerInterestedEdit,
            )}</td>",
          )
          append(
            "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>${"%.1f".format(
              stats.totalTimePerInterestingEdit,
            )}ms</td>",
          )
          append(
            "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>${"%.1f".format(
              stats.totalTimePerUninterestingEdit,
            )}ms</td>",
          )
          append(
            "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>" +
              "${stats.totalEditTimeStats.avgTimeMs}/${stats.totalEditTimeStats.medianTimeMs} " +
              "[${stats.totalEditTimeStats.minTimeMs}-${stats.totalEditTimeStats.maxTimeMs}] " +
              "±${"%.1f".format(stats.totalEditTimeStats.stdDevMs)}ms" +
              "</td>",
          )
          append(
            "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>" +
              "${stats.totalEdits} " +
              "(${stats.interestingEdits}I/${stats.totalEdits - stats.interestingEdits}U)</td>",
          )
          append(
            "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>" +
              "${stats.totalTimeSeconds}s" +
              "</td>",
          )
          append("</tr>")
          append("</table>")

          if (stats.iterationStats.isNotEmpty()) {
            append("<b>Per Iteration:</b>")
            append(
              "<table style='width: 100%; border: 1px solid #ccc; border-collapse: collapse;'>",
            )
            append("<tr style='background-color: #eee;'>")
            append("<th style='border: 1px solid #ccc; padding: 3px; text-align: right;'>Iter</th>")
            append(
              "<th style='border: 1px solid #ccc; padding: 3px; text-align: right;'>Nodes</th>",
            )
            append(
              "<th style='border: 1px solid #ccc; padding: 3px; text-align: right;'>Tokens</th>",
            )
            append(
              "<th style='border: 1px solid #ccc; padding: 3px; text-align: right;'>Speed</th>",
            )
            append(
              "<th style='border: 1px solid #ccc; padding: 3px; text-align: right;'>Succ%</th>",
            )
            append(
              "<th style='border: 1px solid #ccc; padding: 3px; text-align: right;'>Tok/I</th>",
            )
            append(
              "<th style='border: 1px solid #ccc; padding: 3px; text-align: right;'>Time/I</th>",
            )
            append(
              "<th style='border: 1px solid #ccc; padding: 3px; text-align: right;'>Time/U</th>",
            )
            append(
              "<th style='border: 1px solid #ccc; padding: 3px; text-align: right;'>Test Time (avg/med [min-max] ±std)</th>",
            )
            append(
              "<th style='border: 1px solid #ccc; padding: 3px; text-align: right;'>Edits</th>",
            )
            append("<th style='border: 1px solid #ccc; padding: 3px; text-align: right;'>Time</th>")
            append("</tr>")
            for (iter in stats.iterationStats) {
              append("<tr>")
              append(
                "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>${iter.iteration}</td>",
              )
              append(
                "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>" +
                  "${iter.totalEvents}" +
                  "</td>",
              )
              append(
                "<td style='border: 1px solid #ccc; padding: 3px; text-align: right; color: " +
                  "${if (iter.totalTokensDeleted > 0) "#008000" else "#000"};'>" +
                  "${if (iter.totalTokensDeleted > 0) "<b>-${iter.totalTokensDeleted}</b>" else "0"}</td>",
              )
              append(
                "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>" +
                  "${"%.2f".format(
                    iter.reductionSpeed,
                  )}</td>",
              )
              append(
                "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>" +
                  "${"%.1f".format(
                    iter.successRate * 100,
                  )}%</td>",
              )
              append(
                "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>" +
                  "${"%.1f".format(
                    iter.tokensPerInterestedEdit,
                  )}</td>",
              )
              append(
                "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>" +
                  "${"%.1f".format(
                    iter.timePerInterestingEdit,
                  )}ms</td>",
              )
              append(
                "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>" +
                  "${"%.1f".format(
                    iter.timePerUninterestingEdit,
                  )}ms</td>",
              )
              append(
                "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>" +
                  "${iter.editTimeStats.avgTimeMs}/${iter.editTimeStats.medianTimeMs} " +
                  "[${iter.editTimeStats.minTimeMs}-${iter.editTimeStats.maxTimeMs}] " +
                  "±${"%.1f".format(iter.editTimeStats.stdDevMs)}ms" +
                  "</td>",
              )
              append(
                "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>" +
                  "${iter.totalEdits} (${iter.interestingEdits}I)" +
                  "</td>",
              )
              append(
                "<td style='border: 1px solid #ccc; padding: 3px; text-align: right;'>${iter.totalTimeSeconds}s</td>",
              )
              append("</tr>")
            }
            append("</table>")
          }
          append("</div>")
          append("</html>")
        },
      ).apply {
        border =
          BorderFactory.createCompoundBorder(
            BorderFactory.createMatteBorder(1, 0, 0, 0, Color.LIGHT_GRAY),
            BorderFactory.createEmptyBorder(5, 5, 5, 5),
          )
      }

    return JPanel(BorderLayout()).apply {
      val scrollPane =
        JScrollPane(statsLabel).apply {
          border = null
          horizontalScrollBarPolicy = JScrollPane.HORIZONTAL_SCROLLBAR_NEVER
          verticalScrollBarPolicy = JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED
        }
      add(scrollPane, BorderLayout.CENTER)
      background = Color(245, 245, 245)
    }
  }

  private fun createAccumulatedTokensPlot(
    runAName: String,
    runAEvents: List<DifferentialEvents.NodeReductionEvent>,
    runBName: String,
    runBEvents: List<DifferentialEvents.NodeReductionEvent>,
  ): ChartPanel {
    val dataset = XYSeriesCollection()

    val runAEdits = runAEvents.flatMap { event -> event.editsTested.map { it to event } }
    val runBEdits = runBEvents.flatMap { event -> event.editsTested.map { it to event } }

    fun addSeries(
      name: String,
      edits: List<Pair<DifferentialEvents.Edit, DifferentialEvents.NodeReductionEvent>>,
      initialStartTime: Int,
    ) {
      if (edits.isEmpty()) return
      val series = XYSeries(name)
      var totalDeleted = 0
      series.add(0.0, 0.0)
      for ((edit, _) in edits) {
        if (edit.propertyTestResult.isInteresting) {
          totalDeleted += edit.deletedTokenCount
        }
        series.add(
          (edit.startPersesTimeSeconds - initialStartTime).toDouble(),
          totalDeleted.toDouble(),
        )
      }
      dataset.addSeries(series)
    }

    val globalStartTime =
      minOf(
        runAEvents.firstOrNull()?.startPersesTimeSeconds ?: Int.MAX_VALUE,
        runBEvents.firstOrNull()?.startPersesTimeSeconds ?: Int.MAX_VALUE,
      ).takeIf { it != Int.MAX_VALUE } ?: 0

    addSeries(runAName, runAEdits, globalStartTime)
    addSeries(runBName, runBEdits, globalStartTime)

    val chart =
      ChartFactory.createXYLineChart(
        "Accumulated Deleted Tokens over Time (Edit Level)",
        "Time (s)",
        "Deleted Tokens",
        dataset,
        PlotOrientation.VERTICAL,
        false, // Legend disabled here, will add as annotation
        true,
        false,
      )

    chart.antiAlias = true

    val plot = chart.xyPlot
    plot.backgroundPaint = Color.WHITE
    plot.isDomainGridlinesVisible = true
    plot.isRangeGridlinesVisible = true
    plot.domainGridlinePaint = Color.LIGHT_GRAY
    plot.rangeGridlinePaint = Color.LIGHT_GRAY

    val renderer = plot.getRenderer() as org.jfree.chart.renderer.xy.XYLineAndShapeRenderer
    renderer.setSeriesStroke(0, java.awt.BasicStroke(2.0f))
    renderer.setSeriesStroke(1, java.awt.BasicStroke(2.0f))

    // Show points on the curves
    renderer.setSeriesShapesVisible(0, true)
    renderer.setSeriesShapesVisible(1, true)

    // Detailed tooltips for events
    val toolTipGenerator = EditToolTipGenerator(runAEdits, runBEdits)
    renderer.setSeriesToolTipGenerator(0, toolTipGenerator)
    renderer.setSeriesToolTipGenerator(1, toolTipGenerator)

    // Add legend inside the plot at the lower right corner
    val legend = LegendTitle(plot.getRenderer())
    legend.margin = RectangleInsets(1.0, 1.0, 1.0, 1.0)
    legend.frame = BlockBorder(Color.LIGHT_GRAY)
    legend.backgroundPaint = Color.WHITE
    val legendAnnotation = XYTitleAnnotation(0.98, 0.02, legend, RectangleAnchor.BOTTOM_RIGHT)
    legendAnnotation.setMaxWidth(0.3)
    plot.addAnnotation(legendAnnotation)

    val panel = ChartPanel(chart)
    panel.maximumDrawWidth = 4000
    panel.maximumDrawHeight = 4000
    panel.minimumDrawWidth = 100
    panel.minimumDrawHeight = 100

    return panel
  }

  private class EditToolTipGenerator(
    private val runAEdits:
      List<Pair<DifferentialEvents.Edit, DifferentialEvents.NodeReductionEvent>>,
    private val runBEdits:
      List<Pair<DifferentialEvents.Edit, DifferentialEvents.NodeReductionEvent>>,
  ) : XYToolTipGenerator {
    override fun generateToolTip(
      dataset: XYDataset,
      series: Int,
      item: Int,
    ): String? {
      if (item <= 0) return "Start"
      val edits = if (series == 0) runAEdits else runBEdits
      val (edit, event) = edits.getOrNull(item - 1) ?: return null

      return buildString {
        append("<html>")
        append("<div style='padding: 5px;'>")
        append("<b>Run:</b> ${if (series == 0) "A" else "B"}<br>")
        append("<b>Edit Index:</b> $item<br>")
        append("<b>Time:</b> ${"%.1f".format(dataset.getXValue(series, item))}s<br>")
        append("<b>Accumulated Tokens:</b> ${dataset.getYValue(series, item).toInt()}<br>")
        append("<hr>")
        append("<b>Rule:</b> ${event.ruleName}<br>")
        append("<b>Node ID:</b> ${event.nodeId}<br>")
        append("<b>Edit Description:</b> ${edit.structureDescription}<br>")
        append("<b>Context:</b> ${edit.contextualDescription}<br>")
        append(
          "<b>Result:</b> ${if (edit.propertyTestResult.isInteresting) "✅ Interesting" else "❌ Uninteresting"}<br>",
        )
        append("<b>Deleted Tokens:</b> ${edit.deletedTokenCount}<br>")
        append("<b>Test Time:</b> ${edit.propertyTestResult.elapsedMillis}ms")
        append("</div>")
        append("</html>")
      }
    }
  }
}
