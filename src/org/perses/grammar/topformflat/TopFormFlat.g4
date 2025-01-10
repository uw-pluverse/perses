/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
grammar TopFormFlat;

topFormFlat: (contentWrapper)+ EOF ;

contentWrapper: (comment | compoundStatement | content | stringLiteral) ;

compoundStatement: statements SEMICOLON* ;

statements: (CONTENT angleStatement)? (
    braceStatement |
    bracketStatement |
    parenStatement |
    angleStatement
)
;

braceStatement: openBrace contentWrapper* closeBrace ;
bracketStatement: angleStatement? openBracket contentWrapper* closeBracket ;
parenStatement: angleStatement? openParen contentWrapper* closeParen ;
angleStatement: openAngle contentWrapper* closeAngle ;

stringLiteral: STRING_LITERAL ;
content: CONTENT stringLiteral? SEMICOLON? ;
comment: COMMENT ;

// Rules
openBrace: OPEN_BRACE ;
closeBrace: CLOSE_BRACE ;
openBracket: OPEN_BRACKET ;
closeBracket: CLOSE_BRACKET ;
openParen: OPEN_PAREN ;
closeParen: CLOSE_PAREN ;
openAngle: OPEN_ANGLE ;
closeAngle: CLOSE_ANGLE ;

// Braces
OPEN_BRACE: '{' ;
CLOSE_BRACE: '}' ;
OPEN_BRACKET: '[' ;
CLOSE_BRACKET: ']' ;
OPEN_PAREN: '(' ;
CLOSE_PAREN: ')' ;
OPEN_ANGLE: '<' ;
CLOSE_ANGLE: '>' ;

// Skip these
WS: [ \t\r\n]+ -> skip ;
COMMENT: [ \t]* '//' ~[\r\n]* -> skip ;

// Main tokens
SEMICOLON: [ \t]* ';' ;
CONTENT: ~('{' | '}' | '[' | ']' | '<' | '>' | '(' | ')' | '"' | '\'' | ';'| '\n')+ ;
STRING_LITERAL: ('"' SCharSequence? '"') | ('\'' SCharSequence? '\'') ;
COMMA: ',' ;

// Characters within a string
fragment SCharSequence: SChar+ ;
fragment SChar:
      ~["\\\r\n]
    | EscapeSequence
    | '\\\n'
    | '\\\r\n'
    ;

fragment EscapeSequence
    : SimpleEscapeSequence
    | OctalEscapeSequence
    | HexadecimalEscapeSequence
    | UniversalCharacterName
    ;

fragment SimpleEscapeSequence: '\\' ['"?abfnrtv\\] ;
fragment OctalEscapeSequence
    : '\\' OctalDigit
    | '\\' OctalDigit OctalDigit
    | '\\' OctalDigit OctalDigit OctalDigit
    ;

fragment HexadecimalEscapeSequence: '\\x' HexadecimalDigit+ ;
fragment UniversalCharacterName: '\\u' HexQuad | '\\U' HexQuad HexQuad ;
fragment HexQuad: HexadecimalDigit HexadecimalDigit HexadecimalDigit HexadecimalDigit ;
fragment HexadecimalDigit: [0-9a-fA-F] ;
fragment OctalDigit: [0-7] ;
