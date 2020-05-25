package org.perses.fuzzer;

import com.google.common.collect.ImmutableList;
import com.google.common.truth.Truth;
import org.antlr.v4.runtime.tree.ParseTree;
import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;
import org.perses.antlr.ast.AbstractPersesRuleDefAst;
import org.perses.antlr.ast.PersesGrammar;
import org.perses.antlr.ast.RuleNameRegistry;
import org.perses.grammar.c.CParserFacade;
import org.perses.grammar.c.PnfCParserFacade;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import static com.google.common.truth.Truth.assertThat;

/** Test for testing the optimized C grammar. */
@RunWith(JUnit4.class)
public class FuzzerTest {

    private static final CParserFacade C_PARSER_FACADE = new CParserFacade();
    private static final PnfCParserFacade PNF_C_PARSER_FACADE = new PnfCParserFacade();

    private static void testOneCFile(File testFile) {
//        try {
//            final ArrayList<String> origTokens =
//                    TestUtility.extractTokens(C_PARSER_FACADE.parseWithOrigCParser(testFile).getTree());
//            {
//                final ParseTree treeByOpt = C_PARSER_FACADE.parseFile(testFile).getTree();
//                assertThat(origTokens)
//                        .containsExactlyElementsIn(TestUtility.extractTokens(treeByOpt))
//                        .inOrder();
//            }
//            {
//                final ParseTree treeByPnfc = PNF_C_PARSER_FACADE.parseFile(testFile).getTree();
//                assertThat(origTokens)
//                        .containsExactlyElementsIn(TestUtility.extractTokens(treeByPnfc))
//                        .inOrder();
//            }
//
//        } catch (Throwable e) {
//            e.printStackTrace();
//            Assert.fail();
//        }
    }

    @Test
    public void testAsmStmt_Issue16() throws IOException {
//        final File file = new File("test_data/c_programs/gcc_testsuite/06002.c");
//        C_PARSER_FACADE.parseFile(file);
//        PNF_C_PARSER_FACADE.parseFile(file);
    }

    }