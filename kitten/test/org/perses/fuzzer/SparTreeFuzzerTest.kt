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

import com.google.common.io.Files
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.languagemodel.AbstractLanguageModel
import org.perses.fuzzer.languagemodel.NDepthTreeModel
import org.perses.fuzzer.languagemodel.NullLanguageModel
import org.perses.grammar.SingleParserFacadeFactory
import org.perses.grammar.c.LanguageC
import org.perses.grammar.go.LanguageGo
import org.perses.grammar.java.LanguageJava
import org.perses.grammar.rust.LanguageRust
import org.perses.grammar.rust.PnfRustLexer
import org.perses.program.printer.SingleTokenPerLinePrinter
import org.perses.spartree.RandomSparTreeGenerator
import org.perses.spartree.SparTree
import org.perses.util.TruthExt
import java.io.File
import java.util.Random

/** Test for testing fuzzer.  */
@Suppress("DEPRECATION")
@RunWith(JUnit4::class) // TODO(gaosen): fix this test.
class SparTreeFuzzerTest {
  private val factory = SingleParserFacadeFactory.builderWithBuiltinLanguages().build()
  private val c = factory.getParserFacadeListForOrNull(LanguageC)!!.defaultParserFacade.create()
  private val java = factory.getParserFacadeListForOrNull(
    LanguageJava,
  )!!.defaultParserFacade.create()

  private val rust = factory.getParserFacadeListForOrNull(
    LanguageRust,
  )!!.defaultParserFacade.create()
  private val rustIdentifierTokenId = PnfRustLexer.Ident

  private val go = factory.getParserFacadeListForOrNull(LanguageGo)!!.defaultParserFacade.create()

  @Test
  fun testRandomMutation() {
    val pathname = "kitten/test/fuzzer_test_data/different_lang_test/toy.c"
    val testFile = File(pathname)
    val mutatedFile = File.createTempFile("mutatedFile", ".temp")
    mutatedFile.deleteOnExit()
    val random = Random(1)
    val fuzzer = SparTreeFuzzer.fromFile(c, testFile)
    fuzzer.createMutant(random)
    assert(!Files.equal(testFile, mutatedFile))
  }

  @Test
  fun testSameTokenMutation() {
    val pathname = "kitten/test/fuzzer_test_data/different_lang_test/toy.c"
    val testFile = File(pathname)
    val mutatedFile = File.createTempFile("mutatedFile", ".temp")
    val random = Random(1)
    val fuzzer = SparTreeFuzzer.fromFile(c, testFile)
    fuzzer.createMutantByReplacingSameToken(random)
    assert(!Files.equal(testFile, mutatedFile))
    // delete Temp file
    mutatedFile.deleteOnExit()
  }

  @Test
  fun testDifferentLang() {
    var pathname = "kitten/test/fuzzer_test_data/different_lang_test/toy.c"
    var testFile = File(pathname)
    val random: Random = Random(1)
    var fuzzer = SparTreeFuzzer.fromFile(c, testFile)
    assertThat(fuzzer.createMutant(random).tokens.isEmpty()).isFalse()
    pathname = "kitten/test/fuzzer_test_data/different_lang_test/toy.go"
    testFile = File(pathname)
    fuzzer = SparTreeFuzzer.fromFile(go, testFile)
    assertThat(fuzzer.createMutant(random).tokens.isEmpty()).isFalse()
    pathname = "kitten/test/fuzzer_test_data/different_lang_test/toy.java"
    testFile = File(pathname)
    fuzzer = SparTreeFuzzer.fromFile(java, testFile)
    assertThat(fuzzer.createMutant(random).tokens.isEmpty()).isFalse()
    pathname = "kitten/test/fuzzer_test_data/different_lang_test/toy.rs"
    testFile = File(pathname)
    fuzzer = SparTreeFuzzer.fromFile(rust, testFile)
    assertThat(fuzzer.createMutant(random).tokens.isEmpty()).isFalse()
  }

  @Test
  fun testShuffle() {
    val pathname = "kitten/test/fuzzer_test_data/different_lang_test/toy.rs"
    val testFile: File = File(pathname)
    val fuzzer = SparTreeFuzzer.fromFile(rust, testFile)
    val rn = Random(1)
    val mutant1 = fuzzer.createMutantByReplacingIdentifier(rn)
    val mutant2 = fuzzer.createMutantByReplacingIdentifier(rn)
    assertThat(mutant1).isNotEqualTo(mutant2)
    rust.parseString(mutant1!!.program) // Should not crash.
    rust.parseString(mutant2!!.program) // Should not crash.
  }

  @Test
  fun fuzzerRunAllTests() {
    testRandomMutation()
    testDifferentLang()
  }

  @Test
  fun testRandomRecursiveMutation() {
    val test =
      """
        fn main() {
            if true {
                println!("Hello");
            }
        }
      """.trimIndent()
    val testFile = File.createTempFile("testFile", ".temp").apply { writeText(test) }
    testFile.deleteOnExit()
    val fuzzer = SparTreeFuzzer.fromFile(rust, testFile)
    val rn1 = Random(3)
    val rn2 = Random(5)
    val mutant1 = fuzzer.createMutantByRepeatingRecursion(
      rn1,
      maxRepeatingTimes = 15,
    )
    val mutant2 = fuzzer.createMutantByRepeatingRecursion(
      rn2,
      maxRepeatingTimes = 15,
    )
    val expectedMutant1 =
      """
        |fn main ( ) {
        |if true {
        |if true {
        |if true {
        |if true {
        |if true {
        |println ! ( "Hello" ) ;
        |}
        |}
        |}
        |}
        |}
        |}
      """.trimMargin() + "\n"
    val expectedMutant2 =
      """
        |fn main ( ) { { { { {
        |if true {
        |println ! ( "Hello" ) ;
        |}
        |}
        |}
        |}
        |}
        |}
      """.trimMargin() + "\n"
    assertThat(mutant1!!.program).isEqualTo(expectedMutant1)
    assertThat(mutant2!!.program).isEqualTo(expectedMutant2)
    rust.parseString(mutant1.program)
    rust.parseString(mutant2.program)
  }

  @Test
  fun testSplicingMutation() {
    val test1 =
      """
        fn main() {
            if true {
                println!("yes_splicing_1");
            } else {
                println!("no_splicing_1");
            }
        }
      """.trimIndent()
    val test2 =
      """
        fn main() {
            if true {
                println!("yes_splicing_2");
            } else {
                println!("no_splicing_2");
            }
        }
      """.trimIndent()
    val test3 = ""
    val testFile1 = File.createTempFile("testFile1", ".temp").apply { writeText(test1) }
    testFile1.deleteOnExit()
    val testFile2 = File.createTempFile("testFile2", ".temp").apply { writeText(test2) }
    testFile2.deleteOnExit()
    val testFile3 = File.createTempFile("testFile3", ".temp").apply { writeText(test3) }
    testFile3.deleteOnExit()
    val fuzzer1 = SparTreeFuzzer.fromFile(rust, testFile1)
    val fuzzer2 = SparTreeFuzzer.fromFile(rust, testFile2)
    val fuzzer3 = SparTreeFuzzer.fromFile(rust, testFile3)
    val rn1 = Random(7)
    val mutant1 = fuzzer1.createMutantBySplicing(fuzzer2, rn1)
    val rn2 = Random(3)
    val mutant2 = fuzzer1.createMutantBySplicing(fuzzer2, rn2)
    // The following two cases should be handled properly
    fuzzer1.createMutantBySplicing(fuzzer3, rn1)
    fuzzer3.createMutantBySplicing(fuzzer1, rn1)
    val expectedMutant1 =
      """
        |fn main ( ) {
        |if true {
        |println ! ( "yes_splicing_1" ) ;
        |} else {
        |println ! ( "yes_splicing_2" ) ;
        |}
        |}
      """.trimMargin() + "\n"
    val expectedMutant2 =
      """
        |fn main ( ) {
        |if true {
        |println ! ( "yes_splicing_1" ) ;
        |} else {
        |println ! ( "no_splicing_2" ) ;
        |}
        |}
      """.trimMargin() + "\n"
    assertThat(mutant1!!.program).isEqualTo(expectedMutant1)
    assertThat(mutant2!!.program).isEqualTo(expectedMutant2)
    rust.parseString(mutant1.program)
    rust.parseString(mutant2.program)
  }

  @Test
  fun testReplacingWithGeneratedNode() {
    val test =
      """
        int printf(const char*, ...);
        int main (int argc, char *argv[]) {
          int a = 1;
          int b = a + 1;
          if (b > a) {
            printf("hello\n");
            printf("world\n");
          }
          return 0;
        }
      """.trimIndent()
    val testFile = File.createTempFile("testFile", ".temp").apply { writeText(test) }
    testFile.deleteOnExit()
    val fuzzer = SparTreeFuzzer.fromFile(c, testFile)
    // Following code should not fail
    for (i in 0..100) {
      val rn = Random(i.toLong())
      val generator =
        RandomSparTreeGenerator(c, rn)
      val mutatedProgram = fuzzer.createMutantByReplacingWithGeneratedNode(rn, generator)
      if (mutatedProgram != null) {
        val program = mutatedProgram.program
        // The generated program should be successfully parsed
        c.parseString(program)
      }
    }
  }

  @Test
  fun testCreateMutantByDeletingTokens() {
    val test =
      """
        fn main() {
            if true {
                println!("Hello");
            }
        }
      """.trimIndent()
    val testFile = File.createTempFile("testFile", ".temp").apply { writeText(test) }
    testFile.deleteOnExit()
    val fuzzer = SparTreeFuzzer.fromFile(rust, testFile)
    val rn1 = Random(0)
    val rn2 = Random(2)
    // Test deleting on random positions
    val mutant1 = fuzzer.createMutantByDeletingTokensOnRandomPositions(rn1)
    val mutant2 = fuzzer.createMutantByDeletingTokensOnRandomPositions(rn2)
    val expectedMutant1 =
      """
        |fn main ( {
        |if true {
        |println ! ( )
        |}
        |}
      """.trimMargin() + "\n"
    val expectedMutant2 =
      """
        |fn main ( )
        |if true {
        |println ! ( ) ;
        |}
      """.trimMargin() + "\n"
    assertThat(mutant1!!.program).isEqualTo(expectedMutant1)
    assertThat(mutant2!!.program).isEqualTo(expectedMutant2)
    // Test deleting on continuous positions
    val mutant3 = fuzzer.createMutantByDeletingARangeOfTokens(rn1)
    val mutant4 = fuzzer.createMutantByDeletingARangeOfTokens(rn2)
    val expectedMutant3 =
      """
        |fn main ( ) {
        |if true {
        |println ) ;
        |}
        |}
      """.trimMargin() + "\n"
    val expectedMutant4 =
      """
        |fn main ( ) {
        |if true {
        |println ! (
        |}
        |}
      """.trimMargin() + "\n"
    assertThat(mutant3!!.program).isEqualTo(expectedMutant3)
    assertThat(mutant4!!.program).isEqualTo(expectedMutant4)
  }

  @Test
  fun testCreateMutantByInsertingTokens() {
    val test =
      """
        fn main() {
            if true {
                println!("Hello");
            }
        }
      """.trimIndent()
    val testFile = File.createTempFile("testFile", ".temp").apply { writeText(test) }
    testFile.deleteOnExit()
    val fuzzer = SparTreeFuzzer.fromFile(rust, testFile)
    val rn1 = Random(0)
    val rn2 = Random(2)
    // Test inserting on random positions
    val mutant1 = fuzzer.createMutantByInsertingTokensOnRandomPositions(rn1)
    val mutant2 = fuzzer.createMutantByInsertingTokensOnRandomPositions(rn2)
    val expectedMutant1 =
      """
        |fn main ( )
        |"Hello" {
        |if true {
        |println ; ! ) ( "Hello" ) ;
        |}
        |}
      """.trimMargin() + "\n"
    val expectedMutant2 =
      """
        |"Hello" fn main ( ) {
        |if true { {
        |println ! ( "Hello" )
        |} ;
        |}
        |}
      """.trimMargin() + "\n"
    assertThat(mutant1!!.program).isEqualTo(expectedMutant1)
    assertThat(mutant2!!.program).isEqualTo(expectedMutant2)
    // Test inserting on continuous positions
    val mutant3 = fuzzer.createMutantByInsertingARangeOfTokens(rn1)
    val mutant4 = fuzzer.createMutantByInsertingARangeOfTokens(rn2)
    val expectedMutant3 =
      """
        |fn main ( ) {
        |if true {
        |println ! ( "Hello" println main ! ) ;
        |}
        |}
      """.trimMargin() + "\n"
    val expectedMutant4 =
      """
        |fn main ( ) {
        |if true {
        |println ! ( "Hello" ) ;
        |} fn ;
        |}
        |}
      """.trimMargin() + "\n"
    assertThat(mutant3!!.program).isEqualTo(expectedMutant3)
    assertThat(mutant4!!.program).isEqualTo(expectedMutant4)
  }

  @Test
  fun testCreateMutantByReplacingTokens() {
    val test =
      """
        fn main() {
            if true {
                println!("Hello");
            }
        }
      """.trimIndent()
    val testFile = File.createTempFile("testFile", ".temp").apply { writeText(test) }
    testFile.deleteOnExit()
    val fuzzer = SparTreeFuzzer.fromFile(rust, testFile)
    val rn1 = Random(0)
    val rn2 = Random(2)
    // Test inserting on random positions
    val mutant1 = fuzzer.createMutantByReplacingTokensOnRandomPositions(rn1)
    val mutant2 = fuzzer.createMutantByReplacingTokensOnRandomPositions(rn2)
    val expectedMutant1 =
      """
        |fn
        |"Hello" ( ) {
        |if
        |true
        |{
        |;
        |!
        |(
        |"Hello" )
        |;
        |}
        |}
      """.trimMargin() + "\n"
    val expectedMutant2 =
      """
        |fn
        |"Hello" ( ) { {
        |true
        |{
        |println
        |!
        |(
        |"Hello"
        |)
        |;
        |}
        |}
      """.trimMargin() + "\n"
    assertThat(mutant1!!.program).isEqualTo(expectedMutant1)
    assertThat(mutant2!!.program).isEqualTo(expectedMutant2)
    // Test inserting on continuous positions
    val mutant3 = fuzzer.createMutantByReplacingARangeOfTokens(rn1)
    val mutant4 = fuzzer.createMutantByReplacingARangeOfTokens(rn2)
    val expectedMutant3 =
      """
        |fn main ( ) {
        |if
        |true
        |{
        |println
        |!
        |} ( {
        |;
        |}
        |}
      """.trimMargin() + "\n"
    val expectedMutant4 =
      """
        |fn main ( ) {
        |}
        |println fn
        |println
        |!
        |(
        |"Hello"
        |)
        |;
        |}
        |}
      """.trimMargin() + "\n"
    assertThat(mutant3!!.program).isEqualTo(expectedMutant3)
    assertThat(mutant4!!.program).isEqualTo(expectedMutant4)
  }

  @Test
  fun testCreateMutatedTreeByDeletingChildrenOfKleeneStarOrPlusNode() {
    val test =
      """
        fn main() {
            if true {
                println!("Hello");
                println!("Hello");
            }
            if true {
                println!("Hello");
                println!("Hello");
            }
        }
      """.trimIndent()
    val testFile = File.createTempFile("testFile", ".temp").apply { writeText(test) }
    testFile.deleteOnExit()
    val fuzzer = SparTreeFuzzer.fromFile(rust, testFile)
    val rn1 = Random(0)
    val rn2 = Random(2)
    val mutatedTree1 = fuzzer.createMutatedTreeByDeletingChildrenOfKleeneStarOrPlusNode(rn1)!!
    val mutatedTree2 = fuzzer.createMutatedTreeByDeletingChildrenOfKleeneStarOrPlusNode(rn2)!!
    val mutant1 = SingleTokenPerLinePrinter.print(mutatedTree1.programSnapshot).sourceCode
    val mutant2 = SingleTokenPerLinePrinter.print(mutatedTree2.programSnapshot).sourceCode
    val expectedMutant1 =
      """
        |fn
        |main
        |(
        |)
        |{
        |if
        |true
        |{
        |}
        |}
      """.trimMargin() + "\n"
    val expectedMutant2 =
      """
        |fn
        |main
        |(
        |)
        |{
        |if
        |true
        |{
        |println
        |!
        |(
        |"Hello"
        |)
        |;
        |}
        |if
        |true
        |{
        |println
        |!
        |(
        |"Hello"
        |)
        |;
        |println
        |!
        |(
        |)
        |;
        |}
        |}
      """.trimMargin() + "\n"
    assertThat(mutant1).isEqualTo(expectedMutant1)
    assertThat(mutant2).isEqualTo(expectedMutant2)
  }

  @Test
  fun testCreateMutantByInsertingChildrenOfKleeneStarOrPlusNode() {
    val test =
      """
        fn main() {
            if true {
                println!("Hello");
            }
        }
      """.trimIndent()
    val testFile = File.createTempFile("testFile", ".temp").apply { writeText(test) }
    testFile.deleteOnExit()
    val fuzzer = SparTreeFuzzer.fromFile(rust, testFile)
    val rn1 = Random(0)
    val rn2 = Random(2)
    // Test inserting on random positions
    val generator1 =
      RandomSparTreeGenerator(rust, rn1)
    val generator2 =
      RandomSparTreeGenerator(rust, rn2)
    val mutant1 = fuzzer.createMutantByInsertingChildrenToKleeneStarOrPlusNode(rn1, generator1)!!
    val mutant2 = fuzzer.createMutantByInsertingChildrenToKleeneStarOrPlusNode(rn2, generator2)!!
    TruthExt.assertTrimmedNonBlankLinesEqual(
      mutant1.program,
      "fn main ( ) {",
      "if true {",
      """println ! ( "Hello" [ && ; %= ] ${'$'} ] ) ; """ +
        """; # [ += ${'$'}crate ${'$'} <<= * , impl impl ... ] loop { }""",
      "}",
      "}",
    )
    TruthExt.assertTrimmedNonBlankLinesEqual(
      mutant2.program,
      "fn main ( ) {",
      "if true {",
      """println ! ( "Hello" && ) ; try { }""",
      """} # [ = <<= use ( -> mut ] # [ } default @ > += ${'$'}crate struct ] """ +
        """# [ . >>= <<= use < as [ in unsafe ] # [ ] '""",
      "}",
    )
  }

  @Test
  fun testTreeLevelMutations() {
    val test =
      """
        int printf(const char*, ...);
        int main (int argc, char *argv[]) {
          int a = 1;
          int b = a + 1;
          if (b > a) {
            printf("hello\n");
            printf("world\n");
          }
          return 0;
        }
      """.trimIndent()
    val anotherTest =
      """
        int foo () {
          int a, b = 1;
          return a + b;
        }
      """.trimIndent()
    val testFile = File.createTempFile("testFile", ".temp").apply { writeText(test) }
    testFile.deleteOnExit()
    var languageModel: AbstractLanguageModel = NullLanguageModel(c)
    val anotherTestFile =
      File.createTempFile("anotherTestFile", ".temp").apply { writeText(anotherTest) }
    anotherTestFile.deleteOnExit()
    val fuzzer = SparTreeFuzzer.fromFile(c, testFile)
    // Test Splicing
    val anotherFuzzer = SparTreeFuzzer.fromFile(c, anotherTestFile)
    var mutatedProgram = fuzzer.createMutantBySplicing(anotherFuzzer, Random(0))
    var mutatedTree =
      fuzzer.createMutatedTreeBySplicing(anotherFuzzer, Random(0), languageModel)
    checkEqualityOfTreeAndProgram(mutatedProgram!!, mutatedTree!!)
    // Test generative mutation
    mutatedProgram = fuzzer.createMutantByReplacingWithGeneratedNode(
      random = Random(1),
      generator = RandomSparTreeGenerator(c, Random(0)),
    )
    mutatedTree = fuzzer.createMutatedTreeByReplacingWithGeneratedNode(
      random = Random(1),
      generator = RandomSparTreeGenerator(c, Random(0)),
      model = languageModel,
    )
    checkEqualityOfTreeAndProgram(mutatedProgram!!, mutatedTree!!)
    // Test guided mutations
    languageModel = NDepthTreeModel(
      contextSizeLimit = 4,
      parserFacade = c,
      allowToEnableGuidance = true,
    )
    languageModel.guidanceEnabled = true
    fuzzer.featureOfTheSparTree = languageModel.updateModelAndGetFeatureOfSparTree(fuzzer.sparTree)
    anotherFuzzer.featureOfTheSparTree =
      languageModel.updateModelAndGetFeatureOfSparTree(anotherFuzzer.sparTree)
    mutatedTree = fuzzer.createMutatedTreeBySplicing(
      anotherFuzzer,
      Random(2),
      languageModel,
    )
    assertThat(mutatedTree).isNotNull()
    mutatedTree = fuzzer.createMutatedTreeByReplacingWithGeneratedNode(
      Random(1),
      RandomSparTreeGenerator(c, Random(0)),
      languageModel,
    )
    assertThat(mutatedTree).isNotNull()
  }

  private fun checkEqualityOfTreeAndProgram(program: MutatedProgram, tree: SparTree) {
    val tree1 = c.parseString(program.program).tree.toStringTree()
    val tree2 = c.parseString(
      SingleTokenPerLinePrinter.print(tree.programSnapshot).sourceCode,
    ).tree.toStringTree()
    assertThat(tree1).isEqualTo(tree2)
  }
}
