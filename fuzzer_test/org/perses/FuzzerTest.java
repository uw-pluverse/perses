package org.perses.fuzzer;


import org.antlr.v4.runtime.tree.ParseTree;
import org.junit.Assert;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;

import org.perses.grammar.c.CParserFacade;
import org.perses.grammar.c.PnfCParserFacade;

import java.io.File;
import java.util.ArrayList;

import static com.google.common.truth.Truth.assertThat;

/** Test for testing fuzzer. */
@RunWith(JUnit4.class)
public class FuzzerTest {

    private static final CParserFacade C_PARSER_FACADE = new CParserFacade();

    private void testOneCFile(String pathname) {
        try{
            final File testFile = new File(pathname);
            final ArrayList<String> origTokens =
                    TestUtility.extractTokens(C_PARSER_FACADE.parseWithOrigCParser(testFile).getTree());

            final ParseTree treeByOpt = Fuzzer.generateTree(pathname);
            assertThat(origTokens)
                        .containsExactlyElementsIn(TestUtility.extractTokens(treeByOpt))
                        .inOrder();

        } catch(Throwable e) {
            e.printStackTrace();
            Assert.fail();
        }
    }

    }