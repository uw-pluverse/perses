



import com.sun.source.util.JavacTask;
import com.sun.tools.javac.api.ClientCodeWrapper.Trusted;
import com.sun.tools.javac.api.DiagnosticFormatter;
import com.sun.tools.javac.api.JavacTaskImpl;
import com.sun.tools.javac.util.Assert;
import com.sun.tools.javac.util.JCDiagnostic;
import com.sun.tools.javac.util.Log;
import java.io.IOException;
import java.net.URI;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Locale;
import javax.tools.Diagnostic;
import javax.tools.DiagnosticListener;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;

public class T7116676 {

    public static void main(String[] args) throws Exception {
        T7116676 test = new T7116676();
        test.testThroughFormatterFormat();
    }

    static class JavaSource extends SimpleJavaFileObject {
        private String text = "package test;\n" +
                              "public class Test {\n" +
                              "   private void t(java.util.List<? extends String> l) {\n" +
                              "      t(java.util.Collections.singleton(l));\n" +
                              "}  }";

        public JavaSource() {
            super(URI.create("myfo:/Test.java"), JavaFileObject.Kind.SOURCE);
        }
        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return text;
        }
    }

    void assertEquals(String req, String found) {
        if (!found.equals(req)) {
            throw new AssertionError(String.format("Error. Found: \n\n%s ; Expected: \n\n%s", found, req));
        }
    }

    public void testThroughFormatterFormat() throws IOException {
        final JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        DiagnosticChecker dc = new DiagnosticChecker("compiler.err.prob.found.req");
        JavacTask ct = (JavacTask)tool.getTask(null, null, dc, null, null, Arrays.asList(new JavaSource()));
        ct.analyze();
        DiagnosticFormatter<JCDiagnostic> formatter =
                Log.instance(((JavacTaskImpl) ct).getContext()).getDiagnosticFormatter();
        String msg = formatter.formatMessage(dc.diag, Locale.getDefault());
        
        Assert.check(msg.indexOf("java.") == -1, msg);
    }

    @Trusted
    private static final class DiagnosticChecker implements DiagnosticListener<JavaFileObject> {

        String expectedKey;
        JCDiagnostic diag;

        DiagnosticChecker(String expectedKey) {
            this.expectedKey = expectedKey;
        }

        @Override
        public void report(Diagnostic<? extends JavaFileObject> diagnostic) {
            JCDiagnostic diag = (JCDiagnostic)diagnostic;
            if (diagnostic.getCode().equals(expectedKey)) {
                this.diag = diag;
            }
        }
    }
}
