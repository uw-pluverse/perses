grammar options;

options {
    tokenVocab=GoLexer;
    superClass=GoParserBase;
}

start: EOF;