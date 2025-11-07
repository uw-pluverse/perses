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
package org.perses.reduction.reducer.latra.c

import org.perses.reduction.reducer.latra.AbstractLatraTransformationList

object CTransformationList : AbstractLatraTransformationList() {
  val aggrStructToScalar1Arg =
    registerTransformation(
      name = "AggregateStructToScalar1ArgTransformation",
      from = "struct :[structName] :[var] = { :[mem1] };",
      such_as = "struct Point pt = { 10 , 20 };",
      to = "struct :[structName] :[var] = { :[mem1] };",
      global_replace = {
        replace(
          pattern = ":[var].:[x]",
          with = ":[mem1]",
        )
      },
    )

  val aggrStructToScalar2Args =
    registerTransformation(
      name = "AggregateStructToScalar2ArgsTransformation",
      from = "struct :[structName] :[var] = { :[mem1], :[mem2] };",
      such_as = "struct Point pt = { 10 , 20 };",
      to = "struct :[structName] :[var] = { :[mem1], :[mem2] };",
      global_replace = {
        replace(
          pattern = ":[var].:[x]",
          with = ":[mem1]",
        )
        replace(
          pattern = ":[var].:[y]",
          with = ":[mem2]",
        )
      },
    )

  val simplifyDivide =
    registerTransformation(
      name = "DivideOperationSimplification",
      from = "( :[var1] / :[var2] )",
      such_as = "( x / y )",
      to = ":[var1]",
    )

  val simplifyMultiply =
    registerTransformation(
      name = "MultiplyOperationSimplification",
      from = "( :[var1] * :[var2] )",
      such_as = "( x * y )",
      to = ":[var1]",
    )

  val simplifyMinus =
    registerTransformation(
      name = "MinusOperationSimplification",
      from = "( :[var1] - :[var2] )",
      such_as = "( x - y )",
      to = ":[var1]",
    )

  val simplifyPlus =
    registerTransformation(
      name = "PlusOperationSimplification",
      from = "( :[var1] + :[var2] )",
      such_as = "( x + y )",
      to = ":[var1]",
    )

  val localToGlobal =
    registerTransformation(
      name = "LocalToGlobalTransformation",
      from = ":[type] :[name];",
      insert = {
        insert(pattern = ":[type] :[name];", location = "top")
      },
    )

  val unionToStruct =
    registerTransformation(
      name = "UnionToStruct",
      from = "union :[name] { :[something+] } ;",
      such_as = "union MyUnion { int i ; } ;",
      to = "struct :[name] { :[something] } ;",
      global_replace = {
        replace(
          pattern = "union :[name]",
          such_as = "union U",
          with = "struct :[name]",
        )
      },
    )

  val voidReturnFuncDecl =
    registerTransformation(
      name = "VoidReturnFunctionDeclLatraTransformation",
      from = ":[retType] :[name] (:[parameterList+]);",
      to = "void :[name] ( :[parameterList] );",
    )

  val voidReturnFuncDef =
    registerTransformation(
      name = "VoidReturnFunctionDefLatraTransformation",
      from = """
        :[declarationSpecifier] :[name] ( :[parameterList+] ) { 
          :[block+] 
        }
    """,
      where = ":[name] != main",
      to = """
        void :[name] ( :[parameterList] ) { 
          :[block] 
        }
    """,
      global_replace = {
        replace(
          pattern = "return :[stm+];",
          inside = "block",
          with = "",
        )
      },
    )

  val funcInline4Args =
    registerTransformation(
      name = "FunctionInlining4Args",
      from =
        """
        :[retType] :[name] (
          :[type1+] :[param1+], :[type2+] :[param2+], :[type3+] :[param3+], :[type4+] :[param4+]
        ) { 
          :[block+] 
        }
        """.trimIndent(),
      such_as =
        """
        int func(int a) {
          return a;
        }
        """.trimIndent(),
      global_replace = {
        replace(
          pattern = ":[name](:[paramCall1+], :[paramCall2+], :[paramCall3+], :[paramCall4+])",
          with = ":[block]",
        )
        replace(
          pattern = ":[param1]",
          inside = "block",
          with = ":[paramCall1]",
          matchAll = true,
        )
        replace(
          pattern = ":[param2]",
          inside = "block",
          with = ":[paramCall2]",
          matchAll = true,
        )
        replace(
          pattern = ":[param3]",
          inside = "block",
          with = ":[paramCall3]",
          matchAll = true,
        )
        replace(
          pattern = ":[param4]",
          inside = "block",
          with = ":[paramCall4]",
          matchAll = true,
        )
      },
    )

  val funcInline4ArgsNoType =
    registerTransformation(
      name = "FunctionInlining4ArgsNoType",
      from =
        """
        :[retType] :[name] (:[param1+], :[param2+], :[param3+], :[param4+]) { 
          :[block+] 
        }
        """.trimIndent(),
      such_as =
        """
        int func(int a) {
          return a;
        }
        """.trimIndent(),
      global_replace = {
        replace(
          pattern = ":[name](:[paramCall1+], :[paramCall2+], :[paramCall3+], :[paramCall4+])",
          with = ":[block]",
        )
        replace(
          pattern = ":[param1]",
          inside = "block",
          with = ":[paramCall1]",
        )
        replace(
          pattern = ":[param2]",
          inside = "block",
          with = ":[paramCall2]",
        )
        replace(
          pattern = ":[param3]",
          inside = "block",
          with = ":[paramCall3]",
        )
        replace(
          pattern = ":[param4]",
          inside = "block",
          with = ":[paramCall4]",
        )
      },
    )

  val funcInline3Args =
    registerTransformation(
      name = "FunctionInliningLatraTransformation",
      from =
        """
        :[retType] :[name] (:[type1+] :[param1+], :[type2+] :[param2+], :[type3+] :[param3+]) { 
          :[block+] 
        }
        """.trimIndent(),
      such_as =
        """
        int func(int a) {
          return a;
        }
        """.trimIndent(),
      global_replace = {
        replace(
          pattern = ":[name](:[paramCall1+], :[paramCall2+], :[paramCall3+])",
          with = ":[block]",
        )
        replace(
          pattern = ":[param1]",
          inside = "block",
          with = ":[paramCall1]",
        )
        replace(
          pattern = ":[param2]",
          inside = "block",
          with = ":[paramCall2]",
        )
        replace(
          pattern = ":[param3]",
          inside = "block",
          with = ":[paramCall3]",
        )
      },
    )

  val funcInline3ArgsNoType =
    registerTransformation(
      name = "FunctionInlining3ArgsNoType",
      from =
        """
        :[retType] :[name] (:[param1+], :[param2+], :[param3+]) { 
          :[block+] 
        }
        """.trimIndent(),
      such_as =
        """
        int func(int a) {
          return a;
        }
        """.trimIndent(),
      global_replace = {
        replace(
          pattern = ":[name](:[paramCall1+], :[paramCall2+], :[paramCall3+])",
          with = ":[block]",
        )
        replace(
          pattern = ":[param1]",
          inside = "block",
          with = ":[paramCall1]",
        )
        replace(
          pattern = ":[param2]",
          inside = "block",
          with = ":[paramCall2]",
        )
        replace(
          pattern = ":[param3]",
          inside = "block",
          with = ":[paramCall3]",
        )
      },
    )

  val funcInline2Args =
    registerTransformation(
      name = "FunctionInlining2Args",
      from =
        """
        :[retType] :[name] (:[type1] :[param1], :[type2] :[param2]) { 
          :[block+] 
        }
        """.trimIndent(),
      such_as =
        """
        int func(int a) {
          return a;
        }
        """.trimIndent(),
      global_replace = {
        replace(
          pattern = ":[name] ( :[paramCall1] , :[paramCall2+] )",
          with = ":[block]",
          mustMatch = true,
        )
        replace(
          pattern = ":[param1]",
          inside = "block",
          with = ":[paramCall1]",
        )
        replace(
          pattern = ":[param2]",
          inside = "block",
          with = ":[paramCall2]",
        )
      },
    )

  val funcInline2ArgsNoType =
    registerTransformation(
      name = "FunctionInlining2ArgsNoType",
      from =
        """
        :[retType] :[name] (:[param1+], :[param2+]) { 
          :[block+] 
        }
        """.trimIndent(),
      such_as =
        """
        int func(int a) {
          return a;
        }
        """.trimIndent(),
      global_replace = {
        replace(
          pattern = ":[name] ( :[paramCall1] , :[paramCall2+] )",
          with = ":[block]",
          mustMatch = true,
        )
        replace(
          pattern = ":[param1]",
          inside = "block",
          with = ":[paramCall1]",
        )
        replace(
          pattern = ":[param2]",
          inside = "block",
          with = ":[paramCall2]",
        )
      },
    )

  val funcInline1Arg =
    registerTransformation(
      name = "FunctionInlining1Arg",
      from =
        """
        :[retType] :[name] (:[type1] :[param1]) { 
          :[block+] 
        }
        """.trimIndent(),
      such_as =
        """
        int func(int a) {
          return a;
        }
        """.trimIndent(),
      global_replace = {
        replace(
          pattern = ":[name](:[paramCall1+]);",
          with = ":[block];",
          mustMatch = true,
        )
        replace(
          pattern = ":[param1]",
          inside = "block",
          with = ":[paramCall1]",
        )
      },
    )

  val funcInline1ArgNoType =
    registerTransformation(
      name = "FunctionInlining1ArgNoType",
      from =
        """
        :[retType] :[name] (:[param1+]) { 
          :[block+] 
        }
        """.trimIndent(),
      such_as =
        """
        int func(int a) {
          return a;
        }
        """.trimIndent(),
      global_replace = {
        replace(
          pattern = ":[name](:[paramCall1+]);",
          with = ":[block];",
          mustMatch = true,
        )
        replace(
          pattern = ":[param1]",
          inside = "block",
          with = ":[paramCall1]",
        )
      },
    )

  val funcInlineNoArg =
    registerTransformation(
      name = "FunctionInliningNoArg",
      from =
        """
        :[retType] :[name] ( ) { 
          :[block+] 
        }
        """.trimIndent(),
      such_as =
        """
        int func(int a) {
          return a;
        }
        """.trimIndent(),
      global_replace = {
        replace(
          pattern = ":[name]();",
          with = ":[block];",
          mustMatch = true,
        )
      },
    )

  val liftAssignment =
    registerTransformation(
      name = "LiftAssignmentExpr",
      from = "for ( :[asg+] ; :[cond+] ; :[expr+] ) { :[block+] }",
      to = "for ( ; :[cond] ; :[expr] ) { :[block] }",
      insert = {
        insert(pattern = ":[asg];", location = "before")
      },
    )

  val copyPropagation =
    registerTransformation(
      name = "CopyPropagation",
      from = ":[type+] :[a] = :[b+];",
      such_as = "int a = b;",
      to = ":[type] :[a] = :[b];",
      global_replace = {
        replace(
          pattern = ":[type+] :[c] = :[a];",
          with = "",
        )
        replace(
          pattern = ":[c]",
          with = ":[a]",
        )
      },
    )

  val callExprToVal =
    registerTransformation(
      name = "CallExprToValue",
      from = ":[type+] :[funcName] ( :[param+] ) { :[body+] }",
      to = ":[type] :[funcName] ( :[param] ) { :[body] }",
      global_replace = {
        replace(
          pattern = ":[funcName]( :[callParam+] )",
          with = "0",
        )
      },
    )

  val replaceCallExpr1Arg =
    registerTransformation(
      name = "ReplaceCallExpr1Arg",
      from = ":[retType+] :[sym] ( :[type+] :[param1+] ) { return :[stm+] ; }",
      to = "",
      global_replace = {
        replace(
          pattern = ":[sym] ( :[paramCall1+] )",
          with = ":[stm]",
          mustMatch = true,
        )
        replace(
          pattern = ":[param1+]",
          inside = "stm",
          with = ":[paramCall1]",
        )
      },
    )

  val replaceCallExpr2Arg =
    registerTransformation(
      name = "ReplaceCallExpr2Arg",
      from = ":[retType+] :[sym] (:[type1+] :[param1+], :[type2+] :[param2+]) { return :[stm+] ; }",
      to = "",
      global_replace = {
        replace(
          pattern = ":[sym] ( :[paramCall1+], :[paramCall2+] )",
          with = ":[stm]",
          mustMatch = true,
        )
        replace(
          pattern = ":[param1+]",
          inside = "stm",
          with = ":[paramCall1]",
        )
        replace(
          pattern = ":[param2+]",
          inside = "stm",
          with = ":[paramCall2]",
        )
      },
    )

  val replaceCallExpr3Arg =
    registerTransformation(
      name = "ReplaceCallExpr3Arg",
      from =
        """
        :[retType+] :[sym] ( 
          :[type1+] :[param1+], :[type2+] :[param2+] , :[type3+] :[param3+]
          ) { return :[stm+] ; }
        """.trimIndent(),
      to = "",
      global_replace = {
        replace(
          pattern = ":[sym] ( :[paramCall1+], :[paramCall2+], :[paramCall3+] )",
          with = ":[stm]",
          mustMatch = true,
        )
        replace(
          pattern = ":[param1+]",
          inside = "stm",
          with = ":[paramCall1]",
        )
        replace(
          pattern = ":[param2+]",
          inside = "stm",
          with = ":[paramCall2]",
        )
        replace(
          pattern = ":[param3+]",
          inside = "stm",
          with = ":[paramCall3]",
        )
      },
    )

  val simplifyCallExpr =
    registerTransformation(
      name = "SimplifyCallExpr",
      from = ":[funcName] (:[param1+], :[param2+], :[param3+]);",
      such_as =
        """
        int main() {
         {:foo(c, f);:}
        }
        """.trimIndent(),
      to = "(0, 0, 0);",
    )

  val simplifyIf =
    registerTransformation(
      name = "SimplifyIf",
      from =
        """
        if(:[cond1+]) { 
          :[block1+] 
        } else if (:[cond2+]) { 
          :[block2+] 
        } else { 
          :[block3+] 
        }  
        """,
      such_as =
        """
        if (x > 0) {
            printf("Positive");
        } else if (x == 0) {
            printf("Zero");
        } else {
            printf("Negative");
        }
        """.trimIndent(),
      to = "if ( :[cond1] ) { :[block1] } if ( :[cond2] ) { :[block2] } else { :[block3] }",
    )

  val simplifyIf2 =
    registerTransformation(
      name = "SimplifyIf2",
      from = "if (:[cond1+]) { :[block1+] } else { :[block2+] }",
      such_as =
        """
        if (x > 0) {
            printf("Positive");
        } else {
            printf("Negative");
        }
        """.trimIndent(),
      to = "if ( :[cond1] ) { :[block1] }",
    )

  val reduceArrDim3 =
    registerTransformation(
      name = "ReduceArrayDim3",
      from = ":[type+] :[var][:[index1]][:[index2]][:[index3]];",
      to = ":[type] :[var][:[index1]][:[index2]];",
      global_replace = {
        replace(
          pattern = ":[var][:[index4]][:[index5]][:[index6]]",
          with = ":[var][:[index4]][:[index5]]",
        )
      },
    )

  val reduceArrDim2 =
    registerTransformation(
      name = "ReduceArrayDim2",
      from = ":[type+] :[var][:[index1]][:[index2]];",
      to = ":[type] :[var][:[index1]];",
      global_replace = {
        replace(
          pattern = ":[var][:[index3]][:[index4]]",
          with = ":[var][:[index3]]",
        )
      },
    )

  val reduceArrDim =
    registerTransformation(
      name = "ReduceArrayDim",
      from = ":[type+] :[var] [:[index1]];",
      to = ":[type] :[var];",
      global_replace = {
        replace(
          pattern = ":[var][:[index2]]",
          with = ":[var]",
        )
        // Added as the above pattern cannot match the below cases
        replace(
          pattern = ":[var][:[index2]].:[mem]",
          with = ":[var].:[mem]",
        )
      },
    )

  val moveDefToDecl =
    registerTransformation(
      name = "MoveFuncDefToDecl",
      from = ":[type+] :[sym] ( :[paramList+] ) { :[block+] }",
      global_replace = {
        replace(
          pattern = "static :[sym] ( :[paramList2+] ) ;",
          with = ":[type] :[sym] ( :[paramList] ) { :[block] }",
          mustMatch = true,
        )
      },
    )

  val moveDefToDecl2 =
    registerTransformation(
      name = "MoveFuncDefToDecl2",
      from = ":[type+] :[sym] ( :[paramList+] ) { :[block+] }",
      global_replace = {
        replace(
          pattern = ":[type+] :[sym] ( :[paramList2+] ) ;",
          with = ":[type] :[sym] ( :[paramList] ) { :[block] }",
          mustMatch = true,
        )
      },
    )

  val moveDefToDeclNoParam =
    registerTransformation(
      name = "MoveFuncDefToDeclNoParam",
      from = ":[type+] :[sym] ( ) { :[block+] }",
      where = ":[sym] != main",
      global_replace = {
        replace(
          pattern = "static :[sym] ( ) ;",
          with = ":[type] :[sym] ( ) { :[block] }",
          mustMatch = true,
        )
      },
    )

  val moveDefToDeclNoParam2 =
    registerTransformation(
      name = "MoveFuncDefToDeclNoParam2",
      from = ":[type] :[sym] ( ) { :[block+] }",
      where = ":[sym] != main",
      global_replace = {
        replace(
          pattern = ":[type+] :[sym] ( ) ;",
          with = ":[type] :[sym] ( ) { :[block] }",
          mustMatch = true,
        )
      },
    )

  val simplifyComma =
    registerTransformation(
      name = "SimplifyComma",
      from = "( :[x+] , :[y+] ) ;",
      such_as =
        """
        int main() {
          int x = 10, y = 20;
          {:(x++, y--);:}
          return 0;
        }
        """.trimIndent(),
      to = ":[x]; (:[y] );",
    )

  val typedef =
    registerTransformation(
      name = "TypeDefTransform",
      from = "typedef :[specifier+] :[alias];",
      global_replace = {
        replace(
          pattern = ":[alias]",
          with = ":[specifier]",
        )
      },
    )

  val emptyStructToInt =
    registerTransformation(
      name = "EmptyStructToInt",
      from = "struct :[name] { };",
      to = "typedef int :[name];",
      global_replace = {
        replace(
          pattern = "struct :[name] :[idt] ;",
          with = ":[name] :[idt] ;",
        )
      },
    )

  val removeAssignment =
    registerTransformation(
      name = "RemoveAssignment",
      from = ":[var+] = :[expr]",
      such_as = "g_1729[0][3] = func_1",
      to = ":[expr]",
    )

  val removeAddrTaken =
    registerTransformation(
      name = "RemoveAddrTaken",
      from = "&:[var]",
      such_as = "&x",
      to = ":[var]",
    )

  val replaceArrayAccessWithIndex =
    registerTransformation(
      name = "ReplaceArrayAccessWithIndex",
      from = ":[var] [:[index]]",
      such_as = "arr[i]",
      to = ":[index]",
    )

  val simplifyUnionDecl =
    registerTransformation(
      name = "SimplifyUnionDecl",
      from = "union :[name1] :[var1] ;",
      such_as = "union Point p1;",
      global_replace = {
        replace(
          pattern = "union :[name1] { :[param1+] } ;",
          such_as = "union Point { int x; int y; };",
          with = "union :[name1] { :[param1] } :[var1] ;",
          mustMatch = true,
        )
      },
    )

  val simplifyStructDecl =
    registerTransformation(
      name = "SimplifyStructDecl",
      from = "struct :[name1] :[var1] ;",
      such_as = "struct Point p1;",
      global_replace = {
        replace(
          pattern = "struct :[name1] { :[param1+] } ;",
          such_as = "struct Point { int x; int y; };",
          with = "struct :[name1] { :[param1] } :[var1] ;",
          mustMatch = true,
        )
      },
    )

  val replaceDefByDecl =
    registerTransformation(
      name = "ReplaceDefByDecl",
      from = ":[type+] :[sym] ( :[paramList+] ) { :[block+] }",
      such_as = "int func(int a) {return 0;}",
      to = ":[type] :[sym] ( :[paramList] ) ;",
    )

  val combineVarDecl =
    registerTransformation(
      name = "CombineLocalVarDecl",
      from = ":[retType] :[name];",
      such_as = "int a;",
      global_replace = {
        replace(
          pattern = ":[retType] :[name2];",
          such_as = "int b;",
          with = ":[retType] :[name], :[name2];",
          mustMatch = true,
        )
      },
    )
  val unifyFunctionDecl =
    registerTransformation(
      name = "UnifyFunctionDecl",
      from = "static :[type] :[name] ( :[param+] ) ;",
      such_as = "static int func1 ( int a ) ;",
      global_replace = {
        replace(
          pattern = ":[type] :[name] ( :[param2+] ) { :[block+] }",
          such_as = "int func ( int a ) { return a; }",
          with = "static :[type] :[name] (:[param2] ) {:[block]}",
          mustMatch = true,
        )
      },
    )
}
