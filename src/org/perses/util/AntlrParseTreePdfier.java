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

package org.perses.util;

import com.google.common.base.Preconditions;
import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import org.antlr.v4.runtime.ParserRuleContext;
import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.TerminalNode;
import org.perses.dot_graph.DotGraph;
import org.perses.dot_graph.TreeDotifier;
import org.perses.grammar.SingleParserFacadeFactory;
import org.perses.program.SourceFile;

public class AntlrParseTreePdfier {

  public static void pdfier(File sourceFile, File pdfFile) throws IOException {
    final SourceFile source = SourceFile.createFromPath(sourceFile);
    final ParseTreeWithParser treeWithParser =
        SingleParserFacadeFactory.SINGLETON
            .createParserFacade(source.getLanguageKind())
            .parseFile(sourceFile);
    TreeDotifier.dotifyAntlrParseTree(
        treeWithParser.tree(),
        pdfFile,
        new DotGraph.NodeLabelProvider<ParseTree>() {
          @Override
          protected String computeNodeLabel(ParseTree node) {
            if (node instanceof TerminalNode) {
              return node.getText();
            }
            ParserRuleContext rule = (ParserRuleContext) node;
            return treeWithParser.parser().getRuleNames()[rule.getRuleIndex()];
          }
        });
  }

  public static void main(String[] args) throws IOException {
    Preconditions.checkArgument(args.length == 2, Arrays.toString(args));
    final File sourceFile = new File(args[0]);
    final File pdfFile = new File(args[1]);
    System.out.println("The source file is " + sourceFile);
    pdfier(sourceFile, pdfFile);
    System.out.println("The pdf file is " + pdfFile);
  }
}
