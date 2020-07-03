/*
 * Copyright (C) 2018-2020 University of Waterloo.
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

import com.beust.jcommander.JCommander;
import org.antlr.v4.runtime.tree.ParseTree;

import org.perses.tree.spar.SparTree;

import java.io.IOException;
import java.util.Arrays;
import java.util.Random;

public class FuzzerMain {

  public static void main(String[] args) throws IOException {

    final CommandOptions cmd = new CommandOptions();
    final JCommander commander = cmd.createJCommander(FuzzerMain.class);
    commander.parse(args);
    if (cmd.help) {
      commander.usage();
      return;
    }

    // sample test with file "test_data/c_programs/gcc_testsuite/06002.c"
    //        final ParseTree treeByOpt = Fuzzer.generateParseTree(cmd.randomMutationFlag.seedFile);
    //        System.out.println(Arrays.toString(args));
    final ParseTree treeByOpt =
        Fuzzer.generateParseTree("test_data/c_programs/gcc_testsuite/06002.c");
    final SparTree sparTree = Fuzzer.generateSparTree(treeByOpt);
    Random rnd = new Random();
    rnd.setSeed(cmd.randomMutationFlag.randomSeed);
    Fuzzer.treeMutation(sparTree, rnd);
  }
}
