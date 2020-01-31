

import java.io.*;
import java.net.*;
import javax.tools.*;
import java.util.*;

import com.sun.source.tree.CompilationUnitTree;
import com.sun.source.util.JavacTask;
import com.sun.tools.javac.api.JavacTool;
import com.sun.tools.javac.tree.JCTree;
import com.sun.tools.javac.tree.Pretty;



public class Test {

    public static void main(String[] args) throws Exception {
        Test t = new Test();
        t.run("E1.java", "E2.java");
    }

    void run(String... args) throws Exception {
        File testSrcDir = new File(System.getProperty("test.src"));
        for (String arg: args) {
            test(new File(testSrcDir, arg));
        }
    }

    void test(File test) throws Exception {
        JavacTool tool1 = JavacTool.create();
        StandardJavaFileManager fm = tool1.getStandardFileManager(null, null, null);
        Iterable<? extends JavaFileObject> files = fm.getJavaFileObjects(test);

        
        JavacTask t1 = tool1.getTask(null, fm, null, null, null, files);
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        Iterable<? extends CompilationUnitTree> trees = t1.parse();
        for (CompilationUnitTree tree: trees) {
            new Pretty(pw, true).printExpr((JCTree) tree);
        }
        pw.close();

        final String out = sw.toString();
        System.err.println("generated code:\n" + out + "\n");

        
        JavacTool tool2 = JavacTool.create();
        JavaFileObject fo = new SimpleJavaFileObject(URI.create("output"), JavaFileObject.Kind.SOURCE) {
            @Override
            public CharSequence getCharContent(boolean ignoreEncodingErrors) {
                return out;
            }
        };
        JavacTask t2 = tool2.getTask(null, fm, null, null, null, Collections.singleton(fo));
        boolean ok = t2.call();
        if (!ok)
            throw new Exception("compilation of generated code failed");

        File expectedClass = new File(test.getName().replace(".java", ".class"));
        if (!expectedClass.exists())
            throw new Exception(expectedClass + " not found");
    }
}

