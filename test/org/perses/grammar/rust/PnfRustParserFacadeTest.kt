package org.perses.grammar.rust

import com.google.common.truth.Truth
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import java.io.File

@RunWith(JUnit4::class)
class PnfRustParserFacadeTest {
  val facade = PnfRustParserFacade()

  // Collection for keeping track of the shards of tests we need to run
  private companion object testData {
    val shard1 = mutableListOf<File>()
    val shard2 = mutableListOf<File>()
    val shard3 = mutableListOf<File>()
    val shard4 = mutableListOf<File>()
    val shard5 = mutableListOf<File>()
    val shard6 = mutableListOf<File>()

    init {
      var counter = 0
      val files = listOf(shard1, shard2, shard3, shard4, shard5, shard6)
      for (file in TestUtility.getRustTestFiles()) {
        files.get(counter % files.size).add(file)
        counter += 1
      }
    }
  }

  fun testString(program: String, name: String) {
    val parseTreeFromOrigParser = facade.parseWithOrigRustParser(program, name)
    val tokensByOrigParser = TestUtility.extractTokens(parseTreeFromOrigParser.tree)

    val parseTreeWithPnfParser = facade.parseString(program, name)
    val tokensByPnfParser = TestUtility.extractTokens(parseTreeWithPnfParser.tree)

    Truth.assertThat(tokensByPnfParser).containsExactlyElementsIn(tokensByOrigParser).inOrder()
  }

  fun testSingleFile(file: File) {
    /* 
    try {
      System.err.println("Testing file ${file.getAbsolutePath()}")
      val check = file.readText()

      testString(check, file.toString())
    } catch (err : java.io.FileNotFoundException) {
      // Suppress missing files (there's some strangeness with java and Unicode file names).
    }
    */
  }

  @Test
  fun testShard1() {
    for (file in testData.shard1) {
      testSingleFile(file)
    }
  }

  @Test
  fun testShard2() {
    for (file in testData.shard2) {
      testSingleFile(file)
    }
  }

  @Test
  fun testShard3() {
    for (file in testData.shard3) {
      testSingleFile(file)
    }
  }

  @Test
  fun testShard4() {
    for (file in testData.shard4) {
      testSingleFile(file)
    }
  }

  @Test
  fun testShard5() {
    for (file in testData.shard5) {
      testSingleFile(file)
    }
  }

  @Test
  fun testShard6() {
    for (file in testData.shard6) {
      testSingleFile(file)
    }
  }

  @Test
  fun basicTest() {

    val program =
      """
    |fn main() {
    |  // Statements here are executed when the compiled binary is called
    |
    |  // Print text to the console
    |  println!("Hello World!");
    |}
    """.trimMargin()

    testString(program, "<in memory>")
  }
}
