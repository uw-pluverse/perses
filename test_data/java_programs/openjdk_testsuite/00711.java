



import javax.tools.*;

import com.sun.tools.javac.api.ClientCodeWrapper.DiagnosticSourceUnwrapper;
import com.sun.tools.javac.util.JCDiagnostic;

import java.net.URI;
import java.util.Arrays;

import static javax.tools.StandardLocation.*;
import static javax.tools.JavaFileObject.Kind.*;


public class T7086261 {

    static class ErroneousSource extends SimpleJavaFileObject {
        public ErroneousSource() {
            super(URI.create("myfo:/Test.java"), JavaFileObject.Kind.SOURCE);
        }
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return "class Test { NonexistentClass c = null; }";
        }
    }

    static class DiagnosticChecker implements DiagnosticListener<javax.tools.JavaFileObject> {
        public void report(Diagnostic message) {
            if (!(message instanceof DiagnosticSourceUnwrapper)) {
                throw new AssertionError("Wrapped diagnostic expected!");
            }
            String actual = message.toString();
            JCDiagnostic jd = (JCDiagnostic)((DiagnosticSourceUnwrapper)message).d;
            String expected = jd.toString();
            if (!actual.equals(expected)) {
                throw new AssertionError("expected = " + expected + "\nfound = " + actual);
            }
        }
    };

    void test() throws Throwable {
        JavaCompiler javac = ToolProvider.getSystemJavaCompiler();
        JavaFileManager jfm = javac.getStandardFileManager(null, null, null);
        JavaCompiler.CompilationTask task =
                javac.getTask(null, jfm, new DiagnosticChecker(), null, null, Arrays.asList(new ErroneousSource()));
        task.call();
    }

    public static void main(String[] args) throws Throwable {
        new T7086261().test();
    }
}
