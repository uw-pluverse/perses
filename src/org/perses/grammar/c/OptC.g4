/*
 [The "BSD licence"]
 Copyright (c) 2013 Sam Harwell
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
 1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
 3. The name of the author may not be used to endorse or promote products
    derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/** C 2011 grammar built from the C11 Spec */
grammar OptC;

IncludeDirective: '#' 'include' ~ [\n]*;

primaryExpression
    :   Identifier
    |   Constant
    |   kleene_plus__StringLiteral
    |   '(' expression ')'
    |   genericSelection
    |   optional__extension '(' compoundStatement ')' // Blocks (GCC extension)
    |   '__builtin_va_arg' '(' unaryExpression ',' typeName ')'
    |   '__builtin_offsetof' '(' typeName ',' unaryExpression ')'
    ;

optional__extension
    :   '__extension__'?
    ;

kleene_plus__StringLiteral
    :   StringLiteral+
    ;

genericSelection
    :   '_Generic' '(' assignmentExpression ',' genericAssocList ')'
    ;

genericAssocList
    :   genericAssociation kleene_star__genericAssociationPart
    ;

genericAssocListPart
    :   ',' genericAssociation
    ;

kleene_star__genericAssociationPart
    :   genericAssocListPart*
    ;

genericAssociation
    :   typeName ':' assignmentExpression
    |   'default' ':' assignmentExpression
    ;

postfixExpression
    :   primaryExpression // Primary expression.
    |   postfixExpression '[' expression ']'
    |   postfixExpression '(' optional__argumentExpressionList ')'
    |   postfixExpression '.' Identifier
    |   postfixExpression '->' Identifier
    |   postfixExpression '++'
    |   postfixExpression '--'
    |   '(' typeName ')' '{' initializerList optional__comma '}'
    |   '__extension__' '(' typeName ')' '{' initializerList optional__comma '}'
    ;

optional__comma
    : ',' ?
    ;

optional__argumentExpressionList
    :   argumentExpressionList?
    ;

argumentExpressionListPart
    :   ',' assignmentExpression
    ;

kleene_star__argumentExpressionListPart
    :   argumentExpressionListPart*
    ;

argumentExpressionList
    :   assignmentExpression kleene_star__argumentExpressionListPart
    ;

unaryExpression
    :   postfixExpression
    |   '++' unaryExpression
    |   '--' unaryExpression
    |   unaryOperator castExpression
    |   'sizeof' unaryExpression
    |   'sizeof' '(' typeName ')'
    |   '_Alignof' '(' typeName ')'
    |   '&&' Identifier // GCC extension address of label
    ;

unaryOperator
    :   '&' | '*' | '+' | '-' | '~' | '!'
    ;

castExpression
    :   unaryExpression
    |   optional__extension '(' typeName ')' castExpression
    ;

binaryOperator
    :   '*' | '/' | '%'
    |   '+' | '-'
    |   '<<' | '>>'
    |   '<' | '>' | '<=' | '>='
    |   '==' | '!='
    |   '&'
    |   '^'
    |   '|'
    |   '&&'
    |   '||'
    ;

nonAssignmentBinaryExpressionPart
    :   binaryOperator castExpression
    ;

kleene_star__nonAssignmentBinaryExpressionPart
    :   nonAssignmentBinaryExpressionPart*
    ;

// binary expression for non-assignment
nonAssignmentBinaryExpression
    :   castExpression kleene_star__nonAssignmentBinaryExpressionPart
    ;

conditionalExpressionPart
    :   '?' expression ':' conditionalExpression
    ;

optional__conditionalExpressionPart
    :   conditionalExpressionPart?
    ;

conditionalExpression
    :   nonAssignmentBinaryExpression optional__conditionalExpressionPart
    ;

assignmentExpression
    :   conditionalExpression
    |   unaryExpression assignmentOperator assignmentExpression
    ;

assignmentOperator
    :   '=' | '*=' | '/=' | '%=' | '+=' | '-=' | '<<=' | '>>=' | '&=' | '^=' | '|='
    ;

expressionPart
    :   ',' assignmentExpression
    ;

kleene_star__expressionPart
    :   expressionPart*
    ;

optional__expression
    :   expression?
    ;

expression
    :   assignmentExpression kleene_star__expressionPart
    ;

constantExpression
    :   conditionalExpression
    ;

declaration
    :   kleene_plus__declarationSpecifiers optional__initDeclaratorList ';'
    |   staticAssertDeclaration
    |   asmStatement // https://en.cppreference.com/w/cpp/language/asm
    ;

kleene_star__declarationSpecifiers
    :   declarationSpecifier*
    ;

kleene_plus__declarationSpecifiers
    :   declarationSpecifier+
    ;

declarationSpecifier
    :   storageClassSpecifier
    |   typeSpecifier
    |   typeQualifier
    |   functionSpecifier
    |   alignmentSpecifier
    ;

initDeclaratorListPart
    :   ',' initDeclarator
    ;

kleene_star__initDeclaratorListPart
    :   initDeclaratorListPart*
    ;

optional__initDeclaratorList
    :   initDeclaratorList?
    ;

initDeclaratorList
    :   initDeclarator kleene_star__initDeclaratorListPart
    ;

initDeclaratorPart
    :   '=' initializer
    ;

optional__initDeclaratorPart
    :   initDeclaratorPart?
    ;

initDeclarator
    :   declarator optional__initDeclaratorPart
    ;

storageClassSpecifier
    :   'typedef'
    |   'extern'
    |   'static'
    |   '_Thread_local'
    |   'auto'
    |   'register'
    ;

typeSpecifier
    :   ('void'
    |   'char'
    |   'short'
    |   'int'
    |   'long'
    |   'float'
    |   'double'
    |   'signed'
    |   'unsigned'
    |   '_Bool'
    |   '_Complex'
    |   '__m128'
    |   '__m128d'
    |   '__m128i')
    |   '__extension__' '(' ('__m128' | '__m128d' | '__m128i') ')'
    |   atomicTypeSpecifier
    |   structOrUnionSpecifier
    |   enumSpecifier
    |   typedefName
    |   '__typeof__' '(' constantExpression ')' // GCC extension
    ;


optional__identifier
    :   Identifier?
    ;

structOrUnionSpecifier
    :   structOrUnion optional__identifier '{' kleene_plus__structDeclarationList '}'
    |   structOrUnion Identifier
    ;

structOrUnion
    :   'struct'
    |   'union'
    ;

kleene_plus__structDeclarationList
    :   structDeclaration+
    ;

structDeclaration
    :   kleene_plus__specifierQualifierList optional__structDeclaratorList ';'
    |   staticAssertDeclaration
    ;


specifierQualifierListPart
    :   typeSpecifier
    |   typeQualifier
    ;

kleene_plus__specifierQualifierList
    :   specifierQualifierListPart+
    ;

structDeclaratorListPart
    :   ',' structDeclarator
    ;

kleene_star__structDeclaratorList
    :   structDeclaratorListPart*
    ;

structDeclaratorList
    :   structDeclarator kleene_star__structDeclaratorList
    ;

optional__structDeclaratorList
    :   structDeclaratorList?
    ;

structDeclarator
    :   declarator
    |   optional__declarator ':' constantExpression
    ;

optional__declarator
    :   declarator?
    ;

enumSpecifier
    :   'enum' optional__identifier '{' enumeratorList optional__comma '}'
    |   'enum' Identifier
    ;

enumeratorListPart
    :   ',' enumerator
    ;

kleene_star__enumeratorListPart
    :   enumeratorListPart*
    ;

enumeratorList
    :   enumerator kleene_star__enumeratorListPart
    ;

enumeratorPart
    :   '=' constantExpression
    ;

optional__enumeratorPart
    :   enumeratorPart?
    ;

enumerator
    :   Identifier optional__enumeratorPart
    ;

atomicTypeSpecifier
    :   '_Atomic' '(' typeName ')'
    ;

typeQualifier
    :   'const'
    |   'restrict'
    |   'volatile'
    |   '_Atomic'
    ;

functionSpecifier
    :   ('inline'
    |   '_Noreturn'
    |   '__inline__' // GCC extension
    |   '__stdcall')
    |   gccAttributeSpecifier
    |   '__declspec' '(' Identifier ')'
    ;

alignmentSpecifier
    :   '_Alignas' '(' typeName ')'
    |   '_Alignas' '(' constantExpression ')'
    ;

kleene_star__gccDeclaratorExtension
    :   gccDeclaratorExtension*
    ;

declarator
    :   kleene_star__pointerPart directDeclarator kleene_star__gccDeclaratorExtension
    ;


optional__assignmentExpression
    :   assignmentExpression?
    ;

directDeclaratorPart
    :   '[' kleene_star__typeQualifierList optional__assignmentExpression ']'
    |   '[' 'static' kleene_star__typeQualifierList assignmentExpression ']'
    |   '[' kleene_plus__typeQualifierList 'static' assignmentExpression ']'
    |   '[' kleene_star__typeQualifierList '*' ']'
    |   '(' parameterTypeList ')'
    |   '(' optional__identifierList ')'
    ;

kleene_star__directDeclaratorPart
    :   directDeclaratorPart*
    ;

directDeclarator
    :   (Identifier |   '(' declarator ')')
        kleene_star__directDeclaratorPart
    ;

//directDeclarator
//    :   Identifier
//    |   '(' declarator ')'
//    |   directDeclarator '[' kleene_star__typeQualifierList optional__assignmentExpression ']'
//    |   directDeclarator '[' 'static' kleene_star__typeQualifierList assignmentExpression ']'
//    |   directDeclarator '[' kleene_plus__typeQualifierList 'static' assignmentExpression ']'
//    |   directDeclarator '[' kleene_star__typeQualifierList '*' ']'
//    |   directDeclarator '(' parameterTypeList ')'
//    |   directDeclarator '(' optional__identifierList ')'
//    ;

gccDeclaratorExtension
    :   asmKeyword '(' kleene_plus__StringLiteral ')'
    |   gccAttributeSpecifier
    ;

asmKeyword
    :   'asm' | '__asm__' | '__asm'
    ;

gccAttributeSpecifier
    :   '__attribute__' '(' '(' optional__gccAttributeList ')' ')'
    ;

gccAttributeListPart
    :   ',' gccAttribute
    ;

kleene_star__gccAttributeListPart
    :   gccAttributeListPart*
    ;

optional__gccAttributeList
    :   gccAttributeList?
    ;

gccAttributeList
    :   gccAttribute kleene_star__gccAttributeListPart
    ;

gccAttributePart
    :   '(' optional__argumentExpressionList ')'
    ;

optional__gccAttributePart
    :   gccAttributePart?
    ;

gccAttribute
    :   ~(',' | '(' | ')') // relaxed def for "identifier or reserved word"
        optional__gccAttributePart
    ;

nestedParenthesesBlockPart
    :   (   ~('(' | ')')
        |   '(' nestedParenthesesBlock ')'
        )
    ;

kleene_star__nestedParenthesesBlockPart
    :   nestedParenthesesBlockPart*
    ;

nestedParenthesesBlock
    :   kleene_star__nestedParenthesesBlockPart
    ;

//pointer
//    :   '*' kleene_star__typeQualifierList
//    |   '*' kleene_star__typeQualifierList pointer
//    |   '^' kleene_star__typeQualifierList // Blocks language extension
//    |   '^' kleene_star__typeQualifierList pointer // Blocks language extension
//    ;

pointerPart
    :   ('*' | '^') kleene_star__typeQualifierList
    ;

kleene_plus__pointerPart
    :   pointerPart+
    ;


kleene_star__pointerPart
    :   pointerPart*
    ;
//
//pointer
//    :   kleene_plus__pointerPart
//    ;

kleene_star__typeQualifierList
    :   typeQualifier*
    ;

kleene_plus__typeQualifierList
    :   typeQualifier+
    ;

parameterTypeListPart
    : ',' '...'
    ;

optional__parameterTypeListPart
    :   parameterTypeListPart?
    ;

optional__parameterTypeList
    :   parameterTypeList?
    ;

parameterTypeList
    :   parameterList optional__parameterTypeListPart
    ;

parameterListPart
    :   ',' parameterDeclaration
    ;

kleene_star__parameterListPart
    :   parameterListPart*
    ;

parameterList
    :   parameterDeclaration kleene_star__parameterListPart
    ;

parameterDeclaration
    :   kleene_plus__declarationSpecifiers (declarator | optional__abstractDeclarator)
    ;

identifierListPart
    :   ',' Identifier
    ;

kleene_star__identifierListPart
    :   identifierListPart*
    ;

identifierList
    :   Identifier kleene_star__identifierListPart
    ;

optional__identifierList
    :   identifierList?
    ;

typeName
    :   kleene_plus__specifierQualifierList optional__abstractDeclarator
    ;

optional__abstractDeclarator
    :   abstractDeclarator?
    ;

abstractDeclarator
    :   kleene_plus__pointerPart
    |   kleene_star__pointerPart directAbstractDeclarator optional__gccAttributeList
    ;

directAbstractDeclarator
    :   '(' abstractDeclarator ')' kleene_star__gccDeclaratorExtension
    |   '[' kleene_star__typeQualifierList optional__assignmentExpression ']'
    |   '[' 'static' kleene_star__typeQualifierList assignmentExpression ']'
    |   '[' kleene_plus__typeQualifierList 'static' assignmentExpression ']'
    |   '[' '*' ']'
    |   '(' optional__parameterTypeList ')' kleene_star__gccDeclaratorExtension
    |   directAbstractDeclarator '[' kleene_star__typeQualifierList optional__assignmentExpression ']'
    |   directAbstractDeclarator '[' 'static' kleene_star__typeQualifierList assignmentExpression ']'
    |   directAbstractDeclarator '[' kleene_plus__typeQualifierList 'static' assignmentExpression ']'
    |   directAbstractDeclarator '[' '*' ']'
    |   directAbstractDeclarator '(' optional__parameterTypeList ')' kleene_star__gccDeclaratorExtension
    ;

typedefName
    :   Identifier
    ;

initializer
    :   assignmentExpression
    |   '{' initializerList optional__comma '}'
    ;

initializerListPart
    :   ',' optional__designation initializer
    ;

kleene_star__initializerListPart
    :   initializerListPart*
    ;

initializerList
    :   optional__designation initializer kleene_star__initializerListPart
    ;

optional__designation
    :   designation?
    ;

designation
    :   kleene_plus__designatorList '='
    ;

kleene_plus__designatorList
    :   designator+
    ;

designator
    :   '[' constantExpression ']'
    |   '.' Identifier
    ;

staticAssertDeclaration
    :   '_Static_assert' '(' constantExpression ',' kleene_plus__StringLiteral ')' ';'
    ;

statementPartOne
    :   ',' nonAssignmentBinaryExpression
    ;

kleene_star__statementPartOne
    :   statementPartOne*
    ;

statementPartTwo
    :    nonAssignmentBinaryExpression kleene_star__statementPartOne
    ;

optional__statementPartTwo
    :   statementPartTwo?
    ;

statementPartThree
    :   ':' optional__statementPartTwo
    ;

kleene_star__statementPartThree
    :   statementPartThree*
    ;

statement
    :   labeledStatement
    |   compoundStatement
    |   expressionStatement
    |   selectionStatement
    |   iterationStatement
    |   jumpStatement
    |   asmStatement
    ;

// https://en.cppreference.com/w/cpp/language/asm
// GCC Assembler syntax: https://www.felixcloutier.com/documents/gcc-asm.html
asmStatement
    :   asmKeyword
        ('volatile' | '__volatile__')?
        '('
            optional__statementPartTwo
            kleene_star__statementPartThree
        ')' ';'
    ;

labeledStatement
    :   Identifier ':' statement
    |   'case' constantExpression ':' statement
    |   'default' ':' statement
    ;

compoundStatement
    :   '{' kleene_star__blockItem '}'
    ;

kleene_star__blockItem
    :   blockItem*
    ;

blockItem
    :   declaration
    |   statement
    ;

expressionStatement
    :   optional__expression ';'
    ;

selectionStatementPart
    :   'else' statement
    ;

optional__selectionStatementPart
    :   selectionStatementPart?
    ;
selectionStatement
    :   'if' '(' expression ')' statement optional__selectionStatementPart
    |   'switch' '(' expression ')' statement
    ;

iterationStatement
    :   'while' '(' expression ')' statement
    |   'do' statement 'while' '(' expression ')' ';'
    |   'for' '(' optional__expression ';' optional__expression ';' optional__expression ')' statement
    |   'for' '(' declaration optional__expression ';' optional__expression ')' statement
    ;

jumpStatement
    :   'goto' Identifier ';'
    |   'continue' ';'
    |   'break' ';'
    |   'return' optional__expression ';'
    |   'goto' unaryExpression ';' // GCC extension
    ;

compilationUnit
    :   optional__translationUnit EOF
    ;

optional__translationUnit
    :   translationUnit?
    ;


kleene_plus__externalDeclaration
    :   externalDeclaration+
    ;

translationUnit
    :   kleene_plus__externalDeclaration
    ;

externalDeclaration
    :   functionDefinition
    |   declaration
    |   IncludeDirective
    |   ';' // stray ;
    ;

functionDefinition
    :   kleene_star__declarationSpecifiers declarator kleene_star__declaration compoundStatement
    ;

kleene_star__declaration
    :   declaration*
    ;

Auto : 'auto';
Break : 'break';
Case : 'case';
Char : 'char';
Const : 'const';
Continue : 'continue';
Default : 'default';
Do : 'do';
Double : 'double';
Else : 'else';
Enum : 'enum';
Extern : 'extern';
Float : 'float';
For : 'for';
Goto : 'goto';
If : 'if';
Inline : 'inline';
Int : 'int';
Long : 'long';
Register : 'register';
Restrict : 'restrict';
Return : 'return';
Short : 'short';
Signed : 'signed';
Sizeof : 'sizeof';
Static : 'static';
Struct : 'struct';
Switch : 'switch';
Typedef : 'typedef';
Union : 'union';
Unsigned : 'unsigned';
Void : 'void';
Volatile : 'volatile';
While : 'while';

Alignas : '_Alignas';
Alignof : '_Alignof';
Atomic : '_Atomic';
Bool : '_Bool';
Complex : '_Complex';
Generic : '_Generic';
Imaginary : '_Imaginary';
Noreturn : '_Noreturn';
StaticAssert : '_Static_assert';
ThreadLocal : '_Thread_local';

LeftParen : '(';
RightParen : ')';
LeftBracket : '[';
RightBracket : ']';
LeftBrace : '{';
RightBrace : '}';

Less : '<';
LessEqual : '<=';
Greater : '>';
GreaterEqual : '>=';
LeftShift : '<<';
RightShift : '>>';

Plus : '+';
PlusPlus : '++';
Minus : '-';
MinusMinus : '--';
Star : '*';
Div : '/';
Mod : '%';

And : '&';
Or : '|';
AndAnd : '&&';
OrOr : '||';
Caret : '^';
Not : '!';
Tilde : '~';

Question : '?';
Colon : ':';
Semi : ';';
Comma : ',';

Assign : '=';
// '*=' | '/=' | '%=' | '+=' | '-=' | '<<=' | '>>=' | '&=' | '^=' | '|='
StarAssign : '*=';
DivAssign : '/=';
ModAssign : '%=';
PlusAssign : '+=';
MinusAssign : '-=';
LeftShiftAssign : '<<=';
RightShiftAssign : '>>=';
AndAssign : '&=';
XorAssign : '^=';
OrAssign : '|=';

Equal : '==';
NotEqual : '!=';

Arrow : '->';
Dot : '.';
Ellipsis : '...';

Identifier
    :   IdentifierNondigit
        (   IdentifierNondigit
        |   Digit
        )*
    ;

fragment
IdentifierNondigit
    :   Nondigit
    |   UniversalCharacterName
    //|   // other implementation-defined characters...
    ;

fragment
Nondigit
    :   [a-zA-Z_]
    ;

fragment
Digit
    :   [0-9]
    ;

fragment
UniversalCharacterName
    :   '\\u' HexQuad
    |   '\\U' HexQuad HexQuad
    ;

fragment
HexQuad
    :   HexadecimalDigit HexadecimalDigit HexadecimalDigit HexadecimalDigit
    ;

Constant
    :   IntegerConstant
    |   FloatingConstant
    //|   EnumerationConstant
    |   CharacterConstant
    ;

fragment
IntegerConstant
    :   DecimalConstant IntegerSuffix?
    |   OctalConstant IntegerSuffix?
    |   HexadecimalConstant IntegerSuffix?
    |	BinaryConstant
    ;

fragment
BinaryConstant
	:	'0' [bB] [0-1]+
	;

fragment
DecimalConstant
    :   NonzeroDigit Digit*
    ;

fragment
OctalConstant
    :   '0' OctalDigit*
    ;

fragment
HexadecimalConstant
    :   HexadecimalPrefix HexadecimalDigit+
    ;

fragment
HexadecimalPrefix
    :   '0' [xX]
    ;

fragment
NonzeroDigit
    :   [1-9]
    ;

fragment
OctalDigit
    :   [0-7]
    ;

fragment
HexadecimalDigit
    :   [0-9a-fA-F]
    ;

fragment
IntegerSuffix
    :   UnsignedSuffix LongSuffix?
    |   UnsignedSuffix LongLongSuffix
    |   LongSuffix UnsignedSuffix?
    |   LongLongSuffix UnsignedSuffix?
    ;

fragment
UnsignedSuffix
    :   [uU]
    ;

fragment
LongSuffix
    :   [lL]
    ;

fragment
LongLongSuffix
    :   'll' | 'LL'
    ;

fragment
FloatingConstant
    :   DecimalFloatingConstant
    |   HexadecimalFloatingConstant
    ;

fragment
DecimalFloatingConstant
    :   FractionalConstant ExponentPart? FloatingSuffix?
    |   DigitSequence ExponentPart FloatingSuffix?
    ;

fragment
HexadecimalFloatingConstant
    :   HexadecimalPrefix HexadecimalFractionalConstant BinaryExponentPart FloatingSuffix?
    |   HexadecimalPrefix HexadecimalDigitSequence BinaryExponentPart FloatingSuffix?
    ;

fragment
FractionalConstant
    :   DigitSequence? '.' DigitSequence
    |   DigitSequence '.'
    ;

fragment
ExponentPart
    :   'e' Sign? DigitSequence
    |   'E' Sign? DigitSequence
    ;

fragment
Sign
    :   '+' | '-'
    ;

fragment
DigitSequence
    :   Digit+
    ;

fragment
HexadecimalFractionalConstant
    :   HexadecimalDigitSequence? '.' HexadecimalDigitSequence
    |   HexadecimalDigitSequence '.'
    ;

fragment
BinaryExponentPart
    :   'p' Sign? DigitSequence
    |   'P' Sign? DigitSequence
    ;

fragment
HexadecimalDigitSequence
    :   HexadecimalDigit+
    ;

fragment
FloatingSuffix
    :   'f' | 'l' | 'F' | 'L'
    ;

fragment
CharacterConstant
    :   '\'' CCharSequence '\''
    |   'L\'' CCharSequence '\''
    |   'u\'' CCharSequence '\''
    |   'U\'' CCharSequence '\''
    ;

fragment
CCharSequence
    :   CChar+
    ;

fragment
CChar
    :   ~['\\\r\n]
    |   EscapeSequence
    ;

fragment
EscapeSequence
    :   SimpleEscapeSequence
    |   OctalEscapeSequence
    |   HexadecimalEscapeSequence
    |   UniversalCharacterName
    ;

fragment
SimpleEscapeSequence
    :   '\\' ['"?abfnrtv\\]
    ;

fragment
OctalEscapeSequence
    :   '\\' OctalDigit
    |   '\\' OctalDigit OctalDigit
    |   '\\' OctalDigit OctalDigit OctalDigit
    ;

fragment
HexadecimalEscapeSequence
    :   '\\x' HexadecimalDigit+
    ;

StringLiteral
    :   EncodingPrefix? '"' SCharSequence? '"'
    ;

fragment
EncodingPrefix
    :   'u8'
    |   'u'
    |   'U'
    |   'L'
    ;

fragment
SCharSequence
    :   SChar+
    ;

fragment
SChar
    :   ~["\\\r\n]
    |   EscapeSequence
    |   '\\\n'   // Added line
    |   '\\\r\n' // Added line
    ;

ComplexDefine
    :   '#' Whitespace? 'define'  ~[#]*
        -> skip
    ;
         
// ignore the following asm blocks:
/*
    asm
    {
        mfspr x, 286;
    }
 */
AsmBlock
    :   'asm' // ~['{']*
        '{' ~['}']* '}'
	-> skip
    ;
	
// ignore the lines generated by c preprocessor                                   
// sample line : '#line 1 "/home/dm/files/dk1.h" 1'                           
LineAfterPreprocessing
    :   '#line' Whitespace* ~[\r\n]*
        -> skip
    ;  

LineDirective
    :   '#' Whitespace? DecimalConstant Whitespace? StringLiteral ~[\r\n]*
        -> skip
    ;

PragmaDirective
    :   '#' Whitespace? 'pragma' Whitespace ~[\r\n]*
        -> skip
    ;

Whitespace
    :   [ \t]+
        -> skip
    ;

Newline
    :   (   '\r' '\n'?
        |   '\n'
        )
        -> skip
    ;

BlockComment
    :   '/*' .*? '*/'
        -> skip
    ;

LineComment
    :   '//' ~[\r\n]*
        -> skip
    ;
