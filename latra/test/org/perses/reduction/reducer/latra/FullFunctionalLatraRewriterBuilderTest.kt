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
package org.perses.reduction.reducer.latra

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.perses.TestUtility
import org.perses.grammar.c.OrigCParserFacade
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
    // Share one factory between tree building and latra, as production does in
    // AbstractProgramReductionDriver: node ids created by latra must not collide
    // with the ids already in the tree.
    val sparTreeNodeFactory = SparTreeNodeFactory(parserFacade)
    val sparTree =
      TestUtility.createSparTreeFromString(
        program,
        parserFacade,
        false,
        sparTreeNodeFactory,
      )

    val parsingRelatedArguments =
      LatraArguments(
        parserFacade,
        sparTreeNodeFactory = sparTreeNodeFactory,
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

  // Regression tests for https://github.com/chengniansun/perses-private/issues/1037.
  //
  // The function definition matches the from-clause, but the only call site has a
  // different arity, so the call-site clause matches nothing and binds paramCall1 and
  // paramCall2 to empty lists. The clause substituting :[param2] with :[paramCall2]
  // inside the body then used to crash the reducer with LatraEmptyHoleBindingException;
  // it must be skipped instead.
  private val inliningInputWithMismatchedCallSite =
    """
    int func_1 ( int a , int b ) {
      d = b ;
    }
    int main ( ) {
      func_1 ( 1 ) ;
      return 0 ;
    }
    """.trimIndent()

  private val inliningDefinitionWithoutMustMatch =
    LatraTransformationDefinition.parse(
      RawDefinition(
        name = "FunctionInlining2ArgsWithoutMustMatch",
        from =
          """
          :[retType] :[name] ( :[type1] :[param1] , :[type2] :[param2] ) {
            :[block+]
          }
          """.trimIndent(),
        to = "",
        global_replace =
          ImmutableList.of(
            RawGlobalReplaceClause(
              pattern = ":[name] ( :[paramCall1] , :[paramCall2+] )",
              with = ":[block]",
            ),
            RawGlobalReplaceClause(
              pattern = ":[param1]",
              inside = "block",
              with = ":[paramCall1]",
            ),
            RawGlobalReplaceClause(
              pattern = ":[param2]",
              inside = "block",
              with = ":[paramCall2]",
            ),
          ),
      ),
      parserFacade,
    )

  @Test
  fun testGlobalReplaceSkipsClauseWhoseWithHoleIsBoundToNothing() {
    val builder =
      getBuilder(inliningInputWithMismatchedCallSite, inliningDefinitionWithoutMustMatch)
        .createSingleMatchLatraRewriterBuilder()
        .single()
    val holeBindings = builder.createInitialHoleBindings()
    builder.processToClauseOnSparTreeCopy(holeBindings)
    builder.processGlobalReplaceClauseOnSparTreeCopy(holeBindings)
    val replacingNode = builder.treeCopy.result.detachRootFromTree()
    replacingNode.fixLinkIntegrity()
    val outcome = replacingNode.leafNodeSequence().joinToString(" ") { it.token.lexemeText }
    LatraTestUtil.assertHaveSameTokens(
      actualProgram = outcome,
      expectedProgram =
        """
        int main ( ) {
          func_1 ( 1 ) ;
          return 0 ;
        }
        """.trimIndent(),
      facade = parserFacade,
    )
  }

  @Test
  fun testBuildSucceedsWhenTheCallSiteClauseMatchesNothing() {
    val actionSet =
      getBuilder(inliningInputWithMismatchedCallSite, inliningDefinitionWithoutMustMatch)
        .build()
    assertThat(actionSet).isNotNull()
  }

  private val declarationOnlyInput =
    """
    void func_1 ( ) {
      int d ;
    }
    """.trimIndent()

  // The zero-match global-replace clause binds callArgument to an empty list, and the
  // insert clause then rewrites with it. build() must abandon the transformation
  // gracefully instead of propagating LatraEmptyHoleBindingException.
  private val insertionUsingHoleBoundToNothingDefinition =
    LatraTransformationDefinition.parse(
      RawDefinition(
        name = "InsertionUsingHoleBoundToNothing",
        from = ":[type] :[name] ;",
        to = ":[type] :[name] = 0 ;",
        global_replace =
          ImmutableList.of(
            RawGlobalReplaceClause(
              pattern = ":[name] ( :[callArgument+] )",
              with = "",
            ),
          ),
        insert =
          ImmutableList.of(
            RawInsertClause(
              pattern = "int newVar = :[callArgument] ;",
              location = "bottom",
            ),
          ),
      ),
      parserFacade,
    )

  @Test
  fun testBuildAbandonsTransformationOnEmptyHoleBindingInInsertClause() {
    val actionSet =
      getBuilder(declarationOnlyInput, insertionUsingHoleBoundToNothingDefinition)
        .build()
    assertThat(actionSet).isNull()
  }
}
