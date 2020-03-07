package org.perses.grammar.go

import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

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
    facade.parseString(program)
    //    facade.parseString()
  }
}