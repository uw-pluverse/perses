



import java.io.*;
import java.net.URI;
import java.util.Arrays;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.StandardJavaFileManager;
import javax.tools.StandardLocation;
import javax.tools.ToolProvider;

import com.sun.source.util.JavacTask;

public class TestCircularClassfile {

    enum SourceKind {
        A_EXTENDS_B("class B {} class A extends B { void m() {} }"),
        B_EXTENDS_A("class A { void m() {} } class B extends A {}");

        String sourceStr;

        private SourceKind(String sourceStr) {
            this.sourceStr = sourceStr;
        }

        SimpleJavaFileObject getSource() {
            return new SimpleJavaFileObject(URI.create("myfo:/Test.java"), JavaFileObject.Kind.SOURCE) {
                @Override
                public CharSequence getCharContent(boolean ignoreEncodingErrors) throws IOException {
                    return sourceStr;
                }
            };
        }
    }

    enum TestKind {
        REPLACE_A("A.class"),
        REPLACE_B("B.class");

        String targetClass;

        private TestKind(String targetClass) {
            this.targetClass = targetClass;
        }
    }

    enum ClientKind {
        METHOD_CALL1("A a = null; a.m();"),
        METHOD_CALL2("B b = null; b.m();"),
        CONSTR_CALL1("new A();"),
        CONSTR_CALL2("new B();"),
        ASSIGN1("A a = null; B b = a;"),
        ASSIGN2("B b = null; A a = b;");

        String mainMethod;

        private ClientKind(String mainMethod) {
            this.mainMethod = mainMethod;
        }

        SimpleJavaFileObject getSource() {
            return new SimpleJavaFileObject(URI.create("myfo:/Test.java"), JavaFileObject.Kind.SOURCE) {
                @Override
                public CharSequence getCharContent(boolean ignoreEncodingErrors) throws IOException {
                    return "class Test { public static void main(String[] args) { #M } }"
                            .replace("#M", mainMethod);
                }
            };
        }
    }

    public static void main(String... args) throws Exception {
        JavaCompiler comp = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager fm = comp.getStandardFileManager(null, null, null);
        int count = 0;
        for (SourceKind sk1 : SourceKind.values()) {
            for (SourceKind sk2 : SourceKind.values()) {
                for (TestKind tk : TestKind.values()) {
                    for (ClientKind ck : ClientKind.values()) {
                        new TestCircularClassfile("sub_"+count++, sk1, sk2, tk, ck).check(comp, fm);
                    }
                }
            }
        }
    }

    static String workDir = System.getProperty("user.dir");

    String destPath;
    SourceKind sk1;
    SourceKind sk2;
    TestKind tk;
    ClientKind ck;

    TestCircularClassfile(String destPath, SourceKind sk1, SourceKind sk2, TestKind tk, ClientKind ck) {
        this.destPath = destPath;
        this.sk1 = sk1;
        this.sk2 = sk2;
        this.tk = tk;
        this.ck = ck;
    }

    void check(JavaCompiler comp, StandardJavaFileManager fm) throws Exception {
        
        File destDir = new File(workDir, destPath); destDir.mkdir();
        
        fm.setLocation(javax.tools.StandardLocation.CLASS_OUTPUT, Arrays.asList(destDir));
        JavacTask ct = (JavacTask)comp.getTask(null, fm, null,
                null, null, Arrays.asList(sk1.getSource()));
        ct.generate();

        
        File tmpDir = new File(destDir, "tmp"); tmpDir.mkdir();
        
        fm.setLocation(javax.tools.StandardLocation.CLASS_OUTPUT, Arrays.asList(tmpDir));
        ct = (JavacTask)comp.getTask(null, fm, null,
                null, null, Arrays.asList(sk2.getSource()));
        ct.generate();

        
        File fileToMove = new File(tmpDir, tk.targetClass);
        File target = new File(destDir, tk.targetClass);
        target.delete();
        boolean success = fileToMove.renameTo(target);

        if (!success) {
            throw new AssertionError("error when moving file " + tk.targetClass);
        }

        
        
        fm.setLocation(StandardLocation.CLASS_OUTPUT, Arrays.asList(destDir));
        fm.setLocation(StandardLocation.CLASS_PATH, Arrays.asList(destDir));
        ct = (JavacTask)comp.getTask(null, fm, null,
                null, null, Arrays.asList(ck.getSource()));

        ct.generate();
    }
}
