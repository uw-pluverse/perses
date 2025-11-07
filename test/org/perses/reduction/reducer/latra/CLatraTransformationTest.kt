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
import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Test
import org.perses.grammar.c.OrigCParserFacade
import org.perses.grammar.c.PnfCParserFacade
import org.perses.reduction.reducer.latra.c.CTransformationList
import org.perses.reduction.reducer.latra.language.LatraTransformationDefinition
import org.perses.reduction.reducer.latra.language.io.RawDefinition
import org.perses.util.toImmutableList

class CLatraTransformationTest :
  AbstractTransformationTest<CTransformationList>(
    facadeList = ImmutableList.of(PnfCParserFacade(), OrigCParserFacade()),
    transformationList = CTransformationList,
  ) {
  class TestTransformation(
    parsingRelatedArguments: LatraArguments,
  ) : LatraTransformation(
      latraArguments = parsingRelatedArguments,
      definition =
        LatraTransformationDefinition.parse(
          RawDefinition(
            name = "TypeDefTransform",
            from = "typedef :[Specifier1] :[idt];",
            such_as = "",
            where = "",
            to = "",
          ),
          parsingRelatedArguments.parserFacade,
        ),
    )

  class TestInvalidTransformation(
    parsingRelatedArguments: LatraArguments,
  ) : LatraTransformation(
      latraArguments = parsingRelatedArguments,
      definition =
        LatraTransformationDefinition.parse(
          RawDefinition(
            name = "TypeDefTransform",
            from = "typedef :[Specifier1] :[idt];",
            such_as = "",
            where = "",
            to = "void :[name] ( :[parameterList] );",
          ),
          parsingRelatedArguments.parserFacade,
        ),
    )

  @Test
  fun testValidTransformation() {
    latraArgsList.forEach { args ->
      testTransformation(
        transformationCreator = { TestTransformation(args) },
        source =
          """
          typedef long int64_t;
          int64_t g;
          int main() {func_2(func_12(g_14));}
          """.trimIndent(),
        expectOutput1 = "int64_t g ; int main ( ) { func_2 ( func_12 ( g_14 ) ) ; }",
      )
    }
  }

  @Test
  fun testTypeDefTransformation() {
    testTransformation(
      transformation = transformationList.typedef,
      source =
        """
        typedef long int64_t;
        int64_t g;
        int main() {func_2(func_12(g_14));}
        """.trimIndent(),
      expectOutput1 = "long g ; int main ( ) { func_2 ( func_12 ( g_14 ) ) ; }",
    )
  }

  @Test
  fun testTypeDefTransformationForComplexTypeDef() {
    testTransformation(
      transformation = transformationList.typedef,
      source =
        """
        typedef long long * long_p;
        long_p a;
        """.trimIndent(),
      expectOutput1 = "long long * a;",
    )
  }

  @Test
  fun testTypeDefTransformation2() {
    testTransformation(
      transformation = transformationList.typedef,
      source =
        """ 
        int main() {
          typedef int abc;
          abc b = 42;
          printf("", b);
        }
        """.trimIndent(),
      expectOutput1 =
        """
        int main ( ) { int b = 42 ; printf ( "" , b ) ; } 
        """.trimIndent(),
    )
  }

  @Test
  fun testInvalidTransformation() {
    latraArgsList.forEach { args ->
      val source = """
        typedef long int64_t;
        int64_t g;
        int main() {func_2(func_12(g_14));}
        """
      val exception =
        Assert.assertThrows(IllegalArgumentException::class.java) {
          val transformation = TestInvalidTransformation(args)
          transformation
            .computeEdits(
              args.createSparTree(source),
            ).toImmutableList()
        }
      assertThat(exception.message).contains(
        """
        Hole Hole{name, greedy=false} is not defined in the match pattern.
        match pattern: typedef :[Specifier1] :[idt];
        rewrite pattern: void :[name] ( :[parameterList] );
        """.trimIndent(),
      )
    }
  }

  @Test
  fun testFunctionInliningWith4Args() {
    testTransformation(
      transformation = transformationList.funcInline4Args,
      source =
        """
        void func_32(int p_33, unsigned p_34, unsigned p_35, int p_36) {
            int l_2124 = 2L;
            for (; g_163 < 51; ++g_163) {
                unsigned l_2150[9];
                int i;
                for (i = 0; i < 9; i++)
                    l_2150[i] = 0x9EE7F9D1C772505BLL;
                l_2124 = safe_add_func_uint64_t_u_u(
                    safe_rshift_func_int8_t_s_s(
                        g_1729[0][3] = safe_add_func_int16_t_s_s(4L, l_2124),
                        3),
                    l_2150[0]);
            }
        }
        
        int main() {
          func_32(6, l_43, 1, p_23);
          return 0;
        }
        """.trimIndent(),
      expectOutput1 =
        """
        int main ( ) { int l_2124 = 2L ; for ( ; g_163 < 51 ; ++ g_163 ) 
        { unsigned l_2150 [ 9 ] ; int i ; 
        for ( i = 0 ; i < 9 ; i ++ ) l_2150 [ i ] = 0x9EE7F9D1C772505BLL ; 
        l_2124 = safe_add_func_uint64_t_u_u ( 
        safe_rshift_func_int8_t_s_s ( g_1729 [ 0 ] [ 3 ] =
         safe_add_func_int16_t_s_s ( 4L , l_2124 ) , 3 ) , l_2150 [ 0 ] ) ; } ; return 0 ; }
        """.trimIndent(),
    )
  }

  @Test
  fun testFunctionInliningWith4Args2() {
    testTransformation(
      transformation = transformationList.funcInline4Args,
      source =
        """
        void func_14(
            unsigned p_15,
            signed p_16,
            unsigned p_17,
            unsigned p_18,
            unsigned p_19
        ) {
            for (; g_900 < 45; ++g_900) {
                struct S0 l_2620 = { 8L, 666 };
                g_217[p_16] = g_1896;
                g_217[p_16] = l_2620;
            }
        }
        
        int main() {
            func_14(
                g_2.f0,
                g_1177[3][2][1],
                2,
                g_2.f4,
                9
            );
        }
        """.trimIndent(),
      expectOutput1 =
        """
        int main ( ) { for ( ; g_900 < 45 ; ++ g_900 ) 
        { struct S0 l_2620 = { 8L , 666 } ; g_217 [ g_1177 [ 3 ] [ 2 ] [ 1 ] ] = g_1896 ; 
        g_217 [ g_1177 [ 3 ] [ 2 ] [ 1 ] ] = l_2620 ; } ; }
        """.trimIndent(),
    )
  }

  @Test
  fun testFunctionInliningWith4ArgsNoType() {
    testTransformation(
      transformation = transformationList.funcInline4ArgsNoType,
      source =
        """
        void func_14(p_15, p_16, p_17, p_18) {
            for (; g_900 < 45; ++g_900) {
                struct S0 l_2620 = { 8L, 666 };
                g_217[p_16] = g_1896;
                g_217[p_16] = l_2620;
            }
        }
        
        int main() {
            func_14(1,2,3,4);
        }
        """.trimIndent(),
      expectOutput1 =
        """
        int main ( ) { for ( ; g_900 < 45 ; ++ g_900 ) { 
        struct S0 l_2620 = { 8L , 666 } ; g_217 [ 2 ] = g_1896 ; 
        g_217 [ p_16 ] = l_2620 ; } ; }
        """.trimIndent(),
    )
  }

  @Test
  fun testFunctionInliningWith3Args() {
    testTransformation(
      transformation = transformationList.funcInline3Args,
      source =
        """
        void func_1 ( int a , char b , int c ) { d = a ; }
        int main ( ) {
        func_1 ( g , "g" , g1 ) ;
        return 0 ; }
        """.trimIndent(),
      expectOutput1 = " int main ( ) { d = g ; ; return 0 ; }",
    )
  }

  @Test
  fun testFunctionInliningWith3ArgsNoType() {
    testTransformation(
      transformation = transformationList.funcInline3ArgsNoType,
      source =
        """
        void func_1 (a, b, c) { d = a ; }
        int main ( ) {
        func_1 ( g.x , "g" , g1 ) ;
        return 0 ; }
        """.trimIndent(),
      expectOutput1 = " int main ( ) { d = g.x ; ; return 0 ; }",
    )
  }

  @Test
  fun testFunctionInliningWith3ArgsLongParam() {
    testTransformation(
      transformation = transformationList.funcInline3Args,
      source =
        """
        void transparent_crc(unsigned val, char *vname, int flag) {
          crc32_context = val;
        }
        int main ( ) {
          transparent_crc(g_1729[i][j], "g_1729[i][j]", print_hash_value);
        return 0 ; }
        """.trimIndent(),
      expectOutput1 = "int main ( ) { crc32_context = g_1729 [ i ] [ j ] ; ; return 0 ; }",
    )
  }

  @Test
  fun testFunctionInliningWith2Args() {
    testTransformation(
      transformation = transformationList.funcInline2Args,
      source =
        """
        void func_1 ( int a , char b ) { d = a ; }
        int main ( ) {
        func_1 ( g , "g") ;
        return 0 ; }
        """.trimIndent(),
      expectOutput1 = " int main ( ) { d = g ; ; return 0 ; }",
    )
  }

  @Test
  fun testFunctionInliningWith2ArgsNoType() {
    testTransformation(
      transformation = transformationList.funcInline2ArgsNoType,
      source =
        """
        void func_1 (a , b) { d = a ; }
        int main ( ) {
        func_1 ( g , "g") ;
        return 0 ; }
        """.trimIndent(),
      expectOutput1 = " int main ( ) { d = g ; ; return 0 ; }",
    )
  }

  @Test
  fun testFunctionInliningWith1Arg() {
    testTransformation(
      transformation = transformationList.funcInline1Arg,
      source =
        """
        void func_1 ( int a ) { d = a ; }
        int main ( ) {
        func_1 ( g ) ;
        return 0 ; }
        """.trimIndent(),
      expectOutput1 = " int main ( ) { d = g ; ; return 0 ; }",
    )
  }

  @Test
  fun testFunctionInliningWith1ArgNoType() {
    testTransformation(
      transformation = transformationList.funcInline1ArgNoType,
      source =
        """
                void crc32_8bytes(val) {
            crc32_byte(val);
        }

        void transparent_crc(unsigned val, char *vname, int flag) {
            crc32_8bytes(val);
        }
        """.trimIndent(),
      expectOutput1 = """
        void transparent_crc ( unsigned val , char * vname , int flag ) { crc32_byte ( val ) ; ; }
      """,
    )
  }

  @Test
  fun testFunctionInliningNoArg() {
    testTransformation(
      transformation = transformationList.funcInlineNoArg,
      source =
        """
        void crc32_8bytes() {
            crc32_byte();
        }

        void transparent_crc(unsigned val, char *vname, int flag) {
            crc32_8bytes();
        }
        """.trimIndent(),
      expectOutput1 = """
        void transparent_crc ( unsigned val , char * vname , int flag ) { crc32_byte ( ) ; ; }
      """,
    )
  }

  @Test
  fun testVoidFunctionDefReturn() {
    testTransformation(
      transformation = transformationList.voidReturnFuncDef,
      source =
        """
        int func_1 ( int a , char b , int c ) { 
          for ( p_131 . f0 = 0 ; p_131 . f0 << 2 ; p_131 . f0 += 1 ) { } 
          d = a ; 
          return a; 
        }
        int main ( ) {
          func_1(1, '2', 3) ;
        return 0 ; }
        """.trimIndent(),
      expectOutput1 =
        """
        void func_1 ( int a , char b , int c ) { 
          for ( p_131 . f0 = 0 ; p_131 . f0 << 2 ; p_131 . f0 += 1 ) { } 
          d = a ; 
        }
        int main ( ) { func_1 ( 1 , '2' , 3 ) ; return 0 ; }
        """.trimIndent(),
    )
  }

  @Test
  fun testVoidFunctionCallReturn() {
    testTransformation(
      transformation = transformationList.voidReturnFuncDecl,
      source =
        """
        int func_1 ( int a , char b , int c );
        int main ( ) {
        return 0 ; }
        """.trimIndent(),
      expectOutput1 = "void func_1 ( int a , char b , int c ) ; int main ( ) { return 0 ; }",
    )
  }

  @Test
  fun testMultipleVoidFunctionCallsReturn() {
    testTransformation(
      transformation = transformationList.voidReturnFuncDecl,
      source =
        """
        int func_1 ( int a , char b , int c );
        int func_2 ( int a );
        int main ( ) {
        return 0 ; }
        """.trimIndent(),
      expectOutput1 =
        """
        int func_1 (int a , char b, int c); 
        void func_2 (int a); 
        int main() { return 0;}
        """.trimIndent(),
      expectOutput2 = """
        void func_1 (int a , char b, int c); 
        int func_2 ( int a ) ; 
        int main ( ) { return 0 ; }
        """,
    )
  }

  @Test
  fun testLocalToGlobal() {
    testTransformation(
      transformation = transformationList.localToGlobal,
      source = "int a; int main(int a) { int test; S0 f1; func1(test); }",
      expectOutput1 = "int test ; int a ; int main ( int a ) { S0 f1 ; func1 ( test ) ; }",
      expectOutput2 = "S0 f1 ; int a ; int main ( int a ) { int test ; func1 ( test ) ; }",
    )
  }

  @Test
  fun testVoidFunctionDefReturnNoMatch() {
    testTransformation(
      transformation = transformationList.voidReturnFuncDef,
      source =
        """
        int main ( ) {
          return 0 ; 
        }
        """.trimIndent(),
    )
  }

  @Test
  fun testAggregateStructToScalar() {
    testTransformation(
      transformation = transformationList.aggrStructToScalar2Args,
      source =
        """
        struct Point {
          int x;
          int y;
        };
        struct Point pt = {10, 20};
        
        int sum = pt.x + pt.y;
        """.trimIndent(),
      expectOutput1 = """
        struct Point { 
          int x ; 
          int y ; 
        };
        struct Point pt = {10, 20}; 
        
        int sum = 10 + 20 ;
      """,
    )
  }

  @Test
  fun testAggregateStructToScalar1Arg() {
    testTransformation(
      transformation = transformationList.aggrStructToScalar1Arg,
      source =
        """
        struct Point {
          int x;
        };
        struct Point pt = {10};
        
        int sum = pt.x;
        """.trimIndent(),
      expectOutput1 = """
        struct Point { 
          int x ; 
        };
        struct Point pt = {10}; 
        
        int sum = 10;
      """,
    )
  }

  @Test
  fun testSimplifyPlus() {
    testTransformation(
      transformation = transformationList.simplifyPlus,
      source =
        """
        int compute(int a, int b, int c) {
          return a + (b + c);
        }
        """.trimIndent(),
      expectOutput1 = "int compute ( int a , int b , int c ) { return a + b ; }",
    )
  }

  @Test
  fun testSimplifyMinus() {
    testTransformation(
      transformation = transformationList.simplifyMinus,
      source =
        """
        int compute(int a, int b, int c) {
          return a + (b - c);
        }
        """.trimIndent(),
      expectOutput1 = "int compute ( int a , int b , int c ) { return a + b ; }",
    )
  }

  @Test
  fun testSimplifyMultiply() {
    testTransformation(
      transformation = transformationList.simplifyMultiply,
      source =
        """
        int compute(int a, int b, int c) {
          return a + (b * c);
        }
        """.trimIndent(),
      expectOutput1 = "int compute ( int a , int b , int c ) { return a + b ; }",
    )
  }

  @Test
  fun testSimplifyDivide() {
    testTransformation(
      transformation = transformationList.simplifyDivide,
      source =
        """
        int compute(int a, int b, int c) {
          return a + (b / c);
        }
        """.trimIndent(),
      expectOutput1 = "int compute ( int a , int b , int c ) { return a + b ; }",
    )
  }

  @Test
  fun testCombineVar() {
    testTransformation(
      transformation = transformationList.combineVarDecl,
      source = "int a; int b;",
      expectOutput1 = "int a, b;",
      expectOutput2 = "int b, a;",
    )
  }

  @Test
  fun testCombineVar2() {
    testTransformation(
      transformation = transformationList.combineVarDecl,
      source = "int a; long b; int c;",
      expectOutput1 = "int c, a; long b;",
      expectOutput2 = "long b; int a, c;",
    )
  }

  @Test
  fun testCombineVar3() {
    testTransformation(
      transformation = transformationList.combineVarDecl,
      source = "int a;",
      expectOutput1 = null,
    )
  }

  @Test
  fun testCopyPropagation() {
    testTransformation(
      transformation = transformationList.copyPropagation,
      source =
        """
        struct Point { int x; int y; };
        
        int main() {
          struct Point pt1 = {10, 20};
          struct Point pt2 = pt1; 
          printf("X: %d, Y: %d\n", pt2.x, pt2.y); 
          return 0;
        }
        """.trimIndent(),
      expectOutput1 =
        """
        struct Point { int x ; int y ; } ; 
        
        int main ( ) { 
          struct Point pt1 = { 10 , 20 } ; 
          printf ( "X: %d, Y: %d\n" , pt1 . x , pt1 . y ) ; 
          return 0 ; 
        }
        """.trimIndent(),
    )
  }

  @Test
  fun testCopyPropagation2() {
    testTransformation(
      transformation = transformationList.copyPropagation,
      source =
        """
        int main() {
          int x = 0;
          int y = x;
          int z = y;
          return z;
        }
        """.trimIndent(),
      expectOutput1 =
        """
        int main() {
          int x = 0;
          int z = x;
          return z;
        }
        """.trimIndent(),
      expectOutput2 =
        """
        int main() {
          int x = 0;
          int y = x;
          return y;
        }
        """.trimIndent(),
    )
  }

  @Test
  fun testCopyPropagationNoTransformationShouldBePerformed() {
    testTransformation(
      transformation = transformationList.copyPropagation,
      source =
        """
        int main() {
            typedef int abc;
            abc b=  42;
            printf("answer is %d\n", b);
          }
        """.trimIndent(),
    )
  }

  @Test
  fun testCallExprToValue() {
    testTransformation(
      transformation = transformationList.callExprToVal,
      source =
        """
        int compute(int a, int b, int c) {
          return a + b + c;
        }
        
        int main() {
          int result = compute(1, 2, 3);
          return 0;
        }
        """.trimIndent(),
      expectOutput1 =
        """
        int compute ( int a , int b , int c ) 
        { return a + b + c ; } 
        int main ( ) 
        { int result = 0 ; return 0 ; }
        """.trimIndent(),
    )
  }

  @Test
  fun testEmptyStruct() {
    testTransformation(
      transformation = transformationList.emptyStructToInt,
      source =
        """
        struct Empty {
        };
        
        int main() {
          struct Empty myVar;
          return 0;
        }
        """.trimIndent(),
      expectOutput1 = "typedef int Empty ; int main ( ) { Empty myVar ; return 0 ; }",
    )
  }

  @Test
  fun testLiftAssignment() {
    testTransformation(
      transformation = transformationList.liftAssignment,
      source =
        """
        int main() {
          for (int i = 1; i <= 5; i++) {
            printf("%d\n", i);
          }
          return 0;
        }
        """.trimIndent(),
      expectOutput1 =
        """
        int main ( ) {int i = 1; for ( ; i <= 5 ; i ++ ) { printf ( "%d\n" , i ); } return 0; }
        """.trimIndent(),
    )
  }

  @Test
  fun testMoveDefToDecl() {
    testTransformation(
      transformation = transformationList.moveDefToDecl,
      source =
        """
        static func_59(unsigned, short, unsigned, unsigned, struct S0);

        struct S0 func_59(unsigned p_60, short p_61, unsigned p_62, unsigned p_63, struct S0 p_64) {
            p_64.f3;
        lbl_903:
            ;
            goto lbl_903;
        }
        """.trimIndent(),
      expectOutput1 =
        """
        struct S0 func_59 ( unsigned p_60 , short p_61 , 
        unsigned p_62 , unsigned p_63 , struct S0 p_64 ) 
        { p_64 . f3 ; lbl_903 : ; goto lbl_903 ; }
        """.trimIndent(),
    )
  }

  @Test
  fun testMoveDefToDecl2() {
    testTransformation(
      transformation = transformationList.moveDefToDecl2,
      source =
        """
        unsigned func_12(char, int);
        
        int main() {
            return 0;
        }

        unsigned func_12(char p_13, int p_14) {
            func_22(p_14, p_14, g_15, 18446744073709551613UL, g_15);
            return p_13;
        }
        """.trimIndent(),
      expectOutput1 =
        """
        unsigned func_12 ( char p_13 , int p_14 ) 
        { func_22 ( p_14 , p_14 , g_15 , 18446744073709551613UL , g_15 ) ; return p_13 ; } 
        int main ( ) { return 0 ; }
        """.trimIndent(),
    )
  }

  @Test
  fun testMoveDefToDeclNoParam() {
    testTransformation(
      transformation = transformationList.moveDefToDeclNoParam,
      source =
        """
        static func_12 ( ) ;
        
        int main() {
          return 0;
        }
        
        unsigned func_12( ) {
            func_22(p_14, p_14, g_15, 18446744073709551613UL, g_15);
            return p_13;
        }
        """.trimIndent(),
      expectOutput1 =
        """
        unsigned func_12 ( ) 
        { func_22 ( p_14 , p_14 , g_15 , 18446744073709551613UL , g_15 ) ; return p_13 ; } 
        int main ( ) { return 0 ; }
        """.trimIndent(),
    )
  }

  @Test
  fun testMoveDefToDeclNoParam2() {
    testTransformation(
      transformation = transformationList.moveDefToDeclNoParam2,
      source =
        """
        unsigned func_12 ( ) ;
        
        int main() {
          return 0;
        }
        
        unsigned func_12( ) {
            func_22(p_14, p_14, g_15, 18446744073709551613UL, g_15);
            return p_13;
        }
        """.trimIndent(),
      expectOutput1 =
        """
        unsigned func_12 ( ) 
        { func_22 ( p_14 , p_14 , g_15 , 18446744073709551613UL , g_15 ) ; return p_13 ; } 
        int main ( ) { return 0 ; }
        """.trimIndent(),
    )
  }

  @Test
  fun testReduceArrDim() {
    testTransformation(
      transformation = transformationList.reduceArrDim,
      source =
        """
        struct S0 g_152[2];
        
        struct S0 left(int S0, struct S0 f0) {
          g_152[0] = l_151;
        
          if (!g_152[0].f0) {
            ;
          } 
        }
        """.trimIndent(),
      expectOutput1 =
        """
        struct S0 g_152 ; struct S0 left ( int S0 , struct S0 f0 ) 
        { g_152 = l_151 ; if ( ! g_152 . f0 ) { ; } }
        """.trimIndent(),
    )
  }

  @Test
  fun testReduceArrDim2() {
    testTransformation(
      transformation = transformationList.reduceArrDim2,
      source =
        """
        unsigned g_1729[1][4];
        
        int main() {
          g_1729[0][3] = safe_add_func_int16_t_s_s(4L, l_2124);
        }
        """.trimIndent(),
      expectOutput1 =
        """
        unsigned g_1729 [ 1 ] ; int main ( ) 
        { g_1729 [ 0 ] = safe_add_func_int16_t_s_s ( 4L , l_2124 ) ; }
        """.trimIndent(),
    )
  }

  @Test
  fun testReduceArrDim3() {
    testTransformation(
      transformation = transformationList.reduceArrDim3,
      source =
        """
        static int g_1177[4][5][2];
        
        int main() {
          func_14(
              g_2.f0,
              g_1177[3][2][1],
              2,
              g_2.f4,
              9
          );
        }
        """.trimIndent(),
      expectOutput1 =
        """
        static int g_1177 [ 4 ] [ 5 ] ; int main ( ) 
        { func_14 ( g_2 . f0 , g_1177 [ 3 ] [ 2 ] , 2 , g_2 . f4 , 9 ) ; }
        """.trimIndent(),
    )
  }

  @Test
  fun testRemoveAddr() {
    testTransformation(
      transformation = transformationList.removeAddrTaken,
      source =
        """
        void myFunction() {
          int x = 10;
          int *ptr = &x;        
          if (&x == 0) {       
              printf("x is null.\n");
          }
          printf("%d\n", x);
          myFunction2(&x);     
        }
        
        void myFunction2() {}  
        """.trimIndent(),
      expectOutput1 = """
        void myFunction ( ) { 
          int x = 10 ; 
          int * ptr = & x ; 
          if ( & x == 0 ) { printf ( "x is null.\n" ) ; } 
          printf ( "%d\n" , x ) ; 
          myFunction2 ( x ) ; 
        } 
        void myFunction2 ( ) { }
        """,
      expectOutput2 = """
        void myFunction ( ) { 
          int x = 10 ; 
          int * ptr = x ; 
          if ( & x == 0 ) { printf ( "x is null.\n" ) ; } 
          printf ( "%d\n" , x ) ; 
          myFunction2 ( & x ) ; 
        } 
        void myFunction2 ( ) { } 
        """,
      expectOutput3 = """
        void myFunction ( ) { 
          int x = 10 ; 
          int * ptr = & x ; 
          if ( x == 0 ) { printf ( "x is null.\n" ) ; } 
          printf ( "%d\n" , x ) ; 
          myFunction2 ( & x ) ; 
        } 
        void myFunction2 ( ) { }
        """,
    )
  }

  @Test
  fun testRemoveAssignment() {
    testTransformation(
      transformation = transformationList.removeAssignment,
      source = """
        int main() {
          func_1 = safe_rshift_func_int8_t_s_s(
                  g_1729[0][3] = func_1,
                  3
          ) + left;
          return 0;
        }
        """,
      expectOutput1 = """
        int main ( ) { func_1 = safe_rshift_func_int8_t_s_s ( func_1 , 3 ) + left ; return 0 ; }
        """,
    )
  }

  @Test
  fun testReplaceArrayAccessWithIndex() {
    testTransformation(
      transformation = transformationList.replaceArrayAccessWithIndex,
      source = """
        int main() {
          int a = g_1729[0];
          return 0;
        }
        """,
      expectOutput1 = "int main ( ) { int a = 0 ; return 0 ; }",
    )
  }

  @Test
  fun testReplaceDefByDecl() {
    testTransformation(
      transformation = transformationList.replaceDefByDecl,
      source = """
        struct S0 func_59(unsigned p_60, short p_61, unsigned p_62, unsigned p_63, struct S0 p_64) {
            p_64.f3;
        lbl_903:
            ;
            goto lbl_903;
        }
        """,
      expectOutput1 = """
        struct S0 func_59 ( 
        unsigned p_60 , short p_61 , unsigned p_62 , unsigned p_63 , struct S0 p_64 ) ;
        """,
    )
  }

  @Test
  fun testSimplifyComma() {
    testTransformation(
      transformation = transformationList.simplifyComma,
      source = """
        int main() {
            int x = 10, y = 20;
            (x++ , y--);
            return 0;
        }
        """,
      expectOutput1 = """
        int main ( ) { int x = 10 , y = 20 ; x ++ ; ( y -- ) ; return 0 ; }
        """,
    )
  }

  @Test
  fun testSimplifyCallExpr() {
    testTransformation(
      transformation = transformationList.simplifyCallExpr,
      source = """
        double foo(char c, float f, enum Colors {RED, GREEN, BLUE} color) {
            char a = c;
            return f;
        }
        
        int main() {
            char c = 'A';
            float f = 3.14;
            enum Colors color = GREEN;
        
            foo(c, f, color);
        
            return 0;
        }
        """,
      expectOutput1 = """
        double foo ( char c , float f , enum Colors { RED , GREEN , BLUE } color ) 
        { char a = c ; return f ; } 
        int main ( ) 
        { char c = 'A' ; float f = 3.14 ; enum Colors color = GREEN ; ( 0 , 0, 0 ) ; return 0 ; }
        """,
    )
  }

  @Test
  fun testSimplifyIf() {
    testTransformation(
      transformation = transformationList.simplifyIf,
      source = """
        int main() {
          if (x > 0) {
              printf("Positive");
          } else if (x == 0) {
              printf("Zero");
          } else {
              printf("Negative");
          }
          
          return 0;
        }
        """,
      expectOutput1 = """
        int main ( ) { if ( x > 0 ) { printf ( "Positive" ) ; } 
        if ( x == 0 ) { printf ( "Zero" ) ; } else { printf ( "Negative" ) ; } return 0 ; }
        """,
    )
  }

  @Test
  fun testSimplifyIf2() {
    testTransformation(
      transformation = transformationList.simplifyIf2,
      source = """
        int main() {
          if (x > 0) {
              printf("Positive");
          } else {
              printf("Negative");
          }
          
          return 0;
        }
        """,
      expectOutput1 = """
        int main ( ) { if ( x > 0 ) { printf ( "Positive" ) ; } return 0 ; }
        """,
    )
  }

  @Test
  fun testSimplifyStructDecl() {
    testTransformation(
      transformation = transformationList.simplifyStructDecl,
      source = """
        struct Point {
            int x;
            int y;
        };
        
        struct Point p1;
        
        int main() {
            p1.x = 10;
            p1.y = 20;
            printf("Point: (%d, %d)\n", p1.x, p1.y);
            return 0;
        }
        """,
      expectOutput1 = """
        struct Point { int x ; int y ; } p1 ; 
        int main ( ) { p1 . x = 10 ; p1 . y = 20 ; 
        printf ( "Point: (%d, %d)\n" , p1 . x , p1 . y ) ; return 0 ; }
        """,
    )
  }

  @Test
  fun testSimplifyUnionDecl() {
    testTransformation(
      transformation = transformationList.simplifyUnionDecl,
      source = """
        union Point {
            int x;
            int y;
        };
        
        union Point p1;
        
        int main() {
            p1.x = 10;
            p1.y = 20;
            printf("Point: (%d, %d)\n", p1.x, p1.y);
            return 0;
        }
        """,
      expectOutput1 = """
        union Point { int x ; int y ; } p1 ; 
        int main ( ) { p1 . x = 10 ; p1 . y = 20 ; 
        printf ( "Point: (%d, %d)\n" , p1 . x , p1 . y ) ; return 0 ; }
        """,
    )
  }

  @Test
  fun testUnifyFunctionDecl() {
    testTransformation(
      transformation = transformationList.unifyFunctionDecl,
      source = """
        static int add(int a, int b); 

        int add(int a, int b) { 
            return a + b;
        }
        
        int main() {
            int result = add(5, 3);
            return result;
        }
        """,
      expectOutput1 = """
        static int add ( int a , int b ) { return a + b ; } 
        int main ( ) { int result = add ( 5 , 3 ) ; return result ; }
        """,
    )
  }

  @Test
  fun testUnionToStruct() {
    testTransformation(
      transformation = transformationList.unionToStruct,
      source = """
        union MyUnion {
            int a;
            int b;
        };
        
        int main() {
            union MyUnion u = { .a = 42 }; 
            u.b = 100;
            printf("a: %d, b: %d\n", u.a, u.b); 
        
            return 0;
        }
        """,
      expectOutput1 = """
        struct MyUnion { int a ; int b ; } ; int main ( ) 
        { struct MyUnion u = { . a = 42 } ; u . b = 100 ; 
        printf ( "a: %d, b: %d\n" , u . a , u . b ) ; return 0 ; }
        """,
    )
  }

  @Test
  fun testReplaceCallExpr1Arg() {
    testTransformation(
      transformation = transformationList.replaceCallExpr1Arg,
      source = """     
        short safe_add_func_int16_t_s_s(short si2) {
            return si2;
        }
        
        int main() {
          g_1729[0][3] = safe_add_func_int16_t_s_s( l_2124);
        }
        """,
      expectOutput1 = """
        int main ( ) { g_1729 [ 0 ] [ 3 ] = l_2124 ; }
        """,
    )
  }

  @Test
  fun testReplaceCallExpr2Arg() {
    testTransformation(
      transformation = transformationList.replaceCallExpr2Arg,
      source = """     
        char safe_rshift_func_int8_t_s_s(char left, int right) {
            return left;
        }
        
        int main() {
          l_2124 = safe_add_func_uint64_t_u_u(
            safe_rshift_func_int8_t_s_s(
                g_1729[0][3] = safe_add_func_int16_t_s_s(4L, l_2124),
                3),
            l_2150[0]);
        }
        """,
      expectOutput1 = """
        int main ( ) { l_2124 = safe_add_func_uint64_t_u_u ( 
        g_1729 [ 0 ] [ 3 ] = safe_add_func_int16_t_s_s ( 4L , l_2124 ) , l_2150 [ 0 ] ) ; }
        """,
    )
  }

  @Test
  fun testVoidReturnFunctionDeclLatraTransformation() {
    testTransformation(
      transformation = transformationList.voidReturnFuncDecl,
      source = """
         #include <stdio.h>
         void multiply(int a, int b);
         int main() {
             int b = 42;
             printf("answer is %d\n", b);
             if(b > 15){ printf("Large\n"); }
             int a=  10;
             int i = 0;
             for( ; i < 3 ; i ++ ) {
                 printf ( "Loop %d\n" , i ) ;
             }
         } 
      """,
    )
  }

  @Test
  fun testReplaceCallExpr3Arg() {
    testTransformation(
      transformation = transformationList.replaceCallExpr3Arg,
      source = """     
        short safe_lshift_func_uint8_t_u_s(short left, short right, short mid) {
            return left > mid ? left : left << right;
        }
  
        int main () {
            left = safe_lshift_func_uint8_t_u_s(g_152[0].f0, 2, 1) && f0.f1;
        }
        """,
      expectOutput1 = """
        int main ( ) { left = g_152 [ 0 ] . f0 > 1 ? left : left << 2 && f0 . f1 ; }
        """,
    )
  }
}
