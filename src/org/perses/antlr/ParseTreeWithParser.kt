package org.perses.antlr

import org.antlr.v4.runtime.Parser
import org.antlr.v4.runtime.tree.ParseTree

data class ParseTreeWithParser(val tree: ParseTree, val parser: Parser)