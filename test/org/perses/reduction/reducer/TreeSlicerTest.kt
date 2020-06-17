package org.perses.reduction.reducer

import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.AbstractReducerFunctionalTest

@RunWith(JUnit4::class)
class TreeSlicerTest : AbstractReducerFunctionalTest() {

  @Test
  fun testReduceDelta1() {
    runCTestSubject(
      "test_data/delta_1",
      TokenSlicer.META,
      """
        |int main() {
        |  printf("world\n");
        |}
      """.trimMargin()
    )
  }

  @Test
  fun testReduceScalaHelloWorld() {
    runScalaTestSubject(
      "test_data/scala_helloworld",
      TokenSlicer.META,
      """
      |object Hello {
      | def main(args: Array[String]) =
      |   println("Hello, world")
      |}
    """.trimMargin()
    )
  }
}
