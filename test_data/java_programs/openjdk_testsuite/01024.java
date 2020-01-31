



import java.io.*;
import java.net.URI;
import java.util.Arrays;
import javax.tools.Diagnostic;
import javax.tools.DiagnosticListener;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;

import com.sun.source.util.JavacTask;
import java.util.EnumSet;

public class TestCircularClassfile {

    enum ClassName {
        A("A"),
        B("B"),
        C("C"),
        OBJECT("Object");

        String name;

        ClassName(String name) {
            this.name = name;
        }
    }

    static class JavaSource extends SimpleJavaFileObject {

        final static String sourceStub = "class #C extends #S {}";

        String source;

        public JavaSource(ClassName clazz, ClassName sup) {
            super(URI.create("myfo:/Test.java"), JavaFileObject.Kind.SOURCE);
            source = sourceStub.replace("#C", clazz.name).replace("#S", sup.name);
        }

        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return source;
        }
    }

    public static void main(String... args) throws Exception {
        int count = 0;
        for (ClassName clazz : EnumSet.of(ClassName.A, ClassName.B, ClassName.C)) {
            for (ClassName sup : EnumSet.of(ClassName.A, ClassName.B, ClassName.C)) {
                if (sup.ordinal() < clazz.ordinal()) continue;
                check("sub_"+count++, clazz, sup);
            }
        }
    }

    static JavaSource[] initialSources = new JavaSource[] {
            new JavaSource(ClassName.A, ClassName.OBJECT),
            new JavaSource(ClassName.B, ClassName.A),
            new JavaSource(ClassName.C, ClassName.B)
        };

    static String workDir = System.getProperty("user.dir");

    static void check(String destPath, ClassName clazz, ClassName sup) throws Exception {
        File destDir = new File(workDir, destPath); destDir.mkdir();
        final JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        JavacTask ct = (JavacTask)tool.getTask(null, null, null,
                Arrays.asList("-d", destPath), null, Arrays.asList(initialSources));
        ct.generate();
        File fileToRemove = new File(destPath, clazz.name + ".class");
        fileToRemove.delete();
        JavaSource newSource = new JavaSource(clazz, sup);
        DiagnosticChecker checker = new DiagnosticChecker();
        ct = (JavacTask)tool.getTask(null, null, checker,
                Arrays.asList("-cp", destPath), null, Arrays.asList(newSource));
        ct.analyze();
        if (!checker.errorFound) {
            throw new AssertionError(newSource.source);
        }
    }

    static class DiagnosticChecker implements DiagnosticListener<JavaFileObject> {

        boolean errorFound = false;

        public void report(Diagnostic<? extends JavaFileObject> diagnostic) {
            if (diagnostic.getKind() == Diagnostic.Kind.ERROR &&
                    diagnostic.getCode().equals("compiler.err.cyclic.inheritance")) {
                errorFound = true;
            }
        }
    }
}
