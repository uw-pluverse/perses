



import com.sun.source.tree.CompilationUnitTree;
import com.sun.source.util.JavacTask;
import java.io.File;
import java.io.IOException;
import java.net.URI;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;

public class StringFoldingTest {
    final JavaCompiler tool;
    final JavaSource source;

    public StringFoldingTest() {
        tool = ToolProvider.getSystemJavaCompiler();
        source = new JavaSource();
    }

    static class JavaSource extends SimpleJavaFileObject {

        final static String source =
                "class C {String X=\"F\" + \"O\" + \"L\" + \"D\" + \"E\" + \"D\";}";

        JavaSource() {
            super(URI.create("myfo:/C.java"), JavaFileObject.Kind.SOURCE);
        }

        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return source;
        }
    }

    public static void main(String... args) throws IOException {
        StringFoldingTest t = new StringFoldingTest();
        t.run(false);
        t.run(true);
    }

    void run(boolean disableStringFolding) throws IOException {
        List<String> argsList = new ArrayList<String>();
        if (disableStringFolding) {
            argsList.add("-XDallowStringFolding=false");
        }
        JavacTask ct = (JavacTask)tool.getTask(null, null, null,
                argsList,
                null,
                Arrays.asList(source));
        Iterable<? extends CompilationUnitTree> trees = ct.parse();
        String text = trees.toString();
        System.out.println(text);

        if (disableStringFolding) {
            if (text.contains("FOLDED")) {
                throw new AssertionError("Expected no string folding");
            }
            if (!text.contains("\"F\"")) {
                throw new AssertionError("Expected content not found");
            }
        } else {
            if (!text.contains("FOLDED")) {
                throw new AssertionError("Expected string folding");
            }
        }
    }
}
