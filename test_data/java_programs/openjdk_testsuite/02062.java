



import java.io.*;
import java.util.*;
import javax.tools.*;
import com.sun.source.tree.*;
import com.sun.source.util.*;
import com.sun.tools.javac.api.*;

public class ClassTreeTest {
    public static void main(String... args) throws Exception {
        new ClassTreeTest().run();
    }

    void run() throws Exception {
        JavacTool tool = JavacTool.create();
        StandardJavaFileManager fm = tool.getStandardFileManager(null, null, null);
        List<String> opts = Collections.<String>emptyList();
        File testSrc = new File(System.getProperty("test.src"));
        File thisFile = new File(testSrc, ClassTreeTest.class.getSimpleName() + ".java");
        Iterable<? extends JavaFileObject> fos = fm.getJavaFileObjects(thisFile);
        JavacTask task = tool.getTask(null, fm, null, opts, null, fos);
        for (CompilationUnitTree cu: task.parse()) {
            check(cu, "CLASS", Tree.Kind.CLASS);
            check(cu, "INTERFACE", Tree.Kind.INTERFACE);
            check(cu, "ENUM", Tree.Kind.ENUM);
            check(cu, "ANNOTATION_TYPE", Tree.Kind.ANNOTATION_TYPE);
        }

        int expected = 4;
        if (checks != expected)
            error("Unexpected number of checks performed; expected: " + expected + ", found: " + checks);

        if (errors > 0)
            throw new Exception(errors + " errors found");
    }

    void check(CompilationUnitTree cu, String name, Tree.Kind k) {
        checks++;

        TreeScanner<ClassTree,String> s = new TreeScanner<ClassTree,String>() {
            @Override
            public ClassTree visitClass(ClassTree c, String name) {
                if (c.getSimpleName().toString().equals(name))
                    return c;
                else
                    return super.visitClass(c, name);
            }

            @Override
            public ClassTree reduce(ClassTree t1, ClassTree t2) {
                return (t1 != null ? t1 : t2);
            }
        };

        ClassTree c = s.scan(cu, name);
        if (c == null)
            error("Can't find node named " + name);
        else if (c.getKind() != k)
            error("Unexpected kind for node named " + name + ": expected: " + k + ", found: " + c.getKind());
    }

    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    int checks;
    int errors;

    class CLASS { }
    interface INTERFACE { }
    enum ENUM { }
    @interface ANNOTATION_TYPE { }
}
