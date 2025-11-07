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
import com.google.common.truth.Truth
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.smtlibv2.SmtLibV2ParserFacade
import org.perses.reduction.reducer.latra.smt.SmtTransformationList

@RunWith(JUnit4::class)
class SMTLatraTransformationTest :
  AbstractTransformationTest<SmtTransformationList>(
    facadeList =
      ImmutableList.of(
        SmtLibV2ParserFacade(),
      ),
    transformationList = SmtTransformationList,
  ) {
  @Test
  fun testPrintingProgram() {
    val args = latraArgsList.first()
    val sourceCode = "( assert ( = ( _ bv0 1 ) ( _ bv1 123 ) ) )"
    val tree =
      TestUtility.createSparTreeFromString(
        sourceCode,
        facade = args.parserFacade,
        simplifyTree = false,
        sparTreeNodeFactory = args.sparTreeNodeFactory,
      )
    val printedCode = args.programPrinter.printToString(tree.programSnapshot)
    Truth.assertThat(printedCode.trim()).isEqualTo(sourceCode.trim())
  }

  @Test
  fun testLetSubstitutionTransformation() {
    testTransformation(
      transformation = transformationList.letSubstitution,
      source =
        """
        ( assert ( let ( ( a  b ) ) (  =  a c ) ) )
        """.trimIndent(),
      expectOutput1 = "( assert ( = b c ) )",
    )
  }

  @Test
  fun testAnnotationRemoval() {
    testTransformation(
      transformation = transformationList.annotationRemoval,
      source =
        """
        ( assert (! true :named b))
        """.trimIndent(),
      expectOutput1 = "( assert true )",
    )
  }

  @Test
  fun testMergePlusTransformation() {
    testTransformation(
      transformation = transformationList.mergePlus,
      source =
        """
        ( assert (  +  a ( + b c) ))
        """.trimIndent(),
      expectOutput1 = "( assert ( + a b c ) )",
    )
  }

  @Test
  fun testMergeAndTransformation() {
    testTransformation(
      transformation = transformationList.mergeAnd,
      source =
        """
        ( assert (  and  a ( and b c) ))
        """.trimIndent(),
      expectOutput1 = "( assert ( and a b c ) )",
    )
  }

  @Test
  fun testForallRemovalTransformation() {
    testTransformation(
      transformationList.forallRemoval,
      """
      (get-qe (forall ((a Int))(> 665 (div f1 850) )))
      """.trimIndent(),
      expectOutput1 = "( get-qe ( > 665 ( div f1 850 ) ) )",
    )
  }

  @Test
  fun testExistRemovalTransformation() {
    testTransformation(
      transformation = transformationList.existsRemoval,
      source =
        """
        (assert ( exists ((a (_ BitVec 6))) true))
        """.trimIndent(),
      expectOutput1 = "( assert true )",
    )
  }

  @Test
  fun testDoubleNotTransformation() {
    testTransformation(
      transformation = transformationList.doubleNot,
      source =
        """
        (assert ( bvnot ( bvnot ( exists ((a (_ BitVec 6))) true) )))
        """.trimIndent(),
      expectOutput1 = "( assert ( exists ( ( a ( _ BitVec 6 ) ) ) true ) )",
    )
  }

  @Test
  fun testDoubleNegTransformation() {
    testTransformation(
      transformation = transformationList.doubleNeg,
      source =
        """
        (assert ( bvneg ( bvneg ( exists ((a (_ BitVec 6))) true) )))
        """.trimIndent(),
      expectOutput1 = "( assert ( exists ( ( a ( _ BitVec 6 ) ) ) true ) )",
    )
  }

  @Test
  fun testBvConverstionTransformation() {
    testTransformation(
      transformation = transformationList.bvConvertion,
      source =
        """
        (assert (  bvnot  (  _  bv0  123  )  ) )
        """.trimIndent(),
      expectOutput1 = "( assert ( _ bv1 123 ) )",
    )
  }

  @Test
  fun testEvalFalse() {
    testTransformation(
      transformation = transformationList.evalFalse,
      source =
        """
        ( assert ( = false ( _ bv1 123 )))
        """.trimIndent(),
      expectOutput1 = "( assert ( not ( _ bv1 123 ) ) )",
    )
  }

  @Test
  fun testCheckSatAsumming() {
    testTransformation(
      transformation = transformationList.checkSatAssuming,
      source =
        """
        ( check-sat-assuming ( x ))
        """.trimIndent(),
      expectOutput1 = "( check-sat )",
    )
  }

  /**
   * In this test, two matches will be created but only 1 is expected to be applied to sparTree
   * Either a is changed to b or b is changed to a.
   */
  @Test
  fun testMergeVariable() {
    testTransformation(
      transformation = transformationList.mergeVariable,
      source =
        """
        (declare-fun a () Int)
        (declare-fun b () Int)
        (assert (= a 10))
        (assert (= b 5))
        (assert (= (add a b) 15))
        (assert (= (subtract a b) 5))
        (check-sat)
        """.trimIndent(),
      expectOutput1 =
        """
        ( declare-fun b ( ) Int )
        ( assert ( = b 10 ) )
        ( assert ( = b 5 ) )
        ( assert ( = ( add b b ) 15 ) )
        ( assert ( = ( subtract b b ) 5 ) )
        ( check-sat )
        """.trimIndent(),
      expectOutput2 =
        """
        ( declare-fun a ( ) Int ) 
        ( assert ( = a 10 ) ) 
        ( assert ( = a 5 ) ) 
        ( assert ( = ( add a a ) 15 ) ) 
        ( assert ( = ( subtract a a ) 5 ) ) 
        ( check-sat )
        """.trimIndent(),
    )
  }

  /**
   * In this test, multiple matches will be created, but they might not be able to be applied
   * together. It's Ok to generate invalid edits.
   */
  @Test
  fun testSubstituteWithConst() {
    testTransformation(
      transformation = transformationList.substituteWithConst,
      source = "( assert ( = false ( _ bv1 123 )))",
      expectOutput1 = "( assert ( _ bv0 1 ) )",
      expectOutput2 = "( assert ( = ( _ bv0 1 ) ( _ bv1 123 ) ) )",
      expectOutput3 = "( assert ( = false ( _ bv0 1 ) ) )",
    )
  }
}
