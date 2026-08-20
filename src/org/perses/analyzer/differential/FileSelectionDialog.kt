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

import java.awt.BorderLayout
import java.awt.Component
import java.awt.Dimension
import java.awt.FlowLayout
import java.awt.Font
import java.awt.GridBagConstraints
import java.awt.GridBagLayout
import java.awt.Insets
import java.io.File
import java.nio.file.Path
import java.util.prefs.Preferences
import javax.swing.BorderFactory
import javax.swing.JButton
import javax.swing.JDialog
import javax.swing.JFileChooser
import javax.swing.JLabel
import javax.swing.JPanel
import javax.swing.JTextField
import javax.swing.WindowConstants

class FileSelectionDialog(
  parent: Component? = null,
) : JDialog(null, "Select Input Files", ModalityType.APPLICATION_MODAL) {
  private val prefs = Preferences.userNodeForPackage(FileSelectionDialog::class.java)

  var selectedFiles: Pair<Path, Path>? = null
    private set

  private val dialogFont = Font(Font.SANS_SERIF, Font.PLAIN, 14)

  private val file1Field =
    JTextField(60).apply {
      isEditable = false
      font = dialogFont
    }
  private val file2Field =
    JTextField(60).apply {
      isEditable = false
      font = dialogFont
    }

  private var path1: Path? = null
  private var path2: Path? = null
  private var compareButton: JButton? = null
  private var lastSelectedDirectory: File? = null

  init {
    // Load previously selected paths
    prefs.get(PREF_PATH1, null)?.let {
      val file = File(it)
      if (file.exists()) {
        path1 = file.toPath()
        file1Field.text = it
        lastSelectedDirectory = file.parentFile
      }
    }
    prefs.get(PREF_PATH2, null)?.let {
      val file = File(it)
      if (file.exists()) {
        path2 = file.toPath()
        file2Field.text = it
        if (lastSelectedDirectory == null) {
          lastSelectedDirectory = file.parentFile
        }
      }
    }

    defaultCloseOperation = WindowConstants.DISPOSE_ON_CLOSE
    minimumSize = Dimension(800, 250)
    layout = BorderLayout()

    val mainPanel =
      JPanel(GridBagLayout()).apply {
        border = BorderFactory.createEmptyBorder(20, 20, 20, 20)
      }
    val gbc =
      GridBagConstraints().apply {
        insets = Insets(5, 5, 5, 5)
        fill = GridBagConstraints.HORIZONTAL
      }

    // File 1
    gbc.gridx = 0
    gbc.gridy = 0
    mainPanel.add(JLabel("First File:").apply { font = dialogFont }, gbc)

    gbc.gridx = 1
    mainPanel.add(file1Field, gbc)

    gbc.gridx = 2
    mainPanel.add(
      JButton("Choose...").apply {
        font = dialogFont
        addActionListener {
          chooseFile { file ->
            path1 = file.toPath()
            file1Field.text = path1.toString()
            lastSelectedDirectory = file.parentFile
            savePaths(path1, path2)
            updateCompareButton()
          }
        }
      },
      gbc,
    )

    // File 2
    gbc.gridx = 0
    gbc.gridy = 1
    mainPanel.add(JLabel("Second File:").apply { font = dialogFont }, gbc)

    gbc.gridx = 1
    mainPanel.add(file2Field, gbc)

    gbc.gridx = 2
    mainPanel.add(
      JButton("Choose...").apply {
        font = dialogFont
        addActionListener {
          chooseFile { file ->
            path2 = file.toPath()
            file2Field.text = path2.toString()
            lastSelectedDirectory = file.parentFile
            savePaths(path1, path2)
            updateCompareButton()
          }
        }
      },
      gbc,
    )

    add(mainPanel, BorderLayout.CENTER)

    val buttonPanel =
      JPanel(FlowLayout(FlowLayout.RIGHT)).apply {
        border = BorderFactory.createEmptyBorder(0, 10, 10, 10)
      }

    val compareButton =
      JButton("Compare").apply {
        font = dialogFont
        isEnabled = false
        addActionListener {
          if (path1 != null && path2 != null) {
            selectedFiles = path1!! to path2!!
            dispose()
          }
        }
      }
    this.compareButton = compareButton

    val cancelButton =
      JButton("Cancel").apply {
        font = dialogFont
        addActionListener {
          dispose()
        }
      }

    buttonPanel.add(compareButton)
    buttonPanel.add(cancelButton)

    add(buttonPanel, BorderLayout.SOUTH)

    updateCompareButton()
    pack()
    setLocationRelativeTo(parent)
  }

  companion object {
    private const val PREF_PATH1 = "path1"
    private const val PREF_PATH2 = "path2"

    @JvmStatic
    fun savePaths(
      path1: Path?,
      path2: Path?,
    ) {
      val prefs = Preferences.userNodeForPackage(FileSelectionDialog::class.java)
      path1?.let { prefs.put(PREF_PATH1, it.toString()) }
      path2?.let { prefs.put(PREF_PATH2, it.toString()) }
    }
  }

  private fun chooseFile(onSelected: (File) -> Unit) {
    val chooser =
      JFileChooser().apply {
        fileSelectionMode = JFileChooser.FILES_ONLY
        dialogTitle = "Select YAML File"
        setPreferredSize(Dimension(1000, 800))
        lastSelectedDirectory?.let { currentDirectory = it }
      }
    if (chooser.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
      onSelected(chooser.selectedFile)
    }
  }

  private fun updateCompareButton() {
    compareButton?.isEnabled = path1 != null && path2 != null
  }
}
