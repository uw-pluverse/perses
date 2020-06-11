package org.perses.fuzzer;

import org.antlr.v4.runtime.tree.ParseTree;
import org.perses.tree.spar.SparTree;

import java.io.IOException;

public class FuzzerMain {
    public static void main(String[] args) throws IOException {
        final ParseTree treeByOpt = Fuzzer.generateParseTree("test_data/c_programs/gcc_testsuite/06002.c");
        final SparTree sparTree = Fuzzer.generateSparTree(treeByOpt);
        Fuzzer.treeMutation(sparTree);
    }
}
