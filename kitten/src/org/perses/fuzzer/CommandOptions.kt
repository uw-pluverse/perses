/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.fuzzer

import com.beust.jcommander.IStringConverter
import com.beust.jcommander.Parameter
import com.google.common.base.Preconditions
import org.perses.cmd.LanguageControlFlagGroup
import org.perses.fuzzer.config.TestingConfiguration
import org.perses.fuzzer.config.TestingConfiguration.Companion.readFrom
import org.perses.fuzzer.languagemodel.LanguageModelType
import org.perses.spartree.SparTreeGeneratorType
import org.perses.util.Util
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import org.perses.util.cmd.AbstractCommandOptions
import java.io.File
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths

/** Parser for command line arguments.  */
class CommandOptions : AbstractCommandOptions() {
  @JvmField
  val generalFlags = registerFlags(GeneralFlagGroup())
  val mutationControl = registerFlags(MutationControl())
  val compilerFlags = registerFlags(CompilerFlagGroup())
  val coverageFlags = registerFlags(CoverageFlagGroup())
  val languageExtFlags = registerFlags(LanguageControlFlagGroup())

  inner class GeneralFlagGroup : AbstractCommandLineFlagGroup(groupName = "General") {
    @Parameter(
      names = ["--random-seed"],
      description = "seed for the random number generator.",
      order = FlagOrder.GENERAL_CONTROL,
    )
    var randomSeed = System.currentTimeMillis()

    @Parameter(
      names = ["--seed-limit"],
      description = "the upper limit of the seed files to be used",
      order = FlagOrder.GENERAL_CONTROL + 100,
    )
    var numberLimitOfSeedFiles = Int.MAX_VALUE

    @Parameter(
      names = ["--interesting-folder"],
      description = "folder to save interesting mutants",
      order = FlagOrder.GENERAL_CONTROL + 200,
    )
    private var interestingFolder: File? = null

    @Parameter(
      names = ["--finding-folder"],
      description = "folder to save the findings",
      order = FlagOrder.GENERAL_CONTROL + 300,
    )
    private var findingFolder: File? = null

    @Parameter(
      names = ["--temp-folder"],
      description = "folder to save temp files",
      order = FlagOrder.GENERAL_CONTROL + 400,
    )
    private var tempFolder: File? = null

    @Parameter(
      names = ["--threads"],
      description = "number of fuzzing threads",
      order = FlagOrder.GENERAL_CONTROL + 500,
    )
    var numOfThreads = 1

    @JvmField
    @Parameter(
      names = ["--max-iterations"],
      description = "The max number of testing iterations",
      order = FlagOrder.GENERAL_CONTROL + 600,
      hidden = true,
    )
    var maxNumberOfTestingIterations = Int.MAX_VALUE

    @Parameter(
      names = ["--timeout"],
      description = "Time limit for fuzzing (second)",
      order = FlagOrder.GENERAL_CONTROL + 700,
    )
    var timeout: Long = 0

    @Parameter(
      names = ["--shuffle-seed"],
      arity = 1,
      description = "shuffle the seed files",
      order = FlagOrder.GENERAL_CONTROL + 800,
    )
    var shuffleSeeds = true

    @Parameter(
      names = ["--language-model"],
      description = "language model to guide the scheduler. " +
        "Now only two options are valid: ngram and" +
        " ndepth tree model",
      order = FlagOrder.GENERAL_CONTROL + 900,
    )
    var languageModelType = LanguageModelType.NULL_MODEL

    @Parameter(
      names = ["--extension-script"],
      hidden = true,
      description = "an extension script to do customization work on generated mutants.",
      order = FlagOrder.GENERAL_CONTROL + 1000,
    )
    var extensionScript: Path? = null

    @Parameter(
      names = ["--extension-result-folder"],
      hidden = true,
      description = "the result folder for the extension script",
      order = FlagOrder.GENERAL_CONTROL + 1100,
    )
    var extensionScriptResultFolder: Path? = null

    @Parameter(
      names = ["--fuzzer-mode"],
      description = "the mode to run",
      order = FlagOrder.GENERAL_CONTROL + 1200,
    )
    var fuzzerMode = FuzzerMode.NORMAL_FUZZING

    @Parameter(
      names = ["--mutants-folder"],
      description = "folder to save generated mutants",
      order = FlagOrder.GENERAL_CONTROL + 1300,
    )
    private var mutantsFolder: File? = null

    @Parameter(
      names = ["--no-initial-seed"],
      description = "fuzzing with no initial seed",
      arity = 1,
      order = FlagOrder.GENERAL_CONTROL + 1400,
    )
    var noInitialSeed = false

    @Parameter(
      names = ["--max-seed-pool-size"],
      description = "the maximum size of seed pool",
      order = FlagOrder.GENERAL_CONTROL + 1500,
    )
    var maxSeedPoolSize = Int.MAX_VALUE

    @Parameter(
      names = ["--allow-enable-guidance"],
      description = "allow to enable guidance, only effective when use n-depth tree model",
      arity = 1,
      order = FlagOrder.GENERAL_CONTROL + 1600,
    )
    var allowToEnableGuidance = true
    fun getMutantsFolder(): File {
      if (mutantsFolder == null) {
        mutantsFolder = File(
          "kitten/default_mutants_folder_" +
            Preconditions.checkNotNull<String>(testingConfiguration!!.language),
        )
      }
      if (!mutantsFolder!!.exists()) {
        Preconditions.checkState(mutantsFolder!!.mkdirs())
      }
      return mutantsFolder!!
    }

    fun getInterestingFolder(): File {
      if (interestingFolder == null) {
        interestingFolder = File(
          "kitten/default_interesting_folder_" +
            Preconditions.checkNotNull<String>(testingConfiguration!!.language),
        )
      }
      if (!interestingFolder!!.exists()) {
        Preconditions.checkState(interestingFolder!!.mkdirs())
      }
      return interestingFolder!!
    }

    fun setFindingFolder(findingFolder: File?) {
      Preconditions.checkArgument(this.findingFolder == null)
      this.findingFolder = findingFolder
    }

    fun getFindingFolder(): File {
      if (findingFolder == null) {
        findingFolder = File(
          "kitten/default_finding_folder_" +
            Preconditions.checkNotNull<String>(testingConfiguration!!.language),
        )
      }
      if (!findingFolder!!.exists()) {
        Preconditions.checkState(findingFolder!!.mkdirs())
      }
      return findingFolder!!
    }

    fun getTempFolder(): File {
      if (tempFolder == null) {
        tempFolder = File(
          "kitten/default_temp_folder_" +
            Preconditions.checkNotNull<String>(testingConfiguration!!.language),
        )
      }
      if (!tempFolder!!.exists()) {
        Preconditions.checkState(tempFolder!!.mkdirs())
      }
      return tempFolder!!
    }

    override fun validate() {
      Preconditions.checkState(
        getFindingFolder().isDirectory,
        "The finding folder is not a directory: %s",
        getFindingFolder(),
      )
      Preconditions.checkState(
        getTempFolder().isDirectory,
        "The temp folder is not a directory: %s",
        getTempFolder(),
      )
      Preconditions.checkState(numOfThreads > 0)
      Preconditions.checkState(extensionScript == null == (extensionScriptResultFolder == null))
      Preconditions.checkState(!noInitialSeed || languageModelType !== LanguageModelType.NULL_MODEL)
    }
  }

  class MutationControl : AbstractCommandLineFlagGroup(groupName = "Mutation Control") {
    @Parameter(
      names = ["--max-recursions"],
      description = "The max depth of recursive mutation",
      order = FlagOrder.MUTATION_CONTROL,
    )
    var maxRecursionDepth = 0

    @Parameter(
      names = ["--generator"],
      description = "the generator to use. Now only two options are valid: random and guided",
      order = FlagOrder.MUTATION_CONTROL + 100,
    )
    var generatorType = SparTreeGeneratorType.NULL_GENERATOR

    @Parameter(
      names = ["--enable-replace-with-generated-node"],
      description = "enable replacing with generated node mutation",
      order = FlagOrder.MUTATION_CONTROL + 200,
    )
    var enableReplacingWithGeneratedNode = true

    @Parameter(
      names = ["--enable-splicing"],
      arity = 1,
      description = "enable splicing mutation",
      order = FlagOrder.MUTATION_CONTROL + 300,
    )
    var enableSplicing = true

    @Parameter(
      names = ["--enable-deleting-on-random-positions"],
      arity = 1,
      description = "enable deleting mutation on random positions",
      order = FlagOrder.MUTATION_CONTROL + 400,
    )
    var enableDeletingOnRandomPositions = false

    @Parameter(
      names = ["--enable-deleting-on-continuous-positions"],
      arity = 1,
      description = "enable deleting tokens on continuous positions",
      order = FlagOrder.MUTATION_CONTROL + 500,
    )
    var enableDeletingOnContinuousPositions = false

    @Parameter(
      names = ["--enable-inserting-on-random-positions"],
      arity = 1,
      description = "enable inserting mutation on random positions",
      order = FlagOrder.MUTATION_CONTROL + 600,
    )
    var enableInsertingOnRandomPositions = false

    @Parameter(
      names = ["--enable-inserting-on-continuous-positions"],
      arity = 1,
      description = "enable inserting tokens on continuous positions",
      order = FlagOrder.MUTATION_CONTROL + 700,
    )
    var enableInsertingOnContinuousPositions = false

    @Parameter(
      names = ["--enable-replacing-on-random-positions"],
      arity = 1,
      description = "enable replacing tokens on random positions",
      order = FlagOrder.MUTATION_CONTROL + 800,
    )
    var enableReplacingOnRandomPositions = false

    @Parameter(
      names = ["--enable-replacing-on-continuous-positions"],
      arity = 1,
      description = "enable replacing tokens on continuous postions",
      order = FlagOrder.MUTATION_CONTROL + 900,
    )
    var enableReplacingOnContinuousPositions = false

    @Parameter(
      names = ["--enable-replacing-identifier"],
      arity = 1,
      description = "enable replacing identifier mutation",
      order = FlagOrder.MUTATION_CONTROL + 1000,
    )
    var enableReplacingIdentifier = true

    @Parameter(
      names = ["--enable-replacing-same-type-token"],
      arity = 1,
      description = "enable replacing same type token mutation",
      order = FlagOrder.MUTATION_CONTROL + 1100,
    )
    var enableReplacingSameTypeToken = false

    @Parameter(
      names = ["--enable-deleting-children-of-kleene-node"],
      arity = 1,
      description = "enable deleting children of kleene plus/star nodes mutation",
      order = FlagOrder.MUTATION_CONTROL + 1200,
    )
    var enableDeletingChildrenOfKleeneNode = false

    @Parameter(
      names = ["--enable-inserting-children-of-kleene-node"],
      arity = 1,
      description = "enable inserting children of kleene plus/star nodes mutation",
      order = FlagOrder.MUTATION_CONTROL + 1300,
    )
    var enableInsertingChildrenOfKleeneNode = false
    override fun validate() {
      Preconditions.checkState(
        (
          generatorType !== SparTreeGeneratorType.NULL_GENERATOR &&
            enableReplacingWithGeneratedNode || enableReplacingIdentifier ||
            enableSplicing || maxRecursionDepth > 0
          ) || enableDeletingOnRandomPositions ||
          enableDeletingOnContinuousPositions ||
          enableInsertingOnRandomPositions ||
          enableInsertingOnContinuousPositions ||
          enableReplacingOnRandomPositions ||
          enableReplacingOnContinuousPositions ||
          enableReplacingSameTypeToken ||
          enableDeletingChildrenOfKleeneNode ||
          (
            generatorType !== SparTreeGeneratorType.NULL_GENERATOR &&
              enableInsertingChildrenOfKleeneNode
            ),
        "At least one mutation need to be enabled.",
      )
    }
  }

  class CompilerFlagGroup : AbstractCommandLineFlagGroup(groupName = "Compiler Control") {
    @Parameter(
      names = ["--testing-config"],
      description = "an YAML file specifying compilers and seed files",
      required = true,
      converter = TestingConfigurationConverter::class,
      order = FlagOrder.COMPILER_CONTROL,
    )
    var testingConfiguration: TestingConfiguration? = null
    override fun validate() {
      testingConfiguration!!.validate()
    }

    class TestingConfigurationConverter : IStringConverter<TestingConfiguration> {
      override fun convert(path: String): TestingConfiguration {
        return readFrom(Paths.get(path))
      }
    }
  }

  class CoverageFlagGroup : AbstractCommandLineFlagGroup(groupName = "Coverage") {
    @Parameter(
      names = ["--coverage-info"],
      description = "an directory that contains gcov information",
      order = FlagOrder.COVERAGE_CONTROL,
    )
    var coverageInfoPath: Path? = null

    @Parameter(
      names = ["--compiler-source"],
      description = "the directory that contains the source of the target compiler",
      order = FlagOrder.COVERAGE_CONTROL + 10,
    )
    var compilerSourcePath: Path? = null

    @Parameter(
      names = ["--compiler-binary"],
      description = "the directory that contains the binary of the target compiler",
      order = FlagOrder.COVERAGE_CONTROL + 20,
    )
    var compilerBinaryDir: Path? = null

    @Parameter(
      names = ["--coverage-interval"],
      description = "this parameter controls how frequency the coverage information is queried",
      order = FlagOrder.COVERAGE_CONTROL + 30,
    )
    var coverageMonitorInterval: Long = 30

    @Parameter(
      names = ["--coverage-save"],
      description = "the path that the coverage result saved at",
      order = FlagOrder.COVERAGE_CONTROL + 40,
    )
    private var coverageResultFile_: Path? = null

    fun getCoverageResultFile(): Path? {
      if (coverageInfoPath != null && compilerSourcePath != null || aflCoverageMode) {
        if (coverageResultFile_ == null) {
          coverageResultFile_ = Paths.get("kitten/temp_coverage")
        }
        coverageResultFile_!!.let {
          if (Files.notExists(it)) {
            Util.ensureDirExists(it.parent)
            Files.createFile(it)
          }
        }
      }
      return coverageResultFile_
    }

    @Parameter(
      names = ["--llvm-path"],
      description = "a directory that contains llvm binary for coverage collection",
      order = FlagOrder.COVERAGE_CONTROL,
    )
    var llvmBinaryDir: Path? = null

    @Parameter(
      names = ["--afl-coverage-mode"],
      description = "enable afl coverage collection mode, " +
        "the target should be compiled by afl-wrapped" +
        " compiler",
      order = FlagOrder.COVERAGE_CONTROL + 50,
      arity = 1,
    )
    var aflCoverageMode = false

    @Parameter(
      names = ["--gcc-coverage-mode"],
      description = "enable gcc coverage collection mode, " +
        "gcc should be compiled with '--enable-coverage'",
      order = FlagOrder.COVERAGE_CONTROL + 60,
      arity = 1,
    )
    var gccCoverageMode = false

    @Parameter(
      names = ["--rustc-coverage-mode"],
      description = "enable rustc coverage collection mode",
      order = FlagOrder.COVERAGE_CONTROL + 70,
      arity = 1,
    )
    var ruscCoverageMode = false

    @Parameter(
      names = ["--coverage-timeout"],
      description = "Time limit for coverage collection in seconds",
      order = FlagOrder.COVERAGE_CONTROL + 75,
    )
    var coverageTimeout: Long = 24 * 60 * 60

    override fun validate() {
      if (coverageInfoPath != null && !gccCoverageMode) {
        Preconditions.checkState(compilerSourcePath != null)
        Preconditions.checkState(Files.isDirectory(compilerSourcePath))
        Preconditions.checkState(Files.isDirectory(coverageInfoPath))
      }
    }
  }

  val testingConfiguration: TestingConfiguration?
    get() {
      compilerFlags.validate()
      return compilerFlags.testingConfiguration
    }

  private object FlagOrder {
    const val GENERAL_CONTROL = 10000
    const val MUTATION_CONTROL = 20000
    const val COMPILER_CONTROL = 30000
    const val COVERAGE_CONTROL = 40000
  }
}
