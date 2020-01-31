






import java.net.URI;
import java.util.Arrays;
import javax.tools.Diagnostic;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import com.sun.source.util.JavacTask;

public class DisjunctiveTypeWellFormednessTest
    extends JavacTestingAbstractThreadedTest
    implements Runnable {

    enum Alternative {
        EXCEPTION("Exception"),
        RUNTIME_EXCEPTION("RuntimeException"),
        IO_EXCEPTION("java.io.IOException"),
        FILE_NOT_FOUND_EXCEPTION("java.io.FileNotFoundException"),
        ILLEGAL_ARGUMENT_EXCEPTION("IllegalArgumentException");

        String exceptionStr;

        private Alternative(String exceptionStr) {
            this.exceptionStr = exceptionStr;
        }

        static String makeDisjunctiveType(Alternative... alternatives) {
            StringBuilder buf = new StringBuilder();
            String sep = "";
            for (Alternative alternative : alternatives) {
                buf.append(sep);
                buf.append(alternative.exceptionStr);
                sep = "|";
            }
            return buf.toString();
        }

        boolean disjoint(Alternative that) {
            return disjoint[this.ordinal()][that.ordinal()];
        }

        static boolean[][] disjoint = {
            
                            {  false,       false,              false,         false,                   false },
                     {  false,       false,              true,          true,                    false },
                          {  false,       true,               false,         false,                   true },
                {  false,       true,               false,         false,                   true },
             {  false,       false,              true,          true,                    false }
        };
    }

    enum Arity {
        ONE(1),
        TWO(2),
        THREE(3),
        FOUR(4),
        FIVE(5);

        int n;

        private Arity(int n) {
            this.n = n;
        }
    }

    public static void main(String... args) throws Exception {
        for (Arity arity : Arity.values()) {
            for (Alternative a1 : Alternative.values()) {
                if (arity == Arity.ONE) {
                    pool.execute(new DisjunctiveTypeWellFormednessTest(a1));
                    continue;
                }
                for (Alternative a2 : Alternative.values()) {
                    if (arity == Arity.TWO) {
                        pool.execute(new DisjunctiveTypeWellFormednessTest(a1, a2));
                        continue;
                    }
                    for (Alternative a3 : Alternative.values()) {
                        if (arity == Arity.THREE) {
                            pool.execute(new DisjunctiveTypeWellFormednessTest(a1, a2, a3));
                            continue;
                        }
                        for (Alternative a4 : Alternative.values()) {
                            if (arity == Arity.FOUR) {
                                pool.execute(new DisjunctiveTypeWellFormednessTest(a1, a2, a3, a4));
                                continue;
                            }
                            for (Alternative a5 : Alternative.values()) {
                                pool.execute(new DisjunctiveTypeWellFormednessTest(a1, a2, a3, a4, a5));
                            }
                        }
                    }
                }
            }
        }

        checkAfterExec(false);
    }

    Alternative[] alternatives;
    JavaSource source;
    DiagnosticChecker diagChecker;

    DisjunctiveTypeWellFormednessTest(Alternative... alternatives) {
        this.alternatives = alternatives;
        this.source = new JavaSource();
        this.diagChecker = new DiagnosticChecker();
    }

    class JavaSource extends SimpleJavaFileObject {

        String template = "class Test {\n" +
                              "void test() {\n" +
                                 "try {} catch (#T e) {}\n" +
                              "}\n" +
                          "}\n";

        String source;

        public JavaSource() {
            super(URI.create("myfo:/Test.java"), JavaFileObject.Kind.SOURCE);
            source = template.replace("#T", Alternative.makeDisjunctiveType(alternatives));
        }

        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return source;
        }
    }

    @Override
    public void run() {
        JavacTask ct = (JavacTask)comp.getTask(null, fm.get(), diagChecker,
                null, null, Arrays.asList(source));
        try {
            ct.analyze();
        } catch (Throwable t) {
            processException(t);
            return;
        }
        check();
    }

    void check() {

        int non_disjoint = 0;
        int i = 0;
        for (Alternative a1 : alternatives) {
            int j = 0;
            for (Alternative a2 : alternatives) {
                if (i == j) continue;
                if (!a1.disjoint(a2)) {
                    non_disjoint++;
                    break;
                }
                j++;
            }
            i++;
        }

        if (non_disjoint != diagChecker.errorsFound) {
            throw new Error("invalid diagnostics for source:\n" +
                source.getCharContent(true) +
                "\nFound errors: " + diagChecker.errorsFound +
                "\nExpected errors: " + non_disjoint);
        }
    }

    static class DiagnosticChecker implements javax.tools.DiagnosticListener<JavaFileObject> {

        int errorsFound;

        public void report(Diagnostic<? extends JavaFileObject> diagnostic) {
            if (diagnostic.getKind() == Diagnostic.Kind.ERROR &&
                    diagnostic.getCode().startsWith("compiler.err.multicatch.types.must.be.disjoint")) {
                errorsFound++;
            }
        }
    }

}
