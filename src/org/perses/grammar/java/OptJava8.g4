/*
 * [The "BSD license"]
 *  Copyright (c) 2014 Terence Parr
 *  Copyright (c) 2014 Sam Harwell
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. The name of the author may not be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 *  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 *  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 *  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 *  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 *  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * A Java 8 grammar for ANTLR 4 derived from the Java Language Specification
 * chapter 19.
 *
 * NOTE: This grammar results in a generated parser that is much slower
 *       than the Java 7 grammar in the grammars-v4/java directory. This
 *     one is, however, extremely close to the spec.
 *
 * You can test with
 *
 *  $ antlr4 Java8.g4
 *  $ javac *.java
 *  $ grun Java8 compilationUnit *.java
 *
 * Or,
~/antlr/code/grammars-v4/java8 $ java Test .
/Users/parrt/antlr/code/grammars-v4/java8/./Java8BaseListener.java
/Users/parrt/antlr/code/grammars-v4/java8/./Java8Lexer.java
/Users/parrt/antlr/code/grammars-v4/java8/./Java8Listener.java
/Users/parrt/antlr/code/grammars-v4/java8/./Java8Parser.java
/Users/parrt/antlr/code/grammars-v4/java8/./Test.java
Total lexer+parser time 30844ms.
 */
grammar OptJava8;

/*
 * Productions from §3 (Lexical Structure)
 */

literal
	:	IntegerLiteral
	|	FloatingPointLiteral
	|	BooleanLiteral
	|	CharacterLiteral
	|	StringLiteral
	|	NullLiteral
	;

/*
 * Productions from §4 (Types, Values, and Variables)
 */

type
	:	primitiveType
	|	referenceType
	;

kleene_star__annotation
    :   annotation*
    ;

primitiveType
	:	kleene_star__annotation (numericType | 'boolean')
	;

numericType
	:	integralType
	|	floatingPointType
	;

integralType
	:	'byte'
	|	'short'
	|	'int'
	|	'long'
	|	'char'
	;

floatingPointType
	:	'float'
	|	'double'
	;

referenceType
	:	classOrInterfaceType
	|	typeVariable
	|	arrayType
	;

classOrInterfaceType_part
    :   classType_lf_classOrInterfaceType | interfaceType_lf_classOrInterfaceType
    ;

kleene_star__classOrInterfaceType_part
    :   classOrInterfaceType_part*
    ;

classOrInterfaceType
	:	(classType_lfno_classOrInterfaceType | interfaceType_lfno_classOrInterfaceType)
		kleene_star__classOrInterfaceType_part
	;

optional__typeArguments
    :   typeArguments?
    ;
classType
	:	kleene_star__annotation Identifier optional__typeArguments
	|	classOrInterfaceType '.' kleene_star__annotation Identifier optional__typeArguments
	;

classType_lf_classOrInterfaceType
	:	'.' kleene_star__annotation Identifier optional__typeArguments
	;

classType_lfno_classOrInterfaceType
	:	kleene_star__annotation Identifier optional__typeArguments
	;

interfaceType
	:	classType
	;

interfaceType_lf_classOrInterfaceType
	:	classType_lf_classOrInterfaceType
	;

interfaceType_lfno_classOrInterfaceType
	:	classType_lfno_classOrInterfaceType
	;

typeVariable
	:	kleene_star__annotation Identifier
	;

arrayType
	:	primitiveType kleene_plus__dims_part
	|	classOrInterfaceType kleene_plus__dims_part
	|	typeVariable kleene_plus__dims_part
	;

dims_part
    :   kleene_star__annotation '[' ']'
    ;

kleene_plus__dims_part
    :   dims_part+
    ;

kleene_star__dims_part
    :   dims_part*
    ;

typeParameter
	:	kleene_star__annotation Identifier optional__typeBound
	;

optional__typeBound
    :   typeBound?
    ;

typeBound
	:	'extends' typeVariable
	|	'extends' classOrInterfaceType kleene_star__additionalBound
	;

kleene_star__additionalBound
    :   additionalBound*
    ;

additionalBound
	:	'&' interfaceType
	;

typeArguments
	:	'<' typeArgumentList '>'
	;

typeArgumentList_part
    :   ',' typeArgument
    ;

kleene_star__typeArgumentList_part
    :   typeArgumentList_part*
    ;

typeArgumentList
	:	typeArgument kleene_star__typeArgumentList_part
	;

typeArgument
	:	referenceType
	|	wildcard
	;

wildcard
	:	kleene_star__annotation '?' optional__wildcardBounds
	;

optional__wildcardBounds
    :   wildcardBounds?
    ;

wildcardBounds
	:	'extends' referenceType
	|	'super' referenceType
	;

/*
 * Productions from §6 (Names)
 */

packageName
	:	Identifier
	|	packageName '.' Identifier
	;

typeName
	:	Identifier
	|	packageOrTypeName '.' Identifier
	;

packageOrTypeName
	:	Identifier
	|	packageOrTypeName '.' Identifier
	;

expressionName
	:	Identifier
	|	ambiguousName '.' Identifier
	;

methodName
	:	Identifier
	;

ambiguousName
	:	Identifier
	|	ambiguousName '.' Identifier
	;

/*
 * Productions from §7 (Packages)
 */

optional__packageDeclaration
    :   packageDeclaration?
    ;

kleene_star__importDeclaration
    :   importDeclaration*
    ;

kleene_star__typeDeclaration
    :   typeDeclaration*
    ;

compilationUnit
	:	optional__packageDeclaration kleene_star__importDeclaration kleene_star__typeDeclaration EOF
	;

packageDeclaration
	:	kleene_star__annotation 'package' packageName ';'
	;

importDeclaration
	:	singleTypeImportDeclaration
	|	typeImportOnDemandDeclaration
	|	singleStaticImportDeclaration
	|	staticImportOnDemandDeclaration
	;

singleTypeImportDeclaration
	:	'import' typeName ';'
	;

typeImportOnDemandDeclaration
	:	'import' packageOrTypeName '.' '*' ';'
	;

singleStaticImportDeclaration
	:	'import' 'static' typeName '.' Identifier ';'
	;

staticImportOnDemandDeclaration
	:	'import' 'static' typeName '.' '*' ';'
	;

typeDeclaration
	:	classDeclaration
	|	interfaceDeclaration
	|	';'
	;

/*
 * Productions from §8 (Classes)
 */

classDeclaration
	:	normalClassDeclaration
	|	enumDeclaration
	;

normalClassDeclaration
	:	kleene_star__classModifier 'class' Identifier optional__typeParameters
	    optional__superclass optional__superinterfaces classBody
	;

kleene_star__classModifier
    :   classModifier*
    ;

classModifier
	:	annotation
	|	'public'
	|	'protected'
	|	'private'
	|	'abstract'
	|	'static'
	|	'final'
	|	'strictfp'
	;

optional__typeParameters
    :   typeParameters?
    ;

typeParameters
	:	'<' typeParameterList '>'
	;

typeParameterList_part
    :   ',' typeParameter
    ;

kleene_star__typeParameterList_part
    :   typeParameterList_part*
    ;

typeParameterList
	:	typeParameter kleene_star__typeParameterList_part
	;

optional__superclass
    :   superclass?
    ;

superclass
	:	'extends' classType
	;

optional__superinterfaces
    :   superinterfaces?
    ;

superinterfaces
	:	'implements' interfaceTypeList
	;

interfaceTypeList_part
	:   ',' interfaceType
	;

kleene_star__interfaceTypeList_part
    :   interfaceTypeList_part*
    ;

interfaceTypeList
	:	interfaceType kleene_star__interfaceTypeList_part
	;

kleene_star__classBodyDeclaration
    :   classBodyDeclaration*
    ;

classBody
	:	'{' kleene_star__classBodyDeclaration '}'
	;

classBodyDeclaration
	:	classMemberDeclaration
	|	instanceInitializer
	|	staticInitializer
	|	constructorDeclaration
	;

classMemberDeclaration
	:	fieldDeclaration
	|	methodDeclaration
	|	classDeclaration
	|	interfaceDeclaration
	|	';'
	;

fieldDeclaration
	:	kleene_star__fieldModifier unannType variableDeclaratorList ';'
	;

kleene_star__fieldModifier
    :   fieldModifier*
    ;

fieldModifier
	:	annotation
	|	'public'
	|	'protected'
	|	'private'
	|	'static'
	|	'final'
	|	'transient'
	|	'volatile'
	;

variableDeclaratorList_part
    :   ',' variableDeclarator
    ;

kleene_star__variableDeclaratorList_part
    :   variableDeclaratorList_part*
    ;

variableDeclaratorList
	:	variableDeclarator kleene_star__variableDeclaratorList_part
	;

variableDeclarator_part
    :   '=' variableInitializer
    ;

optional__variableDeclarator_part
    :   variableDeclarator_part?
    ;

variableDeclarator
	:	variableDeclaratorId optional__variableDeclarator_part
	;

variableDeclaratorId
	:	Identifier kleene_star__dims_part
	;

variableInitializer
	:	expression
	|	arrayInitializer
	;

unannType
	:	unannPrimitiveType
	|	unannReferenceType
	;

unannPrimitiveType
	:	numericType
	|	'boolean'
	;

unannReferenceType
	:	unannClassOrInterfaceType
	|	unannTypeVariable
	|	unannArrayType
	;

unannClassOrInterfaceType_part
    :   unannClassType_lf_unannClassOrInterfaceType | unannInterfaceType_lf_unannClassOrInterfaceType
    ;

kleene_star__unannClassOrInterfaceType_part
    :   unannClassOrInterfaceType_part*
    ;

unannClassOrInterfaceType
	:	(unannClassType_lfno_unannClassOrInterfaceType | unannInterfaceType_lfno_unannClassOrInterfaceType)
		kleene_star__unannClassOrInterfaceType_part
	;

unannClassType
	:	Identifier optional__typeArguments
	|	unannClassOrInterfaceType '.' kleene_star__annotation Identifier optional__typeArguments
	;

unannClassType_lf_unannClassOrInterfaceType
	:	'.' kleene_star__annotation Identifier optional__typeArguments
	;

unannClassType_lfno_unannClassOrInterfaceType
	:	Identifier optional__typeArguments
	;

unannInterfaceType
	:	unannClassType
	;

unannInterfaceType_lf_unannClassOrInterfaceType
	:	unannClassType_lf_unannClassOrInterfaceType
	;

unannInterfaceType_lfno_unannClassOrInterfaceType
	:	unannClassType_lfno_unannClassOrInterfaceType
	;

unannTypeVariable
	:	Identifier
	;

unannArrayType
	:	unannPrimitiveType kleene_plus__dims_part
	|	unannClassOrInterfaceType kleene_plus__dims_part
	|	unannTypeVariable kleene_plus__dims_part
	;

methodDeclaration
	:	kleene_star__methodModifier methodHeader methodBody
	;


kleene_star__methodModifier
    :    methodModifier*
    ;

methodModifier
	:	annotation
	|	'public'
	|	'protected'
	|	'private'
	|	'abstract'
	|	'static'
	|	'final'
	|	'synchronized'
	|	'native'
	|	'strictfp'
	;

methodHeader
	:	result methodDeclarator optional__throws_
	|	typeParameters kleene_star__annotation result methodDeclarator optional__throws_
	;

result
	:	unannType
	|	'void'
	;

methodDeclarator
	:	Identifier '(' optional__formalParameterList ')' kleene_star__dims_part
	;

formalParameterList
	:	formalParameters ',' lastFormalParameter
	|	lastFormalParameter
	;

formalParameters_part
    :   ',' formalParameter
    ;

kleene_star__formalParameters_part
    :   formalParameters_part*
    ;

formalParameters
	:	(formalParameter | receiverParameter) kleene_star__formalParameters_part
	;

formalParameter
	:	kleene_star__variableModifier unannType variableDeclaratorId
	;

kleene_star__variableModifier
    :   variableModifier*
    ;

variableModifier
	:	annotation
	|	'final'
	;

lastFormalParameter
	:	kleene_star__variableModifier unannType kleene_star__annotation '...' variableDeclaratorId
	|	formalParameter
	;

identifier_and_dot
    :   Identifier '.'
    ;

optional__identifier_and_dot
    :   identifier_and_dot?
    ;

receiverParameter
	:	kleene_star__annotation unannType optional__identifier_and_dot 'this'
	;

optional__throws_
    :   throws_?
    ;

throws_
	:	'throws' exceptionTypeList
	;

exceptionTypeList_part
    :   ',' exceptionType
    ;

kleene_star__exceptionTypeList_part
    :   exceptionTypeList_part*
    ;

exceptionTypeList
	:	exceptionType kleene_star__exceptionTypeList_part
	;

exceptionType
	:	classType
	|	typeVariable
	;

methodBody
	:	block
	|	';'
	;

instanceInitializer
	:	block
	;

staticInitializer
	:	'static' block
	;

constructorDeclaration
	:	kleene_star__constructorModifier constructorDeclarator optional__throws_ constructorBody
	;

kleene_star__constructorModifier
    :   constructorModifier*
    ;

constructorModifier
	:	annotation
	|	'public'
	|	'protected'
	|	'private'
	;

constructorDeclarator
	:	optional__typeParameters simpleTypeName '(' optional__formalParameterList ')'
	;

simpleTypeName
	:	Identifier
	;

optional__explicitConstructorInvocation
    :   explicitConstructorInvocation?
    ;

constructorBody
	:	'{' optional__explicitConstructorInvocation kleene_star__blockStatements '}'
	;

explicitConstructorInvocation
	:	optional__typeArguments 'this' '(' optional__argumentList ')' ';'
	|	optional__typeArguments 'super' '(' optional__argumentList ')' ';'
	|	expressionName '.' optional__typeArguments 'super' '(' optional__argumentList ')' ';'
	|	primary '.' optional__typeArguments 'super' '(' optional__argumentList ')' ';'
	;

enumDeclaration
	:	kleene_star__classModifier 'enum' Identifier optional__superinterfaces enumBody
	;

optional__enumConstantList
    :   enumConstantList?
    ;

enumBody
	:	'{' optional__enumConstantList optional__comma optional__enumBodyDeclarations '}'
	;

optional__enumBodyDeclarations
    :   enumBodyDeclarations ?
    ;

enumConstantList_part
    :   ',' enumConstant
    ;

kleene_star__enumConstantList_part
    :   enumConstantList_part*
    ;

enumConstantList
	:	enumConstant kleene_star__enumConstantList_part
	;

paren_with_argument_list
    :   '(' optional__argumentList ')'
    ;

optional__paren_with_argument_list
    :   paren_with_argument_list?
    ;

enumConstant
	:	kleene_star__annotation Identifier optional__paren_with_argument_list optional__classBody
	;

enumBodyDeclarations
	:	';' kleene_star__classBodyDeclaration
	;

/*
 * Productions from §9 (Interfaces)
 */

interfaceDeclaration
	:	normalInterfaceDeclaration
	|	annotationTypeDeclaration
	;

normalInterfaceDeclaration
	:	kleene_star__interfaceModifier 'interface' Identifier optional__typeParameters optional__extendsInterfaces interfaceBody
	;

kleene_star__interfaceModifier
    :   interfaceModifier*
    ;

interfaceModifier
	:	annotation
	|	'public'
	|	'protected'
	|	'private'
	|	'abstract'
	|	'static'
	|	'strictfp'
	;

optional__extendsInterfaces
    :   extendsInterfaces?
    ;
extendsInterfaces
	:	'extends' interfaceTypeList
	;

interfaceBody
	:	'{' kleene_star__interfaceMemberDeclaration '}'
	;

kleene_star__interfaceMemberDeclaration
    :   interfaceMemberDeclaration*
    ;

interfaceMemberDeclaration
	:	constantDeclaration
	|	interfaceMethodDeclaration
	|	classDeclaration
	|	interfaceDeclaration
	|	';'
	;

constantDeclaration
	:	kleene_star__constantModifier unannType variableDeclaratorList ';'
	;

kleene_star__constantModifier
    :   constantModifier*
    ;

constantModifier
	:	annotation
	|	'public'
	|	'static'
	|	'final'
	;

interfaceMethodDeclaration
	:	kleene_star__interfaceMethodModifier methodHeader methodBody
	;

kleene_star__interfaceMethodModifier
    :   interfaceMethodModifier*
    ;

interfaceMethodModifier
	:	annotation
	|	'public'
	|	'abstract'
	|	'default'
	|	'static'
	|	'strictfp'
	;

annotationTypeDeclaration
	:	kleene_star__interfaceModifier '@' 'interface' Identifier annotationTypeBody
	;

annotationTypeBody
	:	'{' kleene_star__annotationTypeMemberDeclaration '}'
	;

kleene_star__annotationTypeMemberDeclaration
    :   annotationTypeMemberDeclaration*
    ;

annotationTypeMemberDeclaration
	:	annotationTypeElementDeclaration
	|	constantDeclaration
	|	classDeclaration
	|	interfaceDeclaration
	|	';'
	;

annotationTypeElementDeclaration
	:	kleene_star__annotationTypeElementModifier unannType Identifier '(' ')' kleene_star__dims_part optional__defaultValue ';'
	;

kleene_star__annotationTypeElementModifier
    :   annotationTypeElementModifier*
    ;

annotationTypeElementModifier
	:	annotation
	|	'public'
	|	'abstract'
	;

optional__defaultValue
    :   defaultValue?
    ;

defaultValue
	:	'default' elementValue
	;

annotation
	:	normalAnnotation
	|	markerAnnotation
	|	singleElementAnnotation
	;

normalAnnotation
	:	'@' typeName '(' optional__elementValuePairList ')'
	;

optional__elementValuePairList
    :   elementValuePairList?
    ;

elementValuePairList_part
    :   ',' elementValuePair
    ;

kleene_star__elementValuePairList_part
    :   elementValuePairList_part*
    ;

elementValuePairList
	:	elementValuePair kleene_star__elementValuePairList_part
	;

elementValuePair
	:	Identifier '=' elementValue
	;

elementValue
	:	conditionalExpression
	|	elementValueArrayInitializer
	|	annotation
	;

elementValueArrayInitializer
	:	'{' optional__elementValueList optional__comma '}'
	;

elementValueList_part
    :   ',' elementValue
    ;

kleene_star__elementValueList_part
    :   elementValueList_part*
    ;

optional__elementValueList
    :   elementValueList?
    ;

elementValueList
	:	elementValue kleene_star__elementValueList_part
	;

markerAnnotation
	:	'@' typeName
	;

singleElementAnnotation
	:	'@' typeName '(' elementValue ')'
	;

/*
 * Productions from §10 (Arrays)
 */

optional__comma
    : ',' ?
    ;

arrayInitializer
	:	'{' optional__variableInitializerList optional__comma '}'
	;

optional__variableInitializerList
    :   variableInitializerList ?
    ;

variableInitializerList_part
    :   ',' variableInitializer
    ;

kleene_star__variableInitializerList_part
    :   variableInitializerList_part*
    ;

variableInitializerList
	:	variableInitializer kleene_star__variableInitializerList_part
	;

/*
 * Productions from §14 (Blocks and Statements)
 */

block
	:	'{' kleene_star__blockStatements '}'
	;

kleene_star__blockStatements
    :   blockStatement*
    ;

kleene_plus__blockStatements
    :   blockStatement+
    ;

blockStatement
	:	localVariableDeclarationStatement
	|	classDeclaration
	|	statement
	;

localVariableDeclarationStatement
	:	localVariableDeclaration ';'
	;

localVariableDeclaration
	:	kleene_star__variableModifier unannType variableDeclaratorList
	;

statement
	:	statementWithoutTrailingSubstatement
	|	labeledStatement
	|	ifThenStatement
	|	ifThenElseStatement
	|	whileStatement
	|	forStatement
	;

statementNoShortIf
	:	statementWithoutTrailingSubstatement
	|	labeledStatementNoShortIf
	|	ifThenElseStatementNoShortIf
	|	whileStatementNoShortIf
	|	forStatementNoShortIf
	;

statementWithoutTrailingSubstatement
	:	block
	|	emptyStatement
	|	expressionStatement
	|	assertStatement
	|	switchStatement
	|	doStatement
	|	breakStatement
	|	continueStatement
	|	returnStatement
	|	synchronizedStatement
	|	throwStatement
	|	tryStatement
	;

emptyStatement
	:	';'
	;

labeledStatement
	:	Identifier ':' statement
	;

labeledStatementNoShortIf
	:	Identifier ':' statementNoShortIf
	;

expressionStatement
	:	statementExpression ';'
	;

statementExpression
	:	assignment
	|	preIncrementExpression
	|	preDecrementExpression
	|	postIncrementExpression
	|	postDecrementExpression
	|	methodInvocation
	|	classInstanceCreationExpression
	;

ifThenStatement
	:	'if' '(' expression ')' statement
	;

ifThenElseStatement
	:	'if' '(' expression ')' statementNoShortIf 'else' statement
	;

ifThenElseStatementNoShortIf
	:	'if' '(' expression ')' statementNoShortIf 'else' statementNoShortIf
	;

expression_in_assertion
    :   ':' expression
    ;

optional__expression_in_assertion
    :   expression_in_assertion?
    ;

assertStatement
	:	'assert' expression optional__expression_in_assertion ';'
	;

switchStatement
	:	'switch' '(' expression ')' switchBlock
	;

switchBlock
	:	'{' kleene_star__switchBlockStatementGroup kleene_star__switchLabel '}'
	;

kleene_star__switchBlockStatementGroup
    :   switchBlockStatementGroup*
    ;

kleene_star__switchLabel
    :   switchLabel*
    ;

switchBlockStatementGroup
	:	kleene_plus__switchLabe kleene_plus__blockStatements
	;

kleene_plus__switchLabe
    :   switchLabel+
    ;

switchLabel
	:	'case' constantExpression ':'
	|	'case' enumConstantName ':'
	|	'default' ':'
	;

enumConstantName
	:	Identifier
	;

whileStatement
	:	'while' '(' expression ')' statement
	;

whileStatementNoShortIf
	:	'while' '(' expression ')' statementNoShortIf
	;

doStatement
	:	'do' statement 'while' '(' expression ')' ';'
	;

forStatement
	:	basicForStatement
	|	enhancedForStatement
	;

forStatementNoShortIf
	:	basicForStatementNoShortIf
	|	enhancedForStatementNoShortIf
	;

basicForStatement
	:	'for' '(' optional__forInit ';' optional__expression ';' optional__forUpdate ')' statement
	;

basicForStatementNoShortIf
	:	'for' '(' optional__forInit ';' optional__expression ';' optional__forUpdate ')' statementNoShortIf
	;


optional__forInit
    :   forInit ?
    ;


forInit
	:	statementExpressionList
	|	localVariableDeclaration
	;

optional__forUpdate
    :   forUpdate?
    ;

forUpdate
	:	statementExpressionList
	;

statementExpressionList__part
    :   ',' statementExpression
    ;

kleene_star__statementExpressionList__part
    :   statementExpressionList__part*
    ;
statementExpressionList
	:	statementExpression kleene_star__statementExpressionList__part
	;

enhancedForStatement
	:	'for' '(' kleene_star__variableModifier unannType variableDeclaratorId ':' expression ')' statement
	;

enhancedForStatementNoShortIf
	:	'for' '(' kleene_star__variableModifier unannType variableDeclaratorId ':' expression ')' statementNoShortIf
	;

optional__Identifier
	:   Identifier?
	;

breakStatement
	:	'break' optional__Identifier ';'
	;

continueStatement
	:	'continue' optional__Identifier ';'
	;

optional__expression
    :   expression?
    ;

returnStatement
	:	'return' optional__expression ';'
	;

throwStatement
	:	'throw' expression ';'
	;

synchronizedStatement
	:	'synchronized' '(' expression ')' block
	;

tryStatement
	:	'try' block kleene_plus__catches
	|	'try' block kleene_star__catches finally_
	|	tryWithResourcesStatement
	;

kleene_star__catches
    :   catchClause*
    ;

kleene_plus__catches
    :   catchClause+
    ;

catchClause
	:	'catch' '(' catchFormalParameter ')' block
	;

catchFormalParameter
	:	kleene_star__variableModifier catchType variableDeclaratorId
	;


catchTypePart
    :   '|' classType
    ;

kleene_star__catchTypePart
    :   catchTypePart*
    ;

catchType
	:	unannClassType kleene_star__catchTypePart
	;

finally_
	:	'finally' block
	;

tryWithResourcesStatement
	:	'try' resourceSpecification block kleene_star__catches optional__finally_
	;

optional__finally_
    :   finally_?
    ;

optional__semicolon
    :   ';'?
    ;
resourceSpecification
	:	'(' resourceList optional__semicolon ')'
	;

resourceListPart
    :   ';' resource
    ;

kleene_star__resourceListPart
    :   resourceListPart*
    ;

resourceList
	:	resource kleene_star__resourceListPart
	;

resource
	:	kleene_star__variableModifier unannType variableDeclaratorId '=' expression
	;

/*
 * Productions from §15 (Expressions)
 */

kleene_star__primaryNoNewArray_lf_primary
    :   primaryNoNewArray_lf_primary*
    ;

primary
	:	(primaryNoNewArray_lfno_primary | arrayCreationExpression)
		kleene_star__primaryNoNewArray_lf_primary
	;

bracket_pair
    :   '[' ']'
    ;

kleene_star__bracket_pair
    :   bracket_pair*
    ;

primaryNoNewArray
	:	literal
	|	typeName kleene_star__bracket_pair '.' 'class'
	|	'void' '.' 'class'
	|	'this'
	|	typeName '.' 'this'
	|	'(' expression ')'
	|	classInstanceCreationExpression
	|	fieldAccess
	|	arrayAccess
	|	methodInvocation
	|	methodReference
	;

primaryNoNewArray_lf_arrayAccess
	:
	;

primaryNoNewArray_lfno_arrayAccess
	:	literal
	|	typeName kleene_star__bracket_pair '.' 'class'
	|	'void' '.' 'class'
	|	'this'
	|	typeName '.' 'this'
	|	'(' expression ')'
	|	classInstanceCreationExpression
	|	fieldAccess
	|	methodInvocation
	|	methodReference
	;

primaryNoNewArray_lf_primary
	:	classInstanceCreationExpression_lf_primary
	|	fieldAccess_lf_primary
	|	arrayAccess_lf_primary
	|	methodInvocation_lf_primary
	|	methodReference_lf_primary
	;

primaryNoNewArray_lf_primary_lf_arrayAccess_lf_primary
	:
	;

primaryNoNewArray_lf_primary_lfno_arrayAccess_lf_primary
	:	classInstanceCreationExpression_lf_primary
	|	fieldAccess_lf_primary
	|	methodInvocation_lf_primary
	|	methodReference_lf_primary
	;

primaryNoNewArray_lfno_primary
	:	literal
	|	typeName kleene_star__bracket_pair '.' 'class'
	|	unannPrimitiveType kleene_star__bracket_pair '.' 'class'
	|	'void' '.' 'class'
	|	'this'
	|	typeName '.' 'this'
	|	'(' expression ')'
	|	classInstanceCreationExpression_lfno_primary
	|	fieldAccess_lfno_primary
	|	arrayAccess_lfno_primary
	|	methodInvocation_lfno_primary
	|	methodReference_lfno_primary
	;

primaryNoNewArray_lfno_primary_lf_arrayAccess_lfno_primary
	:
	;

primaryNoNewArray_lfno_primary_lfno_arrayAccess_lfno_primary
	:	literal
	|	typeName kleene_star__bracket_pair '.' 'class'
	|	unannPrimitiveType kleene_star__bracket_pair '.' 'class'
	|	'void' '.' 'class'
	|	'this'
	|	typeName '.' 'this'
	|	'(' expression ')'
	|	classInstanceCreationExpression_lfno_primary
	|	fieldAccess_lfno_primary
	|	methodInvocation_lfno_primary
	|	methodReference_lfno_primary
	;

classInstanceCreationExpression
	:	'new' optional__typeArguments kleene_star__annotation Identifier kleene_star__annotation_and_identifier optional__typeArgumentsOrDiamond '(' optional__argumentList ')' optional__classBody
	|	expressionName '.' 'new' optional__typeArguments kleene_star__annotation Identifier optional__typeArgumentsOrDiamond '(' optional__argumentList ')' optional__classBody
	|	primary '.' 'new' optional__typeArguments kleene_star__annotation Identifier optional__typeArgumentsOrDiamond '(' optional__argumentList ')' optional__classBody
	;

classInstanceCreationExpression_lf_primary
	:	'.' 'new' optional__typeArguments kleene_star__annotation Identifier optional__typeArgumentsOrDiamond '(' optional__argumentList ')' optional__classBody
	;

classInstanceCreationExpression_lfno_primary
	:	'new' optional__typeArguments kleene_star__annotation Identifier kleene_star__annotation_and_identifier optional__typeArgumentsOrDiamond '(' optional__argumentList ')' optional__classBody
	|	expressionName '.' 'new' optional__typeArguments kleene_star__annotation Identifier optional__typeArgumentsOrDiamond '(' optional__argumentList ')' optional__classBody
	;

annotation_and_identifier
    :   '.' kleene_star__annotation Identifier
    ;

kleene_star__annotation_and_identifier
    :   annotation_and_identifier*
    ;

optional__classBody
    :   classBody?
    ;

optional__typeArgumentsOrDiamond
    :   typeArgumentsOrDiamond?
    ;

typeArgumentsOrDiamond
	:	typeArguments
	|	'<' '>'
	;

fieldAccess
	:	primary '.' Identifier
	|	'super' '.' Identifier
	|	typeName '.' 'super' '.' Identifier
	;

fieldAccess_lf_primary
	:	'.' Identifier
	;

fieldAccess_lfno_primary
	:	'super' '.' Identifier
	|	typeName '.' 'super' '.' Identifier
	;

arrayAccess_part
    :   primaryNoNewArray_lf_arrayAccess '[' expression ']'
    ;

kleene_star__arrayAccess_part
    :   arrayAccess_part*
    ;

arrayAccess
	:	(expressionName '[' expression ']' | primaryNoNewArray_lfno_arrayAccess '[' expression ']')
		kleene_star__arrayAccess_part
	;

arrayAccess_lf_primary_part
    :   primaryNoNewArray_lf_primary_lf_arrayAccess_lf_primary '[' expression ']'
    ;

kleene_star__arrayAccess_lf_primary_part
    :   arrayAccess_lf_primary_part*
    ;

arrayAccess_lf_primary
	:	(primaryNoNewArray_lf_primary_lfno_arrayAccess_lf_primary '[' expression ']')
		kleene_star__arrayAccess_lf_primary_part
	;

arrayAccess_lfno_primary_part
    :   primaryNoNewArray_lfno_primary_lf_arrayAccess_lfno_primary '[' expression ']'
    ;

kleene_star__arrayAccess_lfno_primary_part
    :   arrayAccess_lfno_primary_part*
    ;

arrayAccess_lfno_primary
	:	(expressionName '[' expression ']' | primaryNoNewArray_lfno_primary_lfno_arrayAccess_lfno_primary '[' expression ']' )
		kleene_star__arrayAccess_lfno_primary_part
	;

methodInvocation
	:	methodName '(' optional__argumentList ')'
	|	typeName '.' optional__typeArguments Identifier '(' optional__argumentList ')'
	|	expressionName '.' optional__typeArguments Identifier '(' optional__argumentList ')'
	|	primary '.' optional__typeArguments Identifier '(' optional__argumentList ')'
	|	'super' '.' optional__typeArguments Identifier '(' optional__argumentList ')'
	|	typeName '.' 'super' '.' optional__typeArguments Identifier '(' optional__argumentList ')'
	;

methodInvocation_lf_primary
	:	'.' optional__typeArguments Identifier '(' optional__argumentList ')'
	;

methodInvocation_lfno_primary
	:	methodName '(' optional__argumentList ')'
	|	typeName '.' optional__typeArguments Identifier '(' optional__argumentList ')'
	|	expressionName '.' optional__typeArguments Identifier '(' optional__argumentList ')'
	|	'super' '.' optional__typeArguments Identifier '(' optional__argumentList ')'
	|	typeName '.' 'super' '.' optional__typeArguments Identifier '(' optional__argumentList ')'
	;

optional__argumentList
    :   argumentList?
    ;

argumentList_part
    :   ',' expression
    ;

kleene_star__argumentList_part
    :   argumentList_part*
    ;

argumentList
	:	expression kleene_star__argumentList_part
	;

methodReference
	:	expressionName '::' optional__typeArguments Identifier
	|	referenceType '::' optional__typeArguments Identifier
	|	primary '::' optional__typeArguments Identifier
	|	'super' '::' optional__typeArguments Identifier
	|	typeName '.' 'super' '::' optional__typeArguments Identifier
	|	classType '::' optional__typeArguments 'new'
	|	arrayType '::' 'new'
	;

methodReference_lf_primary
	:	'::' optional__typeArguments Identifier
	;

methodReference_lfno_primary
	:	expressionName '::' optional__typeArguments Identifier
	|	referenceType '::' optional__typeArguments Identifier
	|	'super' '::' optional__typeArguments Identifier
	|	typeName '.' 'super' '::' optional__typeArguments Identifier
	|	classType '::' optional__typeArguments 'new'
	|	arrayType '::' 'new'
	;

arrayCreationExpression
	:	'new' primitiveType kleene_plus__dimExpr kleene_star__dims_part
	|	'new' classOrInterfaceType kleene_plus__dimExpr kleene_star__dims_part
	|	'new' primitiveType kleene_plus__dims_part arrayInitializer
	|	'new' classOrInterfaceType kleene_plus__dims_part arrayInitializer
	;

//dimExprs
kleene_plus__dimExpr
	:	dimExpr+
	;

dimExpr
	:	kleene_star__annotation '[' expression ']'
	;

constantExpression
	:	expression
	;

expression
	:	lambdaExpression
	|	assignmentExpression
	;

lambdaExpression
	:	lambdaParameters '->' lambdaBody
	;

lambdaParameters
	:	Identifier
	|	'(' optional__formalParameterList ')'
	|	'(' inferredFormalParameterList ')'
	;

optional__formalParameterList
    :   formalParameterList ?
    ;

inferredFormalParameterList_part
    :   ',' Identifier
    ;

kleene_star__inferredFormalParameterList_part
    :   inferredFormalParameterList_part*
    ;

inferredFormalParameterList
	:	Identifier kleene_star__inferredFormalParameterList_part
	;

lambdaBody
	:	expression
	|	block
	;

assignmentExpression
	:	conditionalExpression
	|	assignment
	;

assignment
	:	leftHandSide assignmentOperator expression
	;

leftHandSide
	:	expressionName
	|	fieldAccess
	|	arrayAccess
	;

assignmentOperator
	:	'='
	|	'*='
	|	'/='
	|	'%='
	|	'+='
	|	'-='
	|	'<<='
	|	'>>='
	|	'>>>='
	|	'&='
	|	'^='
	|	'|='
	;

conditionalExpressionPart
    :   '?' expression ':' conditionalExpression
    ;

optional__conditionalExpressionPart
    :   conditionalExpressionPart?
    ;

conditionalExpression
	:	conditionalOrExpression optional__conditionalExpressionPart
	;

conditionalOrExpression
	:	conditionalAndExpression
	|	conditionalOrExpression '||' conditionalAndExpression
	;

conditionalAndExpression
	:	inclusiveOrExpression
	|	conditionalAndExpression '&&' inclusiveOrExpression
	;

inclusiveOrExpression
	:	exclusiveOrExpression
	|	inclusiveOrExpression '|' exclusiveOrExpression
	;

exclusiveOrExpression
	:	andExpression
	|	exclusiveOrExpression '^' andExpression
	;

andExpression
	:	equalityExpression
	|	andExpression '&' equalityExpression
	;

equalityExpression
	:	relationalExpression
	|	equalityExpression ('==' | '!=') relationalExpression
	;

relationalExpression
	:	shiftExpression
	|	relationalExpression
	    ('<' | '>' | '<=' | '>=')
	    shiftExpression
	|	relationalExpression 'instanceof' referenceType
	;

shiftExpression
	:	additiveExpression
	|	shiftExpression '<' '<' additiveExpression
	|	shiftExpression '>' '>' additiveExpression
	|	shiftExpression '>' '>' '>' additiveExpression
	;

additiveExpression
	:	multiplicativeExpression
	|	additiveExpression ('+' | '-') multiplicativeExpression
	;

multiplicativeExpression
	:	unaryExpression
	|	multiplicativeExpression ('*' | '/' | '%') unaryExpression
	;

unaryExpression
	:	preIncrementExpression
	|	preDecrementExpression
	|	'+' unaryExpression
	|	'-' unaryExpression
	|	unaryExpressionNotPlusMinus
	;

preIncrementExpression
	:	'++' unaryExpression
	;

preDecrementExpression
	:	'--' unaryExpression
	;

unaryExpressionNotPlusMinus
	:	postfixExpression
	|	'~' unaryExpression
	|	'!' unaryExpression
	|	castExpression
	;

postfixExpression
	:	(primary | expressionName)
		kleene_star__plusplus_or_minusminus
	;

kleene_star__plusplus_or_minusminus
    :   plus_plus_or_minus_minus*
    ;

plus_plus_or_minus_minus
    :   '++' | '--'
    ;

postIncrementExpression
	:	postfixExpression '++'
	;


postDecrementExpression
	:	postfixExpression '--'
	;

castExpression
	:	'(' primitiveType ')' unaryExpression
	|	'(' referenceType kleene_star__additionalBound ')' unaryExpressionNotPlusMinus
	|	'(' referenceType kleene_star__additionalBound ')' lambdaExpression
	;

// LEXER

// §3.9 Keywords

ABSTRACT : 'abstract';
ASSERT : 'assert';
BOOLEAN : 'boolean';
BREAK : 'break';
BYTE : 'byte';
CASE : 'case';
CATCH : 'catch';
CHAR : 'char';
CLASS : 'class';
CONST : 'const';
CONTINUE : 'continue';
DEFAULT : 'default';
DO : 'do';
DOUBLE : 'double';
ELSE : 'else';
ENUM : 'enum';
EXTENDS : 'extends';
FINAL : 'final';
FINALLY : 'finally';
FLOAT : 'float';
FOR : 'for';
IF : 'if';
GOTO : 'goto';
IMPLEMENTS : 'implements';
IMPORT : 'import';
INSTANCEOF : 'instanceof';
INT : 'int';
INTERFACE : 'interface';
LONG : 'long';
NATIVE : 'native';
NEW : 'new';
PACKAGE : 'package';
PRIVATE : 'private';
PROTECTED : 'protected';
PUBLIC : 'public';
RETURN : 'return';
SHORT : 'short';
STATIC : 'static';
STRICTFP : 'strictfp';
SUPER : 'super';
SWITCH : 'switch';
SYNCHRONIZED : 'synchronized';
THIS : 'this';
THROW : 'throw';
THROWS : 'throws';
TRANSIENT : 'transient';
TRY : 'try';
VOID : 'void';
VOLATILE : 'volatile';
WHILE : 'while';

// §3.10.1 Integer Literals

IntegerLiteral
	:	DecimalIntegerLiteral
	|	HexIntegerLiteral
	|	OctalIntegerLiteral
	|	BinaryIntegerLiteral
	;

fragment
DecimalIntegerLiteral
	:	DecimalNumeral IntegerTypeSuffix?
	;

fragment
HexIntegerLiteral
	:	HexNumeral IntegerTypeSuffix?
	;

fragment
OctalIntegerLiteral
	:	OctalNumeral IntegerTypeSuffix?
	;

fragment
BinaryIntegerLiteral
	:	BinaryNumeral IntegerTypeSuffix?
	;

fragment
IntegerTypeSuffix
	:	[lL]
	;

fragment
DecimalNumeral
	:	'0'
	|	NonZeroDigit (Digits? | Underscores Digits)
	;

fragment
Digits
	:	Digit (DigitsAndUnderscores? Digit)?
	;

fragment
Digit
	:	'0'
	|	NonZeroDigit
	;

fragment
NonZeroDigit
	:	[1-9]
	;

fragment
DigitsAndUnderscores
	:	DigitOrUnderscore+
	;

fragment
DigitOrUnderscore
	:	Digit
	|	'_'
	;

fragment
Underscores
	:	'_'+
	;

fragment
HexNumeral
	:	'0' [xX] HexDigits
	;

fragment
HexDigits
	:	HexDigit (HexDigitsAndUnderscores? HexDigit)?
	;

fragment
HexDigit
	:	[0-9a-fA-F]
	;

fragment
HexDigitsAndUnderscores
	:	HexDigitOrUnderscore+
	;

fragment
HexDigitOrUnderscore
	:	HexDigit
	|	'_'
	;

fragment
OctalNumeral
	:	'0' Underscores? OctalDigits
	;

fragment
OctalDigits
	:	OctalDigit (OctalDigitsAndUnderscores? OctalDigit)?
	;

fragment
OctalDigit
	:	[0-7]
	;

fragment
OctalDigitsAndUnderscores
	:	OctalDigitOrUnderscore+
	;

fragment
OctalDigitOrUnderscore
	:	OctalDigit
	|	'_'
	;

fragment
BinaryNumeral
	:	'0' [bB] BinaryDigits
	;

fragment
BinaryDigits
	:	BinaryDigit (BinaryDigitsAndUnderscores? BinaryDigit)?
	;

fragment
BinaryDigit
	:	[01]
	;

fragment
BinaryDigitsAndUnderscores
	:	BinaryDigitOrUnderscore+
	;

fragment
BinaryDigitOrUnderscore
	:	BinaryDigit
	|	'_'
	;

// §3.10.2 Floating-Point Literals

FloatingPointLiteral
	:	DecimalFloatingPointLiteral
	|	HexadecimalFloatingPointLiteral
	;

fragment
DecimalFloatingPointLiteral
	:	Digits '.' Digits? ExponentPart? FloatTypeSuffix?
	|	'.' Digits ExponentPart? FloatTypeSuffix?
	|	Digits ExponentPart FloatTypeSuffix?
	|	Digits FloatTypeSuffix
	;

fragment
ExponentPart
	:	ExponentIndicator SignedInteger
	;

fragment
ExponentIndicator
	:	[eE]
	;

fragment
SignedInteger
	:	Sign? Digits
	;

fragment
Sign
	:	[+-]
	;

fragment
FloatTypeSuffix
	:	[fFdD]
	;

fragment
HexadecimalFloatingPointLiteral
	:	HexSignificand BinaryExponent FloatTypeSuffix?
	;

fragment
HexSignificand
	:	HexNumeral '.'?
	|	'0' [xX] HexDigits? '.' HexDigits
	;

fragment
BinaryExponent
	:	BinaryExponentIndicator SignedInteger
	;

fragment
BinaryExponentIndicator
	:	[pP]
	;

// §3.10.3 Boolean Literals

BooleanLiteral
	:	'true'
	|	'false'
	;

// §3.10.4 Character Literals

CharacterLiteral
	:	'\'' SingleCharacter '\''
	|	'\'' EscapeSequence '\''
	;

fragment
SingleCharacter
	:	~['\\]
	;

// §3.10.5 String Literals

StringLiteral
	:	'"' StringCharacters? '"'
	;

fragment
StringCharacters
	:	StringCharacter+
	;

fragment
StringCharacter
	:	~["\\]
	|	EscapeSequence
	;

// §3.10.6 Escape Sequences for Character and String Literals

fragment
EscapeSequence
	:	'\\' [btnfr"'\\]
	|	OctalEscape
    |   UnicodeEscape // This is not in the spec but prevents having to preprocess the input
	;

fragment
OctalEscape
	:	'\\' OctalDigit
	|	'\\' OctalDigit OctalDigit
	|	'\\' ZeroToThree OctalDigit OctalDigit
	;

fragment
ZeroToThree
	:	[0-3]
	;

// This is not in the spec but prevents having to preprocess the input
fragment
UnicodeEscape
    :   '\\' 'u' HexDigit HexDigit HexDigit HexDigit
    ;

// §3.10.7 The Null Literal

NullLiteral
	:	'null'
	;

// §3.11 Separators

LPAREN : '(';
RPAREN : ')';
LBRACE : '{';
RBRACE : '}';
LBRACK : '[';
RBRACK : ']';
SEMI : ';';
COMMA : ',';
DOT : '.';

// §3.12 Operators

ASSIGN : '=';
GT : '>';
LT : '<';
BANG : '!';
TILDE : '~';
QUESTION : '?';
COLON : ':';
EQUAL : '==';
LE : '<=';
GE : '>=';
NOTEQUAL : '!=';
AND : '&&';
OR : '||';
INC : '++';
DEC : '--';
ADD : '+';
SUB : '-';
MUL : '*';
DIV : '/';
BITAND : '&';
BITOR : '|';
CARET : '^';
MOD : '%';
ARROW : '->';
COLONCOLON : '::';

ADD_ASSIGN : '+=';
SUB_ASSIGN : '-=';
MUL_ASSIGN : '*=';
DIV_ASSIGN : '/=';
AND_ASSIGN : '&=';
OR_ASSIGN : '|=';
XOR_ASSIGN : '^=';
MOD_ASSIGN : '%=';
LSHIFT_ASSIGN : '<<=';
RSHIFT_ASSIGN : '>>=';
URSHIFT_ASSIGN : '>>>=';

// §3.8 Identifiers (must appear after all keywords in the grammar)

Identifier
	:	JavaLetter JavaLetterOrDigit*
	;

fragment
JavaLetter
	:	[a-zA-Z$_] // these are the "java letters" below 0x7F
	|	// covers all characters above 0x7F which are not a surrogate
		~[\u0000-\u007F\uD800-\uDBFF]
		{Character.isJavaIdentifierStart(_input.LA(-1))}?
	|	// covers UTF-16 surrogate pairs encodings for U+10000 to U+10FFFF
		[\uD800-\uDBFF] [\uDC00-\uDFFF]
		{Character.isJavaIdentifierStart(Character.toCodePoint((char)_input.LA(-2), (char)_input.LA(-1)))}?
	;

fragment
JavaLetterOrDigit
	:	[a-zA-Z0-9$_] // these are the "java letters or digits" below 0x7F
	|	// covers all characters above 0x7F which are not a surrogate
		~[\u0000-\u007F\uD800-\uDBFF]
		{Character.isJavaIdentifierPart(_input.LA(-1))}?
	|	// covers UTF-16 surrogate pairs encodings for U+10000 to U+10FFFF
		[\uD800-\uDBFF] [\uDC00-\uDFFF]
		{Character.isJavaIdentifierPart(Character.toCodePoint((char)_input.LA(-2), (char)_input.LA(-1)))}?
	;

//
// Additional symbols not defined in the lexical specification
//

AT : '@';
ELLIPSIS : '...';

//
// Whitespace and comments
//

WS  :  [ \t\r\n\u000C]+ -> skip
    ;

COMMENT
    :   '/*' .*? '*/' -> skip
    ;

LINE_COMMENT
    :   '//' ~[\r\n]* -> skip
    ;
