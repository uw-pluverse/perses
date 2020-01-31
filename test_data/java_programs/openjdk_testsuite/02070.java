






import java.io.*;
import java.lang.reflect.*;
import java.util.*;
import javax.tools.*;

import com.sun.tools.javac.tree.JCTree;
import com.sun.tools.javac.tree.JCTree.JCCompilationUnit;
import com.sun.tools.javac.tree.TreeScanner;
import com.sun.tools.javac.util.List;

public class JavacTreeScannerTest extends AbstractTreeScannerTest {
    
    public static void main(String... args) {
        String testSrc = System.getProperty("test.src");
        File baseDir = (testSrc == null) ? null : new File(testSrc);
        boolean ok = new JavacTreeScannerTest().run(baseDir, args);
        if (!ok) {
            if (testSrc != null)  
                throw new Error("failed");
            else
                System.exit(1);
        }
    }

    int test(JCCompilationUnit tree) {
        return new ScanTester().test(tree);
    }

    
    private class ScanTester extends TreeScanner {
        
        int test(JCCompilationUnit tree) {
            sourcefile = tree.sourcefile;
            found = new HashSet<JCTree>();
            scan(tree);
            expect = new HashSet<JCTree>();
            reflectiveScan(tree);

            if (found.equals(expect)) {
                
                return found.size();
            }

            error(sourcefile, "differences found");

            if (found.size() != expect.size())
                error("Size mismatch; found: " + found.size() + ", expected: " + expect.size());

            Set<JCTree> missing = new HashSet<JCTree>();
            missing.addAll(expect);
            missing.removeAll(found);
            for (JCTree t: missing)
                error(sourcefile, t, "missing");

            Set<JCTree> excess = new HashSet<JCTree>();
            excess.addAll(found);
            excess.removeAll(expect);
            for (JCTree t: excess)
                error(sourcefile, t, "unexpected");

            return 0;
        }

        
        @Override
        public void scan(JCTree tree) {
            if (tree == null)
                return;
            
            found.add(tree);
            super.scan(tree);
        }

        
        public void reflectiveScan(Object o) {
            if (o == null)
                return;
            if (o instanceof JCTree) {
                JCTree tree = (JCTree) o;
                
                expect.add(tree);
                for (Field f: getFields(tree)) {
                    try {
                        
                        reflectiveScan(f.get(tree));
                    } catch (IllegalAccessException e) {
                        error(e.toString());
                    }
                }
            } else if (o instanceof List) {
                List<?> list = (List<?>) o;
                for (Object item: list)
                    reflectiveScan(item);
            } else
                error("unexpected item: " + o);
        }

        JavaFileObject sourcefile;
        Set<JCTree> found;
        Set<JCTree> expect;
    }
}
