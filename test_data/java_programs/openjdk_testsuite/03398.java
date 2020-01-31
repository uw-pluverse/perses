



import com.sun.source.util.JavacTask;
import java.net.URI;
import java.util.Arrays;
import javax.tools.Diagnostic;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.StandardJavaFileManager;
import javax.tools.ToolProvider;

public class IntersectionTypeParserTest {

    static int checkCount = 0;

    enum TypeKind {
        SIMPLE("A"),
        GENERIC("A<X>"),
        WILDCARD("A<? super X, ? extends Y>");

        String typeStr;

        TypeKind(String typeStr) {
            this.typeStr = typeStr;
        }
    }

    enum ArrayKind {
        NONE(""),
        SINGLE("[]"),
        DOUBLE("[][]");

        String arrStr;

        ArrayKind(String arrStr) {
            this.arrStr = arrStr;
        }
    }

    static class Type {
        TypeKind tk;
        ArrayKind ak;

        Type(TypeKind tk, ArrayKind ak) {
            this.tk = tk;
            this.ak = ak;
        }

        String asString() {
            return tk.typeStr + ak.arrStr;
        }
    }

    enum CastKind {
        ONE("(#T0)", 1),
        TWO("(#T0 & T1)", 2),
        THREE("(#T0 & #T1 & #T2)", 3);

        String castTemplate;
        int nBounds;

        CastKind(String castTemplate, int nBounds) {
            this.castTemplate = castTemplate;
            this.nBounds = nBounds;
        }

        String asString(Type... types) {
            String res = castTemplate;
            for (int i = 0; i < nBounds ; i++) {
                res = res.replaceAll(String.format("#T%d", i), types[i].asString());
            }
            return res;
        }
    }

    public static void main(String... args) throws Exception {
        
        JavaCompiler comp = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager fm = comp.getStandardFileManager(null, null, null);

        for (CastKind ck : CastKind.values()) {
            for (TypeKind t1 : TypeKind.values()) {
                for (ArrayKind ak1 : ArrayKind.values()) {
                    Type typ1 = new Type(t1, ak1);
                    if (ck.nBounds == 1) {
                        new IntersectionTypeParserTest(ck, typ1).run(comp, fm);
                        continue;
                    }
                    for (TypeKind t2 : TypeKind.values()) {
                        for (ArrayKind ak2 : ArrayKind.values()) {
                            Type typ2 = new Type(t2, ak2);
                            if (ck.nBounds == 2) {
                                new IntersectionTypeParserTest(ck, typ1, typ2).run(comp, fm);
                                continue;
                            }
                            for (TypeKind t3 : TypeKind.values()) {
                                for (ArrayKind ak3 : ArrayKind.values()) {
                                    Type typ3 = new Type(t3, ak3);
                                    new IntersectionTypeParserTest(ck, typ1, typ2, typ3).run(comp, fm);
                                }
                            }
                        }
                    }
                }
            }
        }
        System.out.println("Total check executed: " + checkCount);
    }

    CastKind ck;
    Type[] types;
    JavaSource source;
    DiagnosticChecker diagChecker;

    IntersectionTypeParserTest(CastKind ck, Type... types) {
        this.ck = ck;
        this.types = types;
        this.source = new JavaSource();
        this.diagChecker = new DiagnosticChecker();
    }

    class JavaSource extends SimpleJavaFileObject {

        String bodyTemplate = "class Test {\n" +
                              "   void test() {\n" +
                              "      Object o = #Cnull;\n" +
                              "   } }";

        String source = "";

        public JavaSource() {
            super(URI.create("myfo:/Test.java"), JavaFileObject.Kind.SOURCE);
            source += bodyTemplate.replaceAll("#C", ck.asString(types));
        }

        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return source;
        }
    }

    void run(JavaCompiler tool, StandardJavaFileManager fm) throws Exception {
        checkCount++;
        JavacTask ct = (JavacTask)tool.getTask(null, fm, diagChecker,
                null, null, Arrays.asList(source));
        ct.parse();
        if (diagChecker.errorFound) {
            throw new Error("Unexpected parser error for source:\n" +
                source.getCharContent(true));
        }
    }

    static class DiagnosticChecker implements javax.tools.DiagnosticListener<JavaFileObject> {

        boolean errorFound;

        public void report(Diagnostic<? extends JavaFileObject> diagnostic) {
            if (diagnostic.getKind() == Diagnostic.Kind.ERROR) {
                errorFound = true;
            }
        }
    }
}
