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
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.program.EnumFormatControl
import org.perses.reduction.ReducerFunctionalTestUtility
import java.nio.file.Paths

@RunWith(JUnit4::class)
class AbstractLLMBasedReducerTest {
  @Test
  fun testDefaultLLMClientScript() {
    assertThat(AbstractLLMBasedReducer.defaultLLMClientScript.fileName)
      .isEqualTo(AbstractLLMBasedReducer.DEFAULT_LLM_CLIENT_SCRIPT_BASE_NAME)
  }

  @Test
  fun testDataTypeElimination() {
    ReducerFunctionalTestUtility(
      reductionFolder = "test/org/perses/reduction/reducer/lpr",
      testScript = "test_data_type_elimination.sh",
      sourceFile = "test_data_type_elimination.c",
      reducerAnnotation = LLMBasedDataTypeEliminationReducer.META,
      cmdCustomizer = { cmd ->
        cmd.lprFlags.llmClientPath =
          Paths.get("scripts/llm_scripts/llm_client_mock_to_test_workflow.py")
        cmd.reductionControlFlags.codeFormat = EnumFormatControl.COMPACT_ORIG_FORMAT
      },
    ).use {
      it.runReducerAndTest(
        expected =
          """
      |int main() {
      |  int x = 1;
      |  int y = x + 1;
      |  printf("%d", y);
      |  return 0;
      |}
          """.trimMargin(),
      )
    }
  }

  @Test
  fun testFunctionInlining() {
    ReducerFunctionalTestUtility(
      reductionFolder = "test/org/perses/reduction/reducer/lpr",
      testScript = "test_function_inlining.sh",
      sourceFile = "test_function_inlining.c",
      reducerAnnotation = LLMBasedFunctionInliningReducer.META,
      cmdCustomizer = { cmd ->
        cmd.lprFlags.llmClientPath =
          Paths.get("scripts/llm_scripts/llm_client_mock_to_test_workflow.py")
        cmd.reductionControlFlags.codeFormat = EnumFormatControl.COMPACT_ORIG_FORMAT
      },
    ).use {
      it.runReducerAndTest(
        expected =
          """
      |int main() {
      |  int a = 1;
      |  a = a + 1;
      |  printf("%d", a);
      |  return 0;
      |}
          """.trimMargin(),
      )
    }
  }

  @Test
  fun testLoopUnrolling() {
    ReducerFunctionalTestUtility(
      reductionFolder = "test/org/perses/reduction/reducer/lpr",
      testScript = "test_loop_unrolling.sh",
      sourceFile = "test_loop_unrolling.c",
      reducerAnnotation = LLMBasedLoopUnrollingReducer.META,
      cmdCustomizer = { cmd ->
        cmd.lprFlags.llmClientPath =
          Paths.get("scripts/llm_scripts/llm_client_mock_to_test_workflow.py")
        cmd.reductionControlFlags.codeFormat = EnumFormatControl.COMPACT_ORIG_FORMAT
      },
    ).use {
      it.runReducerAndTest(
        expected =
          """
      |int main() {
      |  int a = 1;
      |  a = a + 1;
      |  a = a + 1;
      |  a = a + 1;
      |  printf("%d", a);
      |  return 0;
      |}
          """.trimMargin(),
      )
    }
  }

  @Test
  fun testVariableElimination() {
    ReducerFunctionalTestUtility(
      reductionFolder = "test/org/perses/reduction/reducer/lpr",
      testScript = "test_variable_elimination.sh",
      sourceFile = "test_variable_elimination.c",
      reducerAnnotation = LLMBasedVariableEliminationReducer.META,
      cmdCustomizer = { cmd ->
        cmd.lprFlags.llmClientPath =
          Paths.get("scripts/llm_scripts/llm_client_mock_to_test_workflow.py")
        cmd.reductionControlFlags.codeFormat = EnumFormatControl.COMPACT_ORIG_FORMAT
      },
    ).use {
      it.runReducerAndTest(
        expected =
          """
      |int main() {
      |  printf("%d", 1);
      |  return 0;
      |}
          """.trimMargin(),
      )
    }
  }

  @Test
  fun testDataTypeSimplification() {
    ReducerFunctionalTestUtility(
      reductionFolder = "test/org/perses/reduction/reducer/lpr",
      testScript = "test_data_type_simplification.sh",
      sourceFile = "test_data_type_simplification.c",
      reducerAnnotation = LLMBasedDataTypeSimplificationReducer.META,
      cmdCustomizer = { cmd ->
        cmd.lprFlags.llmClientPath =
          Paths.get("scripts/llm_scripts/llm_client_mock_to_test_workflow.py")
        cmd.reductionControlFlags.codeFormat = EnumFormatControl.COMPACT_ORIG_FORMAT
      },
    ).use {
      it.runReducerAndTest(
        expected =
          """
      |int main() {
      |  int x = 1;
      |  printf("%d", x);
      |  return 0;
      |}
          """.trimMargin(),
      )
    }
  }
}
