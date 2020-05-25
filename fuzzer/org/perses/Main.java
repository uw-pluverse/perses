/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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

package org.perses.fuzzer;

import org.antlr.v4.runtime.tree.ParseTree;



import org.perses.grammar.c.CParserFacade;
import org.perses.grammar.c.PnfCParserFacade;


import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.util.concurrent.ExecutionException;



public class Main {

    public static void main(String[] args)
            throws IOException {

        CParserFacade CParser = new CParserFacade();
        final File testFile = new File("test_data/c_programs/gcc_testsuite/06002.c");
        ParseTree treeByOpt = CParser.parseFile(testFile).getTree();
        System.out.println(treeByOpt.toStringTree());
        System.out.println("finished");
    }
}