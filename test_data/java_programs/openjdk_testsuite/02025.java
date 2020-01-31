


import java.io.InputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.URI;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import com.sun.tools.javac.file.JavacFileManager;
import com.sun.tools.javac.parser.Parser;
import com.sun.tools.javac.parser.ParserFactory;
import com.sun.tools.javac.tree.EndPosTable;
import com.sun.tools.javac.tree.JCTree;
import com.sun.tools.javac.tree.TreeScanner;
import com.sun.tools.javac.util.Context;
import com.sun.tools.javac.util.Log;
import com.sun.tools.javac.util.JCDiagnostic;
import com.sun.tools.javac.util.Options;

public class TestLog
{
    public static void main(String... args) throws IOException {
        test(false);
        test(true);
    }

    static void test(boolean genEndPos) throws IOException {
        Context context = new Context();

        Options options = Options.instance(context);
        options.put("diags", "%b:%s/%o/%e:%_%t%m|%p%m");

        Log log = Log.instance(context);
        log.multipleErrors = true;

        JavacFileManager.preRegister(context);
        ParserFactory pfac = ParserFactory.instance(context);

        final String text =
              "public class Foo {\n"
            + "  public static void main(String[] args) {\n"
            + "    if (args.length == 0)\n"
            + "      System.out.println(\"no args\");\n"
            + "    else\n"
            + "      System.out.println(args.length + \" args\");\n"
            + "  }\n"
            + "}\n";
        JavaFileObject fo = new StringJavaFileObject("Foo", text);
        log.useSource(fo);

        CharSequence cs = fo.getCharContent(true);
        Parser parser = pfac.newParser(cs, false, genEndPos, false);
        JCTree.JCCompilationUnit tree = parser.parseCompilationUnit();
        log.setEndPosTable(fo, tree.endPositions);

        TreeScanner ts = new LogTester(log, tree.endPositions);
        ts.scan(tree);

        check(log.nerrors, 4, "errors");
        check(log.nwarnings, 4, "warnings");
    }

    private static void check(int found, int expected, String name) {
        if (found == expected)
            System.err.println(found + " " + name + " found, as expected.");
        else {
            System.err.println("incorrect number of " + name + " found.");
            System.err.println("expected: " + expected);
            System.err.println("   found: " + found);
            throw new IllegalStateException("test failed");
        }
    }

    private static class LogTester extends TreeScanner {
        LogTester(Log log, EndPosTable endPosTable) {
            this.log = log;
            this.endPosTable = endPosTable;
        }

        public void visitIf(JCTree.JCIf tree) {
            JCDiagnostic.DiagnosticPosition nil = null;
            
            log.error("not.stmt");
            log.error(tree.pos, "not.stmt");
            log.error(tree.pos(), "not.stmt");
            log.error(nil, "not.stmt");

            log.warning("div.zero");
            log.warning(tree.pos, "div.zero");
            log.warning(tree.pos(), "div.zero");
            log.warning(nil, "div.zero");
        }

        private Log log;
        private EndPosTable endPosTable;
    }

    private static class StringJavaFileObject extends SimpleJavaFileObject {
        StringJavaFileObject(String name, String text) {
            super(URI.create(name), JavaFileObject.Kind.SOURCE);
            this.text = text;
        }
        public CharSequence getCharContent(boolean b) {
            return text;
        }
        public InputStream openInputStream() {
            throw new UnsupportedOperationException();
        }
        public OutputStream openOutputStream() {
            throw new UnsupportedOperationException();
        }
        private String text;
    }
}
