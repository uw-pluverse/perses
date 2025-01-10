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

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import com.google.common.io.Files
import org.perses.fuzzer.compilers.AbstractCompilerConfigurationFacade
import org.perses.fuzzer.compilers.DefaultCompilationConfigurationFacade
import org.perses.fuzzer.compilers.ICompilationAction
import org.perses.fuzzer.compilers.ICompilerCrashDetector
import org.perses.fuzzer.config.SeedFolder
import org.perses.fuzzer.config.TestingConfiguration
import org.perses.fuzzer.coveragecollector.CoverageCollectorFactory
import org.perses.fuzzer.coveragecollector.ICoverageCollector
import org.perses.fuzzer.languagemodel.AbstractLanguageModel
import org.perses.fuzzer.languagemodel.LanguageModelType
import org.perses.fuzzer.languagemodel.NDepthTreeModel
import org.perses.fuzzer.languagemodel.NullLanguageModel
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.grammar.CompositeParserFacadeFactory
import org.perses.grammar.SingleParserFacadeFactory
import org.perses.grammar.adhoc.AdhocParserFacadeFactoryUtil
import org.perses.program.TokenizedProgram
import org.perses.program.printer.SingleTokenPerLinePrinter
import org.perses.spartree.GuidedSparTreeGenerator
import org.perses.spartree.RandomSparTreeGenerator
import org.perses.spartree.SparTreeGeneratorType
import org.perses.util.AutoDeletableFolder
import org.perses.util.DaemonThreadPool
import org.perses.util.TimeUtil
import org.perses.util.ifEnabled
import org.perses.util.ktAt
import org.perses.util.ktInfo
import java.io.File
import java.io.IOException
import java.nio.file.FileVisitResult
import java.nio.file.Path
import java.nio.file.SimpleFileVisitor
import java.nio.file.attribute.BasicFileAttributes
import java.util.Random
import java.util.concurrent.Executors
import java.util.concurrent.Future
import java.util.concurrent.TimeUnit
import java.util.concurrent.atomic.AtomicInteger
import java.util.logging.Level
import kotlin.io.path.appendText
import kotlin.io.path.isDirectory
import kotlin.io.path.name

class FuzzerDriver(
  options: CommandOptions,
  private val control: AdditionalFuzzerControl,
) : AutoCloseable {

  val parserFacadeFactory = CompositeParserFacadeFactory(
    builtinFactory = SingleParserFacadeFactory.builderWithBuiltinLanguages().build(),
    extFactory = AdhocParserFacadeFactoryUtil.createParserFacadeFactory(
      options.languageExtFlags.languageJarFiles,
    ),
  )
  val testingConfiguration = options.testingConfiguration!!
  val facades = createFacadeList(
    testingConfiguration,
    parserFacadeFactory,
  )
  val extension: AbstractExtensionScript = if (options.generalFlags.extensionScript == null) {
    NullExtensionScript()
  } else {
    ExtensionScript(
      options.generalFlags.extensionScript!!,
      options.generalFlags.extensionScriptResultFolder!!,
    )
  }

  private val tempFolder = options.generalFlags.getTempFolder()
  private val mutantsFolder = options.generalFlags.getMutantsFolder()
  private val interestingFolder = options.generalFlags.getInterestingFolder()

  @VisibleForTesting
  val findingFolder: FindingFolder
  private val random = Random(options.generalFlags.randomSeed)

  private val successfullyCreatedMutantCounter = AtomicInteger(0)
  private val mutationOperationCounter = AtomicInteger(0)
  private val numberOfGeneratedTreeFuzzer = AtomicInteger(0)

  private val numOfThreads = options.generalFlags.numOfThreads
  private val executor = Executors.newFixedThreadPool(options.generalFlags.numOfThreads)
  private val timeout = options.generalFlags.timeout
  private val fuzzerMode = options.generalFlags.fuzzerMode
  private val noInitialSeed = options.generalFlags.noInitialSeed
  private val maxSeedPoolSize = options.generalFlags.maxSeedPoolSize
  private val allowToEnableGuidance = options.generalFlags.allowToEnableGuidance

  private val shuffleSeeds = options.generalFlags.shuffleSeeds
  private val languageKind = parserFacadeFactory
    .computeLanguageKindWithLanguageNameIgnoreCase(
      testingConfiguration.language,
    )!!
  val parserFacade = parserFacadeFactory.getParserFacadeListForOrNull(languageKind)!!
    .defaultParserFacade.create()
  private val languageModel: AbstractLanguageModel =
    when (options.generalFlags.languageModelType) {
      LanguageModelType.NULL_MODEL -> NullLanguageModel(parserFacade)
      LanguageModelType.N_GRAM_MODEL -> error("N_GRAM_MODEL is unavailable for now")
      LanguageModelType.N_DEPTH_TREE_MODEL ->
        NDepthTreeModel(contextSizeLimit = 3, parserFacade, allowToEnableGuidance)
      else -> error("invalid language model option.")
    }
  private val generator = when (options.mutationControl.generatorType) {
    SparTreeGeneratorType.NULL_GENERATOR -> null
    SparTreeGeneratorType.RANDOM_GENERATOR -> {
      RandomSparTreeGenerator(parserFacade, random)
    }
    SparTreeGeneratorType.GUIDED_GENERATOR -> {
      if (languageModel is NDepthTreeModel) {
        GuidedSparTreeGenerator(
          parserFacade,
          random,
          languageModel,
        )
      } else {
        error("The language model selected cannot guide the generator")
      }
    }
    else -> error("Unreachable")
  }
  private val scheduler: FuzzingScheduler
  private val coverageCollector: ICoverageCollector =
    CoverageCollectorFactory().getCoverageCollector(options.coverageFlags)
  private val coverageFile = options.coverageFlags.getCoverageResultFile()

  private val mutationOperatorExecutor: MutationOperatorExecutor

  fun run() {
    if (scheduler.fuzzerInstances.getSize() == 0 && !noInitialSeed) {
      logger.atWarning().log("No seeds. Exiting.")
      return
    }
    when (fuzzerMode) {
      FuzzerMode.ONLY_ON_INITIAL_SEED -> {
        runInitialSeeds()
      }
      FuzzerMode.ONLY_GENERATE_MUTANTS -> {
        startCreatingMutants()
      }
      FuzzerMode.NORMAL_FUZZING -> {
        startFuzzing()
      }
    }
  }

  private fun startCreatingMutants() {
    val iterationCounter = AtomicInteger()
    val startTime = System.currentTimeMillis()
    for (i in 1..numOfThreads) {
      executor.submit {
        while (true) {
          if (timeout > 0 && System.currentTimeMillis() - startTime >= timeout * 1000) {
            break
          }
          try {
            val currentIteration = iterationCounter.incrementAndGet()
            val treeFuzzer = scheduler.next() ?: continue
            createMutants(treeFuzzer)
            if (currentIteration % 100 == 0) {
              logger.ktInfo { "Generated $currentIteration mutants" }
            }
          } catch (e: InterruptedException) {
            Thread.currentThread().interrupt()
          } catch (e: Throwable) {
            logger.atSevere().withCause(e).log("Exception occurred. %s", e)
            e.printStackTrace()
          }
        }
      }
      Thread.sleep(TimeUnit.SECONDS.toMillis(30))
      DaemonThreadPool.waitInfinitelyToShutdown(executor)
    }
  }

  private fun startFuzzing() {
    val iterationCounter = AtomicInteger()
    val coverageCollectorExecutor = coverageCollector.launch()
    if (noInitialSeed && generator != null) {
      generateNewInstances(maxSeedPoolSize)
    }
    for (i in 1..numOfThreads) {
      executor.submit {
        coverageCollector.registerForThread()
        val startTime = System.currentTimeMillis()
        while (true) {
          if (timeout > 0 && System.currentTimeMillis() - startTime >= timeout * 1000) {
            break
          }
          try {
            val currentIteration = iterationCounter.incrementAndGet()
            if (currentIteration > control.maxNumberOfTestingIterations) {
              break
            }
            val treeFuzzer = scheduler.next() ?: continue
            testWithFuzzer(treeFuzzer)
          } catch (e: InterruptedException) {
            Thread.currentThread().interrupt()
            break
          } catch (e: Throwable) {
            logger.atSevere().withCause(e).log("Exception occurred. %s", e)
            e.printStackTrace()
          }
          logger.atInfo().ifEnabled {
            it.atMostEvery(30, TimeUnit.SECONDS)
              .log("Status of guidance: ${scheduler.model.guidanceEnabled}")
          }
          logger.atInfo().ifEnabled {
            it.atMostEvery(30, TimeUnit.SECONDS)
              .log("Number of generated mutants: ${successfullyCreatedMutantCounter.get()}")
          }
          logger.atInfo().ifEnabled {
            it.atMostEvery(30, TimeUnit.SECONDS)
              .log("Queue size: ${scheduler.fuzzerInstances.content.size}")
          }
          logger.atInfo().ifEnabled {
            it.atMostEvery(30, TimeUnit.SECONDS)
              .log("Size of language model database: ${languageModel.size}")
          }
          logger.atInfo().ifEnabled {
            it.atMostEvery(30, TimeUnit.SECONDS)
              .log("Number of obsoleted seeds: ${scheduler.numberOfObsoletedInstances}")
          }
        }
        coverageCollector.closeForThread()
      }
    }
    Thread.sleep(TimeUnit.SECONDS.toMillis(30))
    DaemonThreadPool.waitInfinitelyToShutdown(executor)
    coverageCollectorExecutor?.let {
      DaemonThreadPool.waitInfinitelyToShutdown(it)
    }
    logger.ktInfo { "Totally generated ${successfullyCreatedMutantCounter.get()} mutants." }
    logger.ktInfo { "Queue size: ${scheduler.fuzzerInstances.getSize()}" }
    logger.ktInfo {
      "Size of the dataset of the model: ${scheduler.model.size}"
    }
    logger.ktInfo {
      "Number of obsoleted seeds: ${scheduler.numberOfObsoletedInstances}"
    }
    if (coverageFile != null && !coverageFile.isDirectory()) {
      coverageFile.appendText(
        "Totally generated ${successfullyCreatedMutantCounter.get()} mutants.\n",
      )
      coverageFile.appendText(
        "Queue size: ${scheduler.fuzzerInstances.getSize()}\n",
      )
      coverageFile.appendText(
        "Size of the dataset of the model: ${scheduler.model.size}\n",
      )
      coverageFile.appendText(
        "Number of obsoleted seeds: ${scheduler.numberOfObsoletedInstances}\n",
      )
      coverageFile.appendText(
        languageModel.printDatabase(),
      )
    }
  }

  private fun runInitialSeeds() {
    val iterationCounter = AtomicInteger()
    for (i in 1..numOfThreads) {
      executor.submit {
        coverageCollector.registerForThread()
        while (true) {
          try {
            val currentIteration = iterationCounter.incrementAndGet()
            val fuzzerInstances = scheduler.fuzzerInstances.content
            if (currentIteration >= fuzzerInstances.size) {
              break
            }
            logger.ktInfo {
              "seed: $currentIteration => " +
                fuzzerInstances[currentIteration].printFeatureOfSparTree()
            }
            for (facade in facades) {
              for (action in facade.compilationActions) {
                coverageCollector.executeActionWithCoverageCollection(
                  action,
                  fuzzerInstances[currentIteration].seedFile,
                  Thread.currentThread().id,
                )
              }
            }
          } catch (e: InterruptedException) {
            Thread.currentThread().interrupt()
            break
          } catch (e: Throwable) {
            logger.atSevere().withCause(e).log("Exception occurred. %s", e)
            e.printStackTrace()
          }
        }
        coverageCollector.closeForThread()
      }
    }
    Thread.sleep(TimeUnit.SECONDS.toMillis(30))
    DaemonThreadPool.waitInfinitelyToShutdown(executor)
    logger.ktInfo { scheduler.model.printDatabase() }
    logger.ktInfo { "Number of initial seeds: ${scheduler.fuzzerInstances.getSize()}" }
    logger.ktInfo {
      "Average number of feature nodes in a spar tree: " +
        "${languageModel.getAverageNumberOfFeatureNodesOfSparTree()}"
    }
    logger.ktInfo {
      "Size of the dataset of the model: ${languageModel.size}"
    }
    logger.ktInfo {
      "Number of edges triggered by initial seeds: ${coverageCollector.getCoverageReport()}"
    }
  }

  private fun createMutants(treeFuzzer: SparTreeFuzzer) {
    val seedFile = treeFuzzer.seedFile
    logger.ktAt(Level.FINE) { "mutating with $seedFile" }
    for (i in 1..10) {
      logger.ktAt(Level.FINE) {
        "Generating the $i-th mutant from the seed file $seedFile"
      }
      val mutatedProgram =
        mutationOperatorExecutor.mutateWithoutSavingTreeStructure(treeFuzzer) ?: return
      val mutantFile = File(
        mutantsFolder,
        "mutant_${mutationOperationCounter.incrementAndGet()}_${System.currentTimeMillis()}." +
          Files.getFileExtension(seedFile.name),
      )
      mutatedProgram.writeToFile(mutantFile)
      extension.run(mutantFile.toPath())
    }
  }

  private fun generateNewInstances(limit: Int) {
    val futures = ArrayList<Future<*>>()
    for (i in 1..numOfThreads) {
      futures.add(
        executor.submit {
          while (scheduler.fuzzerInstances.getSize() < limit
          ) {
            generateNewInstanceAndAddToFuzzerInstances()
          }
        },
      )
    }
    futures.forEach {
      it.get(30, TimeUnit.SECONDS)
    }
  }

  private fun generateNewInstanceAndAddToFuzzerInstances() {
    assert(generator != null)
    val generatedTree = generator!!.generateFromStartSymbol() ?: return
    val generatedSource = SingleTokenPerLinePrinter.print(generatedTree.programSnapshot).sourceCode
    val generatedFile = File(
      interestingFolder,
      "generated_${numberOfGeneratedTreeFuzzer.getAndIncrement()}." +
        languageKind.extensions.first(),
    )
    if (numberOfGeneratedTreeFuzzer.get() % 100 == 0) {
      logger.ktInfo { "Successfully generated $numberOfGeneratedTreeFuzzer instances." }
    }
    generatedFile.writeText(generatedSource)
    val newTreeFuzzer = SparTreeFuzzer
      .fromSparTree(parserFacade, generatedFile, generatedTree)
    scheduler.updateOnNewSeed(newTreeFuzzer)
    scheduler.fuzzerInstances.add(newTreeFuzzer)
  }

  private fun testWithFuzzer(treeFuzzer: SparTreeFuzzer) {
    val seedFile = treeFuzzer.seedFile
    val seedProgram = treeFuzzer.seedProgram

    logger.ktAt(Level.FINE) { "mutating with $seedFile" }
    val numOfTreeLevelMutationToApply = scheduler.getTreeLevelMutationTimes(treeFuzzer)
    val numOfTokenLevelMutationToApply = scheduler.getTokenLevelMutationTimes(treeFuzzer)
    val numberOfMutantsToGenerate = numOfTreeLevelMutationToApply + numOfTokenLevelMutationToApply
    for (i in 1..numberOfMutantsToGenerate) {
      logger.ktAt(Level.FINE) {
        "Generating the $i-th mutant from the seed file $seedFile"
      }
      createMutationFolder().use { mutantFolder ->
        val mutantFile = File(
          mutantFolder.file.toFile(),
          "mutant." +
            Files.getFileExtension(seedFile.name),
        )
        if (i <= numOfTreeLevelMutationToApply) {
          val mutationResult =
            mutationOperatorExecutor.mutateWithTreeLevelMutation(treeFuzzer) ?: return@use
          mutantFile.writeText(mutationResult.mutatedSource)
          for (facade in facades) {
            for (action in facade.compilationActions) {
              testActionOnMutant(action, mutantFile, seedFile, seedProgram, facade.crashDetector)
            }
          }
          scheduler.update(mutationResult.mutatedSparTree!!, mutantFile)
        } else {
          val mutationResult =
            mutationOperatorExecutor.mutateWithTokenLevelMutation(treeFuzzer) ?: return@use
          mutantFile.writeText(mutationResult.mutatedSource)
          for (facade in facades) {
            for (action in facade.compilationActions) {
              testActionOnMutant(action, mutantFile, seedFile, seedProgram, facade.crashDetector)
            }
          }
        }
        successfullyCreatedMutantCounter.incrementAndGet()
        logger.ktAt(Level.FINE) { "running extension on the mutant $mutantFile" }
        extension.run(mutantFile.toPath())
      }
    }
  }

  @VisibleForTesting
  fun testActionOnMutant(
    action: ICompilationAction,
    mutantFile: File,
    seedFile: File,
    seedProgram: TokenizedProgram,
    crashDetector: ICompilerCrashDetector,
  ) {
    val result = coverageCollector.executeActionWithCoverageCollection(
      action,
      mutantFile,
      Thread.currentThread().id,
    )
    logger.ktAt(Level.FINE) { "test cmd: ${result.cmd}" }
    logger.ktAt(Level.FINE) { "stderr: ${result.cmdOutput.stderr.combinedLines}" }
    val crashDetectorResult = crashDetector.detectCrash(result.cmdOutput)
    if (crashDetectorResult.isCrashDetected()) {
      logger.ktAt(Level.FINE) {
        "A crash has been found with the seed file $seedFile"
      }
      CrashInstanceFolder.create(
        findingFolder,
        seedProgram,
        mutantFile,
        result,
        action,
        crashDetectorResult.asCrash(),
      )
    }
  }

  override fun close() {
    DaemonThreadPool.shutdownOrThrow(executor)
  }

  private fun createSparTreeFuzzers(
    seedFiles: ImmutableList<File>,
    numberLimitOfSeedFiles: Int,
  ): ArrayList<SparTreeFuzzer> {
    val result = ArrayList<SparTreeFuzzer>()
    var failedCounter = 0
    var passedCounter = 0
    val totalCount = seedFiles.size
    val shuffledSeedFiles = seedFiles.shuffled(random)
    for (seedWithIndex in shuffledSeedFiles.withIndex()) {
      val seed = seedWithIndex.value
      val index = seedWithIndex.index + 1
      try {
        if (passedCounter >= numberLimitOfSeedFiles) {
          logger.ktInfo { "Reached the limit of seed files: $numberLimitOfSeedFiles" }
          break
        }
        val future = executor.submit<SparTreeFuzzer> {
          logger.ktAt(Level.FINE) { "Parsing($index/$totalCount) $seed" }
          SparTreeFuzzer.fromFile(
            parserFacade,
            seed,
            isInitial = true,
          )
        }
        result.add(future.get(1, TimeUnit.SECONDS))
        ++passedCounter
        logger.ktAt(Level.FINE) { "Parsed($index/$totalCount) $seed" }
      } catch (e: Exception) {
        ++failedCounter
        e.printStackTrace()
        logger.atSevere().withCause(e).log("Failed to parse(%s/%s) %s", index, totalCount, seed)
      } catch (e: StackOverflowError) {
        e.printStackTrace()
        ++failedCounter
        logger.atSevere().withCause(e).log("Failed to parse(%s/%s) %s", index, totalCount, seed)
      }
    }
    if (failedCounter != 0) {
      logger.atWarning().log("Failed to parse %s seed files in total.", failedCounter)
    }
    if (shuffleSeeds) {
      result.shuffle(random)
    }
    return result
  }

  private fun createMutationFolder(): AutoDeletableFolder {
    val builder = StringBuilder()
    builder.append("mutant")
    builder.append("_").append(mutationOperationCounter.get())
    builder.append("-t").append(Thread.currentThread().id)
    builder.append(TimeUtil.formatDateForFileName(System.currentTimeMillis()))
    return AutoDeletableFolder(File(tempFolder, builder.toString()).toPath())
  }

  init {
    if (fuzzerMode != FuzzerMode.ONLY_GENERATE_MUTANTS) {
      check(facades.isNotEmpty())
    }
    val seedFolders = options.testingConfiguration!!.seedFolders
    val seedFiles = collectSeedFilesRecursively(
      seedFolders,
    )
    logger.ktInfo {
      "Collected ${seedFiles.size} seed files in folder $seedFolders"
    }
    val fuzzerInstances = if (!noInitialSeed) {
      SparTreeFuzzerQueue(
        createSparTreeFuzzers(
          seedFiles,
          options.generalFlags.numberLimitOfSeedFiles,
        ),
      )
    } else {
      SparTreeFuzzerQueue(emptyList())
    }
    if (generator != null) {
      for (fuzzerInstance in fuzzerInstances.content) {
        generator.updateCorpus(fuzzerInstance.sparTree)
      }
    }
    val mutationFrequencyController = MutationFrequencyController(
      languageModel,
    )
    scheduler = FuzzingScheduler(
      languageModel,
      fuzzerInstances,
      maxSeedPoolSize,
      mutationFrequencyController,
      interestingFolder,
    )
    mutationOperatorExecutor = MutationOperatorExecutor(
      options.mutationControl,
      random,
      generator,
      scheduler,
    )
    logger.ktInfo { "Created ${fuzzerInstances.getSize()} spar-tree fuzzers." }
    findingFolder = FindingFolder(options.generalFlags.getFindingFolder())
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
    fun createFacadeList(
      testingConfiguration: TestingConfiguration,
      parserFacadeFactory: AbstractParserFacadeFactory,
    ): ImmutableList<AbstractCompilerConfigurationFacade> {
      val builder = ImmutableList.builder<AbstractCompilerConfigurationFacade>()
      testingConfiguration.programsUnderTest.forEach { prog ->
        builder.add(
          DefaultCompilationConfigurationFacade(
            languageKind = requireNotNull(
              parserFacadeFactory.computeLanguageKindWithLanguageNameIgnoreCase(
                testingConfiguration.language,
              ),
            ) { "Cannot found language '${testingConfiguration.language}'" },
            programUnderTest = prog,
          ),
        )
      }
      return builder.build()
    }

    fun getMutantFileName(seedFileName: String) =
      "mutant." + Files.getFileExtension(seedFileName)

    @VisibleForTesting
    fun collectSeedFilesRecursively(
      seedFolders: List<SeedFolder>,
    ): ImmutableList<File> {
      require(seedFolders.isNotEmpty())

      val builder = ArrayList<File>()

      seedFolders.forEach { it ->
        val seedFolder = File(it.path)
        val seedFileNamePostfixList = it.fileExtentions
        check(seedFolder.isDirectory) { seedFolder }

        java.nio.file.Files.walkFileTree(
          seedFolder.toPath(),
          object : SimpleFileVisitor<Path>() {
            @Throws(IOException::class)
            override fun visitFile(file: Path, attrs: BasicFileAttributes): FileVisitResult {
              if (seedFileNamePostfixList.any { file.toFile().name.endsWith(it) }) {
                builder.add(file.toFile())
              }
              return super.visitFile(file, attrs)
            }
          },
        )
      }
      return ImmutableList.sortedCopyOf(builder)
    }
  }
}
