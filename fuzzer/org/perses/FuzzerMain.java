package org.perses.fuzzer;

import com.beust.jcommander.JCommander;
import org.antlr.v4.runtime.tree.ParseTree;

import org.perses.tree.spar.SparTree;

import java.io.IOException;
import java.util.Arrays;

public class FuzzerMain {

    public static void main(String[] args) throws IOException,Exception {

        final CommandOptions cmd = new CommandOptions();
        final JCommander commander = cmd.createJCommander(FuzzerMain.class);
        commander.parse(args);
        if (cmd.help) {
            commander.usage();
            return;
        }
        Long randomSeed = 1L;
        if (cmd.randomMutationFlag.randomSeed != null) {
            randomSeed = cmd.randomMutationFlag.randomSeed;
        }

        if (cmd.randomMutationFlag.seedFile == null){
//            throw new Exception("no target file");
        }
        // sample test with file "test_data/c_programs/gcc_testsuite/06002.c"
//        final ParseTree treeByOpt = Fuzzer.generateParseTree(cmd.randomMutationFlag.seedFile);
//        System.out.println(Arrays.toString(args));
        final ParseTree treeByOpt = Fuzzer.generateParseTree("test_data/c_programs/gcc_testsuite/06002.c");
        final SparTree sparTree = Fuzzer.generateSparTree(treeByOpt);
        Fuzzer.treeMutation(sparTree, randomSeed);
    }
}
