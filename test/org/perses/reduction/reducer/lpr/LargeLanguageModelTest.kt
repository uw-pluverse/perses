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
package org.perses.reduction.reducer.lpr

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.AutoDeletableFolder
import org.perses.util.Util
import java.nio.file.Paths
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively

@RunWith(JUnit4::class)
class LargeLanguageModelTest {
  val tempDir = Util.createTempDirForObject(this)

  @OptIn(ExperimentalPathApi::class)
  @After
  fun tearDown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testExtractListBetweenStarAndNewline1() {
    val input =
      """These are all functions. 
        |* fn1 
        |* fn2 
        |* fn3
      """.trimMargin()
    val list = LargeLanguageModel.extractListBetweenStarAndNewline(input)
    assertThat(list).containsExactly("fn1", "fn2", "fn3").inOrder()
  }

  @Test
  fun testExtractListBetweenStarAndNewline3() {
    val input =
      """
      |These are all functions.
      """.trimMargin()
    val list = LargeLanguageModel.extractListBetweenStarAndNewline(input)
    assertThat(list).hasSize(0)
  }

  @Test
  fun testExtractListBetweenStarAndNewline4() {
    val input =
      """These are all functions.
        |* fn1
        |* fn2
        |* fn3
        |
        |
      """.trimMargin()
    val list = LargeLanguageModel.extractListBetweenStarAndNewline(input)
    assertThat(list).containsExactly("fn1", "fn2", "fn3").inOrder()
  }

  @Test
  fun testExtractLastFencedCodeBlockFromDocstring1() {
    val input =
      """|
      |Here is the program.
      |```
      |  int main() { return 0; }
      |```
      """.trimMargin()
    val program = LargeLanguageModel.extractLastFencedCodeBlockFromDocstring(input)!!.trim()
    assertThat(program.trim()).isEqualTo("int main() { return 0; }")
  }

  @Test
  fun testExtractLastFencedCodeBlockFromDocstring2() {
    val input =
      """|
      |Here is the program snippet.
      |```
      |  return 0;
      |```
      |And here is the whole program.
      |```
      |  int main() { return 0; }
      |```
      """.trimMargin()
    val program = LargeLanguageModel.extractLastFencedCodeBlockFromDocstring(input)!!.trim()
    assertThat(program).isEqualTo("int main() { return 0; }")
  }

  @Test
  fun testExtractLastFencedCodeBlockFromDocstring3() {
    val input =
      """|
      |Here is the whole program.
      |```c
      |  int main() { return 0; }
      |```
      """.trimMargin()
    val program = LargeLanguageModel.extractLastFencedCodeBlockFromDocstring(input)!!.trim()
    assertThat(program).isEqualTo("int main() { return 0; }")
  }

  @Test
  fun testExtractLastFencedCodeBlockFromDocstring4() {
    val input =
      """|
      |Here is the whole program.
      |```python
      |  int main() { return 0; }
      |```
      """.trimMargin()
    val program = LargeLanguageModel.extractLastFencedCodeBlockFromDocstring(input)!!.trim()
    assertThat(program).isEqualTo("int main() { return 0; }")
  }

  val llmMock =
    LargeLanguageModel(
      Paths.get("scripts/llm_scripts/llm_client_mock_to_test_functions.py"),
      tempDirectoryCreator = {
        AutoDeletableFolder(Util.ensureDirExists(tempDir.resolve("temp")))
      },
    )

  @Test
  fun testCallLLMScript1() {
    val message =
      """
      |int main() {
      |int a = 1;
      |printf("%d", a);
      |return 0;
      |}
      """.trimMargin()

    val output = llmMock.callLLMScript(message).llmOutput

    assertThat(output.single().trim()).isEqualTo(message)
  }

  @Test
  fun testCallLLMScript2() {
    val message = "abcde"
    val output =
      llmMock
        .callLLMScript(message)
        .llmOutput
        .single()
        .trim()
    assertThat(output).isEqualTo("abcde")
  }

  @Test
  fun testGetTargetListFromLLM1() {
    val promptSystem = "succeed in the first time"
    val program = "this is program"
    val promptTargetList = "this is promptTargetList"
    val primaryQuestion = "this is primaryQuestion"

    val output =
      llmMock.getTargetListFromLLM(
        program,
        promptSystem,
        promptTargetList,
        primaryQuestion,
      )

    assertThat(output.size).isEqualTo(1)
    assertThat(output[0]).isEqualTo("a")
  }

  @Test
  fun testGetTargetListFromLLM2() {
    val promptSystem = "succeed in the second time"
    val program = "this is program"
    val promptTargetList = "this is promptTargetList"
    val primaryQuestion = "this is primaryQuestion"

    val output =
      llmMock.getTargetListFromLLM(
        program,
        promptSystem,
        promptTargetList,
        primaryQuestion,
      )

    assertThat(output.size).isEqualTo(2)
    assertThat(output[0]).isEqualTo("a")
    assertThat(output[1]).isEqualTo("b")
  }

  @Test
  fun testGetTargetListFromLLM3() {
    val promptSystem = "succeed in the third time"
    val program = "this is program"
    val promptTargetList = "this is promptTargetList"
    val primaryQuestion = "this is primaryQuestion"

    val output =
      llmMock.getTargetListFromLLM(
        program,
        promptSystem,
        promptTargetList,
        primaryQuestion,
      )

    assertThat(output.size).isEqualTo(3)
    assertThat(output[0]).isEqualTo("a")
    assertThat(output[1]).isEqualTo("b")
    assertThat(output[2]).isEqualTo("c")
  }

  @Test
  fun testGetTargetListFromLLM4() {
    val promptSystem = "never succeed"
    val program = "this is program"
    val promptTargetList = "this is promptTargetList"
    val primaryQuestion = "this is primaryQuestion"

    val output =
      llmMock.getTargetListFromLLM(
        program,
        promptSystem,
        promptTargetList,
        primaryQuestion,
      )

    assertThat(output.size).isEqualTo(0)
  }

  @Test
  fun testGetTargetListFromLLM5() {
    val promptSystem = "test other parameters"
    val program = "this is program"
    val promptTargetList = "this is promptTargetList"
    val primaryQuestion = "this is primaryQuestion"

    val output =
      llmMock.getTargetListFromLLM(
        program,
        promptSystem,
        promptTargetList,
        primaryQuestion,
      )

    assertThat(output.size).isEqualTo(4)
    assertThat(output[0]).isEqualTo("test other parameters")
    assertThat(output[1]).isEqualTo("this is promptTargetList")
    assertThat(output[2]).isEqualTo("The question: this is primaryQuestion")
    assertThat(output[3]).isEqualTo("The program: this is program")
  }

  @Test
  fun testGetProgramsFromLLM1() {
    val promptSystem = "test get programs"
    val promptToGenerateProgram = "this is promptToGenerateProgram"
    val followupQuestion = "this is followupQuestion"
    val program =
      """
      |program1:
      |```c
      |int a = 0;
      |```
      |======
      |program2:
      |```
      |int b = 1;
      |```
      |======
      |program3:
      |```python
      |print("hello")
      |```
      |======
      |program4:
      |wrong info
      |======
      |program5:
      |```python
      |intermediate code xxx
      |```
      |whole program:
      |```js
      |c = 3
      |```
      """.trimMargin()

    val output =
      llmMock.getProgramsFromLLM(
        program,
        promptSystem,
        promptToGenerateProgram,
        followupQuestion,
      )

    assertThat(output.size).isEqualTo(4)
    assertThat(output[0].trim()).isEqualTo("int a = 0;")
    assertThat(output[1].trim()).isEqualTo("int b = 1;")
    assertThat(output[2].trim()).isEqualTo("print(\"hello\")")
    assertThat(output[3].trim()).isEqualTo("c = 3")
  }
}
