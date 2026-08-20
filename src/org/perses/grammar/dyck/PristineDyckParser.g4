parser grammar PristineDyckParser;

// A pure Dyck grammar: tokens nest by balanced delimiters only, with no notion of
// source lines -- the line-oblivious counterpart of LineAwareDyckParser. Both grammars
// draw their vocabulary from the shared DyckTokens lexer grammar, so they get identical
// token numbering -- which is what lets the two parsers reuse the same hand-written
// DyckLexer. PristineDyckParserFacadeTest guards that alignment from drifting.
options {
    tokenVocab = DyckTokens;
}

start
    : node* EOF
    ;

node
    : text
    | OPEN_BRACE node* CLOSE_BRACE
    | OPEN_PARENTHESIS node* CLOSE_PARENTHESIS
    | OPEN_BRACKET node* CLOSE_BRACKET
    ;

// FABRICATED_NEWLINE is absorbed into the text run rather than delimiting it, so a
// run of content tokens spanning several source lines collapses into one text node
// -- this is precisely how the grammar stays line-oblivious. The fabricated token
// carries a negative start/stop index, so SparTreeBuilder drops it from the tree
// (see AbstractParserFacade.isFabricatedToken), leaving only the OTHER leaves.
text
    : (OTHER | FABRICATED_NEWLINE)+
    ;
