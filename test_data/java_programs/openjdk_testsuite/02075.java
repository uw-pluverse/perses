






import java.io.*;
import java.lang.reflect.*;
import java.util.*;
import javax.tools.*;

import com.sun.source.tree.Tree;
import com.sun.source.util.TreeScanner;
import com.sun.tools.javac.tree.JCTree;
import com.sun.tools.javac.tree.JCTree.JCCompilationUnit;
import com.sun.tools.javac.tree.JCTree.TypeBoundKind;
import com.sun.tools.javac.util.List;

public class SourceTreeScannerTest extends AbstractTreeScannerTest {
    
    public static void main(String... args) {
        String testSrc = System.getProperty("test.src");
        File baseDir = (testSrc == null) ? null : new File(testSrc);
        boolean ok = new SourceTreeScannerTest().run(baseDir, args);
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

    
    private class ScanTester extends TreeScanner<Void,Void> {
        
        int test(JCCompilationUnit tree) {
            sourcefile = tree.sourcefile;
            found = new HashSet<Tree>();
            scan(tree, null);
            expect = new HashSet<Tree>();
            reflectiveScan(tree);

            if (found.equals(expect)) {
                
                return found.size();
            }

            error(sourcefile.getName() + ": differences found");

            if (found.size() != expect.size())
                error("Size mismatch; found: " + found.size() + ", expected: " + expect.size());

            Set<Tree> missing = new HashSet<Tree>();
            missing.addAll(expect);
            missing.removeAll(found);
            for (Tree t: missing)
                error(sourcefile, t, "missing");

            Set<Tree> excess = new HashSet<Tree>();
            excess.addAll(found);
            excess.removeAll(expect);
            for (Tree t: excess)
                error(sourcefile, t, "unexpected");

            return 0;
        }

        
        @Override
        public Void scan(Tree tree, Void ignore) {
            if (tree == null)
                return null;
            
            found.add(tree);
            return super.scan(tree, ignore);
        }

        
        public void reflectiveScan(Object o) {
            if (o == null)
                return;
            if (o instanceof JCTree) {
                JCTree tree = (JCTree) o;
                
                expect.add(tree);
                for (Field f: getFields(tree)) {
                    if (TypeBoundKind.class.isAssignableFrom(f.getType())) {
                        
                        continue;
                    }
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
        Set<Tree> found;
        Set<Tree> expect;
    }
}
