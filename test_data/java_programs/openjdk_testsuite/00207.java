



import com.sun.source.util.JavacTask;
import java.net.URI;
import java.util.Arrays;
import javax.tools.Diagnostic;
import javax.tools.DiagnosticListener;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;

public class T6996914a {

    enum PackageKind {
        DEFAULT("", ""),
        A("package a;", "import a.*;");

        String pkgDecl;
        String importDecl;

        PackageKind(String pkgDecl, String importDecl) {
            this.pkgDecl = pkgDecl;
            this.importDecl = importDecl;
        }
    }

    enum ConstructorKind {
        PACKAGE(""),
        PROTECTED("protected"),
        PRIVATE("private"),
        PUBLIC("public");

        String mod;

        ConstructorKind(String mod) {
            this.mod = mod;
        }
    }

    static class FooClass extends SimpleJavaFileObject {

        final static String sourceStub =
                        "#P\n" +
                        "public class Foo<X> {\n" +
                        "  #M Foo() {}\n" +
                        "}\n";

        String source;

        public FooClass(PackageKind pk, ConstructorKind ck) {
            super(URI.create("myfo:/" + (pk != PackageKind.DEFAULT ? "a/Foo.java" : "Foo.java")),
                    JavaFileObject.Kind.SOURCE);
            source = sourceStub.replace("#P", pk.pkgDecl).replace("#M", ck.mod);
        }

        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return source;
        }
    }

    static class ClientClass extends SimpleJavaFileObject {

        final static String sourceStub =
                        "#I\n" +
                        "class Test {\n" +
                        "  Foo<String> fs = new Foo<>();\n" +
                        "}\n";

        String source;

        public ClientClass(PackageKind pk) {
            super(URI.create("myfo:/Test.java"), JavaFileObject.Kind.SOURCE);
            source = sourceStub.replace("#I", pk.importDecl);
        }

        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return source;
        }
    }

    public static void main(String... args) throws Exception {
        for (PackageKind pk : PackageKind.values()) {
            for (ConstructorKind ck : ConstructorKind.values()) {
                    compileAndCheck(pk, ck);
            }
        }
    }

    static void compileAndCheck(PackageKind pk, ConstructorKind ck) throws Exception {
        FooClass foo = new FooClass(pk, ck);
        ClientClass client = new ClientClass(pk);
        final JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        ErrorListener el = new ErrorListener();
        JavacTask ct = (JavacTask)tool.getTask(null, null, el,
                null, null, Arrays.asList(foo, client));
        ct.analyze();
        if (el.errors > 0 == check(pk, ck)) {
            String msg = el.errors > 0 ?
                "Error compiling files" :
                "No error when compiling files";
            throw new AssertionError(msg + ": \n" + foo.source + "\n" + client.source);
        }
    }

    static boolean check(PackageKind pk, ConstructorKind ck) {
        switch (pk) {
            case A: return ck == ConstructorKind.PUBLIC;
            case DEFAULT: return ck != ConstructorKind.PRIVATE;
            default: throw new AssertionError("Unknown package kind");
        }
    }

    
    private static class ErrorListener implements DiagnosticListener<JavaFileObject> {

        public void report(Diagnostic<? extends JavaFileObject> diagnostic) {
            switch (diagnostic.getKind()) {
                case ERROR:
                    errors++;
            }
        }
        int errors;
    }
}
