#!/bin/sed -rf

# Read pattern
:collect
$!N
$!b collect

# Remove grammar lines
s/\<lexer\>\s+\<\grammar\>\s+\<\w+\>\s*\;//g
s/\<parser\>\s+\<\grammar\>\s+\<\w+\>\s*\;//g
