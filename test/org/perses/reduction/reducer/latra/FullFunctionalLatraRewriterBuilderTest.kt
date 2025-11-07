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
package org.perses.reduction.reducer.latra

import com.google.common.collect.ImmutableList
import org.junit.Test
import org.perses.TestUtility
import org.perses.grammar.c.OrigCParserFacade
import org.perses.program.TokenizedProgramFactory
import org.perses.reduction.reducer.latra.language.LatraTransformationDefinition
import org.perses.reduction.reducer.latra.language.io.RawDefinition
import org.perses.reduction.reducer.latra.language.io.RawGlobalReplaceClause
import org.perses.reduction.reducer.latra.language.io.RawInsertClause
import org.perses.spartree.SparTreeNodeFactory

class FullFunctionalLatraRewriterBuilderTest {
  private val parserFacade = OrigCParserFacade()

  private val input1 =
    """
    int func_1 ( int a , char b , int c ) { 
      for ( p_131 . f0 = 0 ; p_131 . f0 << 2 ; p_131 . f0 += 1 ) { } 
      d = a ; 
      return a; 
    }
    int main ( ) {
      func_1(1, '2', 3) ;
      return 0 ; 
    }
    """.trimIndent()

  private val definition1 =
    LatraTransformationDefinition.parse(
      RawDefinition(
        name = "VoidReturnFunctionDefLatraTransformation",
        from =
          """
          :[declarationSpecifier] :[name] ( :[parameterList+] ) { 
            :[block+] 
          }
          """.trimIndent(),
        such_as = "",
        where = ":[name] != main",
        to =
          """
          void :[name] ( :[parameterList] ) { 
            :[block] 
          }
          """.trimIndent(),
        global_replace =
          ImmutableList.of(
            RawGlobalReplaceClause(
              pattern = "return :[stm+];",
              inside = "block",
              with = "  ",
            ),
          ),
      ),
      parserFacade,
    )

  private fun getBuilder(
    program: String,
    definition: LatraTransformationDefinition,
  ): FullFunctionalLatraRewriterBuilder {
    val sparTree =
      TestUtility.createSparTreeFromString(
        program,
        parserFacade,
        false,
      )

    val parsingRelatedArguments =
      LatraArguments(
        parserFacade,
        sparTreeNodeFactory =
          SparTreeNodeFactory(
            parserFacade.metaTokenInfoDb,
            TokenizedProgramFactory.createEmptyFactory(parserFacade.language),
            parserFacade.ruleHierarchy,
          ),
        IProgramPrinter.create(parserFacade),
        prefixLabelFromRootToHere = "[test]",
      )

    val match =
      TransformationUtility.looseMatch(
        definition.matchingTemplate.from.pattern,
        definition.matchingTemplate.suchAs,
        sparTree.realRoot,
        parsingRelatedArguments,
      )

    return FullFunctionalLatraRewriterBuilder(
      match,
      sparTree,
      definition,
      parsingRelatedArguments,
    )
  }

  @Test
  fun testProcessToClauseOnSparTreeCopy() {
    val builder = getBuilder(input1, definition1)
    val latraRewriterBuilder = builder.createSingleMatchLatraRewriterBuilder().single()
    latraRewriterBuilder.processToClauseOnSparTreeCopy(
      latraRewriterBuilder.createInitialHoleBindings(),
    )
    val replacingNode = latraRewriterBuilder.treeCopy.result.detachRootFromTree()
    replacingNode.fixLinkIntegrity()
    val outcome =
      replacingNode.leafNodeSequence().joinToString(" ") {
        it.token.lexemeText
      }
    LatraTestUtil.assertHaveSameTokens(
      actualProgram = outcome,
      expectedProgram =
        """
        void func_1 ( int a , char b , int c ) { 
          for ( p_131 . f0 = 0 ; p_131 . f0 << 2 ; p_131 . f0 += 1 ) { } 
          d = a ; 
          return a; 
        }
        int main ( ) {
          func_1(1, '2', 3) ;
          return 0 ; 
        }
        """.trimIndent(),
      facade = parserFacade,
    )
  }

  @Test
  fun testProcessGlobalReplaceClauseOnSparTreeCopy() {
    val builder = getBuilder(input1, definition1).createSingleMatchLatraRewriterBuilder().single()
    builder.processGlobalReplaceClauseOnSparTreeCopy(builder.createInitialHoleBindings())
    val replacingNode = builder.treeCopy.result.detachRootFromTree()
    replacingNode.fixLinkIntegrity()
    val outcome =
      replacingNode.leafNodeSequence().joinToString(" ") {
        it.token.lexemeText
      }
    LatraTestUtil.assertHaveSameTokens(
      actualProgram = outcome,
      expectedProgram =
        """
        int func_1 ( int a , char b , int c ) { 
          for ( p_131 . f0 = 0 ; p_131 . f0 << 2 ; p_131 . f0 += 1 ) { } 
          d = a ; 
        }
        int main ( ) {
          func_1(1, '2', 3) ;
          return 0 ; 
        }
        """.trimIndent(),
      facade = parserFacade,
    )
  }

  private val input2 =
    """
    void func_1 ( int a , char b , int c ) { 
      for ( p_131 . f0 = 0 ; p_131 . f0 << 2 ; p_131 . f0 += 1 ) { } 
      int d;
    }
    """.trimIndent()

  private fun getInsertionDef(location: String): LatraTransformationDefinition =
    LatraTransformationDefinition.parse(
      RawDefinition(
        name = "Insertion",
        from = ":[type] :[name];",
        such_as = "",
        where = "",
        to = ":[type] :[name] = 0;",
        insert =
          ImmutableList.of(
            RawInsertClause(
              pattern = ":[type] newVar;",
              location = location,
            ),
          ),
      ),
      parserFacade,
    )

  private fun assertInsertClauseOutcome(
    location: String,
    expected: String,
  ) {
    val builder =
      getBuilder(
        input2,
        getInsertionDef(location),
      ).createSingleMatchLatraRewriterBuilder().single()
    val holeBindings = builder.createInitialHoleBindings()
    builder.processToClauseOnSparTreeCopy(holeBindings)
    builder.processInsertClausesOnSparTreeCopy(holeBindings)

    val replacingNode = builder.treeCopy.result.detachRootFromTree()
    replacingNode.fixLinkIntegrity()

    val outcome = replacingNode.leafNodeSequence().joinToString(" ") { it.token.lexemeText }

    LatraTestUtil.assertHaveSameTokens(
      actualProgram = outcome,
      expectedProgram = expected,
      facade = parserFacade,
    )
  }

  @Test
  fun testProcessInsertClausesOnTopSparTreeCopy() {
    assertInsertClauseOutcome(
      location = "top",
      expected =
        """
        int newVar;
        void func_1 ( int a , char b , int c ) { 
          for ( p_131 . f0 = 0 ; p_131 . f0 << 2 ; p_131 . f0 += 1 ) { } 
          int d = 0;
        }
        """.trimIndent(),
    )
  }

  @Test
  fun testProcessInsertClausesOnBottomSparTreeCopy() {
    assertInsertClauseOutcome(
      location = "bottom",
      expected =
        """
        void func_1 ( int a , char b , int c ) { 
          for ( p_131 . f0 = 0 ; p_131 . f0 << 2 ; p_131 . f0 += 1 ) { } 
          int d = 0;
        }
        int newVar;
        """.trimIndent(),
    )
  }

  @Test
  fun testProcessInsertClausesOnBeforeSparTreeCopy() {
    assertInsertClauseOutcome(
      location = "before",
      expected =
        """
        void func_1 ( int a , char b , int c ) { 
          for ( p_131 . f0 = 0 ; p_131 . f0 << 2 ; p_131 . f0 += 1 ) { } 
          int newVar;
          int d = 0;
        }
        """.trimIndent(),
    )
  }

  @Test
  fun testProcessInsertClausesOnAfterSparTreeCopy() {
    assertInsertClauseOutcome(
      location = "after",
      expected =
        """
        void func_1 ( int a , char b , int c ) { 
          for ( p_131 . f0 = 0 ; p_131 . f0 << 2 ; p_131 . f0 += 1 ) { } 
          int d = 0;
          int newVar;
        }
        """.trimIndent(),
    )
  }
}
