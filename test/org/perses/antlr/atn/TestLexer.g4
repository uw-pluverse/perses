lexer grammar TestLexer;

SingleChar
    : 'A'
    ;

TwoChars
    : 'AB'
    ;

CharSet
    : [a-z]
    ;

NotADigit
    : ~[0-9]
    ;

KleeneStar
    : 'a' 'b'*
    ;

OptionalOnly
    : 'b' ?
    ;

OptionalChar
    : 'a' 'b'?
    ;

OptionalSequence
    : 'abcd'? 'e'
    ;

Alt
    : 'a' | 'A'
    ;

KleenePlusOnSingleChar
    : 'a' +
    ;

NegationAndPlus
    : ~[\n]+
    ;

IncludeDirective
    : '#' 'include' ~ [\n]+
    ;

fragment DIGIT
    : [0-9]
    ;

NaturalNumber
    : DIGIT+
    ;

Long
    : DIGIT+ 'L'
    ;

Wildcard
    : 'a' .
    ;

NonRegexToken
    : 'a'
    | '#' NonRegexToken '#'
    ;

GreedyWildcard
    : '|' .* '|'
    ;

NonGreedyWildcard
    : '|' .*? '|'
    ;
