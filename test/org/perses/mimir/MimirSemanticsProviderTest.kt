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
package org.perses.mimir

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.SparTree
import org.perses.util.Util
import org.perses.util.shell.ShellCommandOnPath
import java.nio.file.Paths
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class MimirSemanticsProviderTest {
  val tempDir = Util.createTempDirForObject(this)

  @OptIn(ExperimentalPathApi::class)
  @After
  fun tearDown() {
    tempDir.deleteRecursively()
  }

  fun createProvider(
    sourceFileName: String,
    sourceCode: String,
    languageServer: ShellCommandOnPath = ShellCommandOnPath("clangd-18"),
  ): Pair<MimirSemanticsProvider, SparTree> {
    val sourceFile = tempDir.resolve(sourceFileName).apply { writeText(sourceCode) }
    val sparTree = TestUtility.createSparTreeFromFile(sourceFile)
    val provider =
      MimirSemanticsProviderCreator(languageServer).computeSemanticsForSparTree(
        sourceFile,
        sparTree,
      ) as MimirSemanticsProvider
    return provider to sparTree
  }

  fun createJavacProvider(
    sourceFileName: String,
    sourceCode: String,
  ): Pair<MimirSemanticsProvider, SparTree> {
    val sourceFile = tempDir.resolve(sourceFileName).apply { writeText(sourceCode) }
    val sparTree = TestUtility.createSparTreeFromFile(sourceFile)
    val provider =
      MimirJavacSemanticProviderCreator().computeSemanticsForSparTree(
        sourceFile,
        sparTree,
      ) as MimirSemanticsProvider
    return provider to sparTree
  }

  @Test
  fun testCyclicDependencyGraph() {
    val file = "test/org/perses/mimir/lsp/cyclic-deps.c"
    testBuildScopedGraphForEachNodeSuccessfully(file)
//    testBuildScopedGraphForEachNodeSuccessfully("test/org/perses/mimir/lsp/recursive.c")
  }

  private fun testBuildScopedGraphForEachNodeSuccessfully(file: String) {
    val (provider, tree) =
      createProvider(
        sourceFileName = "t.c",
        sourceCode = Paths.get(file).readText(),
      )
    // TODO(cnsun): need to assert on the content, rather than just checking for crashes.
    tree.realRoot.preOrderVisit { node ->
      provider.buildScopedDependencyGraph(listOf(node))
      provider.buildScopedDependencyGraph(node.immutableChildView)
      node.immutableChildView
    }
  }

  @Test
  fun testScopedDependencyGraph() {
    val (provider, tree) =
      createProvider(
        sourceFileName = "t.c",
        sourceCode =
          """
          void f0() {}
          void f1() {}
          void f2() {f1();}
          void f3() {f1(); f2();}
          void f4() {f3();}
          void f5() {}
          void f6() {
            f5();
          }
          """.trimIndent(),
      )
    val nodes = mutableListOf<AbstractSparTreeNode>()
    tree.realRoot.preOrderVisit { node ->
      val children =
        node.immutableChildView
          .filter { child ->
            child.leafNodeSequence().map { it.token.lexemeText }.first() == "void"
          }
      if (children.size == 7) {
        nodes.addAll(children)
        ImmutableList.of()
      } else {
        node.immutableChildView
      }
    }
    assertThat(nodes).hasSize(7)

    val f0 = nodes[0]
    provider
      .buildScopedDependencyGraph(
        listOf(
          f0,
        ),
      ).let { graph ->
        assertThat(graph.allNodes).containsExactly(f0)
        assertThat(graph.representativeOfExternalUses).isNull()
        assertThat(graph.nodesUsedExternally).isEmpty()
        assertThat(graph.allNodesExcludingRepresentativeOfExternalUses).containsExactly(f0)

        assertThat(graph.nodesWithZeroOutDegree).containsExactly(f0)
        assertThat(graph.getPredecessorNodes(f0)).isEmpty()
      }
    val f1 = nodes[1]
    provider.buildScopedDependencyGraph(listOf(f0, f1)).let { graph ->
      assertThat(graph.allNodes).containsExactly(f0, f1, graph.representativeOfExternalUses)
      assertThat(graph.allNodesExcludingRepresentativeOfExternalUses).containsExactly(f0, f1)
      assertThat(graph.representativeOfExternalUses).isNotNull()
      assertThat(graph.nodesUsedExternally).containsExactly(f1)

      assertThat(
        graph.nodesWithZeroOutDegree,
      ).containsExactly(f0, graph.representativeOfExternalUses)
      assertThat(graph.getPredecessorNodes(f0)).isEmpty()
      assertThat(graph.getPredecessorNodes(f1)).isEmpty()
    }
    val f2 = nodes[2]
    val f3 = nodes[3]
    provider.buildScopedDependencyGraph(listOf(f1, f2, f3)).let { graph ->
      assertThat(graph.allNodes).containsExactly(f1, f2, f3, graph.representativeOfExternalUses)
      assertThat(graph.allNodesExcludingRepresentativeOfExternalUses).containsExactly(f1, f2, f3)
      assertThat(graph.nodesUsedExternally).containsExactly(f3)
      assertThat(graph.representativeOfExternalUses).isNotNull()

      assertThat(graph.nodesWithZeroOutDegree).containsExactly(graph.representativeOfExternalUses)
      assertThat(graph.getPredecessorNodes(f1)).isEmpty()
      assertThat(graph.getPredecessorNodes(f2)).containsExactly(f1)
      assertThat(graph.getPredecessorNodes(f3)).containsExactly(f1, f2)
    }
    val f5 = nodes[5]
    val f6 = nodes[6]
    provider.buildScopedDependencyGraph(listOf(f5, f6)).let { graph ->
      assertThat(graph.allNodes).containsExactly(f5, f6)
      assertThat(graph.allNodesExcludingRepresentativeOfExternalUses).containsExactly(f5, f6)
      assertThat(graph.nodesUsedExternally).isEmpty()
      assertThat(graph.representativeOfExternalUses).isNull()

      assertThat(graph.nodesWithZeroOutDegree).containsExactly(f6)
      assertThat(graph.getPredecessorNodes(f6)).containsExactly(f5)
      assertThat(graph.getPredecessorNodes(f5)).isEmpty()
    }
  }

  @Test
  fun test() {
    val provider =
      createProvider(
        sourceFileName = "t.c",
        sourceCode =
          """
          int main() {
            int a = 0;
            int b = 0;
            int c;
            c = 1;
            b = a + c;
            return a + b + c;
          }
          """.trimIndent(),
      ).first
    assertThat(Util.extractNonBlankLinesAndTrim(provider.dumpGraph())).isEqualTo(
      Util.extractNonBlankLinesAndTrim(
        """
        def:main@1:function
        
        def:a@2:variable
        a@6
        a@7
        
        def:b@3:variable
        b@6
        b@7
        
        def:c@4:variable
        c@5
        c@6
        c@7
        """,
      ),
    )
  }

  @Test
  fun testDefUseTokenEdges() {
    val (provider, tree) =
      createProvider(
        sourceFileName = "t.c",
        sourceCode =
          """
          int a = 0;
          int b = a;
          """.trimIndent(),
      )
    val nodes = mutableListOf<AbstractSparTreeNode>()
    tree.realRoot.preOrderVisit { node ->
      if (node.antlrRule?.ruleName == "declaration") {
        nodes.add(node)
        return@preOrderVisit emptyList()
      }
      node.childSequence().toList()
    }
    assertThat(nodes).hasSize(2)
    val declA = nodes[0]
    val declB = nodes[1]

    val graph = provider.buildScopedDependencyGraph(listOf(declA, declB))
    val edge = graph.getEdge(declA, declB)
    assertThat(edge).isNotNull()
    assertThat(edge!!.defTokens.map { it.token.lexemeText }).containsExactly("a")
    assertThat(edge.useTokens.map { it.token.lexemeText }).containsExactly("a")
  }

  @Test
  fun testForLargeJavaProgram() {
    val javaFile = Paths.get("benchmark_v2/benchmark_java/checkerframework-691/Collections.java")
    val jls =
      ShellCommandOnPath(
        Paths.get("benchmark_v2/binaries/start_jls.sh").toAbsolutePath().toString(),
      )
    val (provider, tree) =
      createProvider(
        sourceFileName = "Collections.java",
        sourceCode = javaFile.readText(),
        languageServer = jls,
      )
    // Build scoped dependency graphs for top-level nodes in the Java file
    // To identify top-level nodes, we can just take the children of the root (compilationUnit usually)
    val topLevelNodes = tree.realRoot.immutableChildView
    val graph = provider.buildScopedDependencyGraph(topLevelNodes)
    assertThat(
      graph.allNodesExcludingRepresentativeOfExternalUses,
    ).containsAtLeastElementsIn(topLevelNodes)
  }

  @Test
  fun testJavacSemanticsProvider() {
    verifyJavacProvider("benchmark_v2/benchmark_java/checkerframework-691/Collections.java")
  }

  @Test
  fun testJavacSemanticsProviderForIncomparableTypes() {
    verifyJavacProvider("benchmark_v2/benchmark_java/checkerframework-577/IncomparableTypes.java")
  }

  private fun verifyJavacProvider(javaFilePath: String) {
    val javaFile = Paths.get(javaFilePath)
    val (provider, tree) =
      createJavacProvider(
        sourceFileName = javaFile.fileName.toString(),
        sourceCode = javaFile.readText(),
      )

    tree.realRoot.postOrderVisit { node ->
      if (node.hasChildren()) {
        val children = node.immutableChildView
        val graph = provider.buildScopedDependencyGraph(children)
        assertThat(
          graph.allNodesExcludingRepresentativeOfExternalUses,
        ).containsAtLeastElementsIn(children)
      }
    }
  }
}
