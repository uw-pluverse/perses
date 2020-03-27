package org.perses.grammar.go

import com.google.common.truth.Truth
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility

@RunWith(JUnit4::class)
class PnfGoParserFacadeTest {
  @Test
  fun test() {
    val facade = PnfGoParserFacade()
    val program = """
      |package main
      |import "fmt"
      |
      |func main() {
      |    fmt.Println("go" + "lang")
      |    
      |    
      |    
      |}
    """.trimMargin()

    val parseTreeWithPnfParser = facade.parseString(program)
    val tokensByPnfParser = TestUtility.extractTokens(parseTreeWithPnfParser.tree)

    val parseTreeFromOrigParser = facade.parseWithOrigGoParser(program)
    val tokensByOrigParser = TestUtility.extractTokens(parseTreeFromOrigParser.tree)

    Truth.assertThat(tokensByPnfParser).containsExactlyElementsIn(tokensByOrigParser).inOrder()
  }
}
