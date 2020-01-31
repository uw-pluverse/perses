



import java.io.*;
import java.util.*;
import javax.tools.*;
import com.sun.source.tree.*;
import com.sun.source.util.*;
import com.sun.tools.javac.api.*;

public class T6392782 {
    public static void main(String... args) throws IOException {
        String testSrc = System.getProperty("test.src", ".");
        JavacTool tool = JavacTool.create();
        StandardJavaFileManager fm = tool.getStandardFileManager(null, null, null);
        Iterable<? extends JavaFileObject> files =
            fm.getJavaFileObjectsFromFiles(Arrays.asList(new File(testSrc, T6392782.class.getName()+".java")));
        JavacTask task = tool.getTask(null, fm, null, null, null, files);
        Iterable<? extends Tree> trees = task.parse();
        TreeScanner<Integer,Void> scanner = new MyScanner();
        check(scanner, 6, scanner.scan(trees, null));

        CountNodes nodeCounter = new CountNodes();
        
        
        check(nodeCounter, 360, nodeCounter.scan(trees, null));

        CountIdentifiers idCounter = new CountIdentifiers();
        check(idCounter, 107, idCounter.scan(trees, null));
    }

    private static void check(TreeScanner<?,?> scanner, int expect, int found) {
        if (found != expect)
            throw new AssertionError(scanner.getClass().getName() + ": expected: " + expect + " found: " + found);
    }

    static class MyScanner extends TreeScanner<Integer,Void> {
        @Override
        public Integer visitImport(ImportTree tree, Void ignore) {
            
            return 1;
        }

        @Override
        public Integer reduce(Integer i1, Integer i2) {
            return (i1 == null ? 0 : i1) + (i2 == null ? 0 : i2);
        }
    }

    static class CountNodes extends TreeScanner<Integer,Void> {
        @Override
        public Integer scan(Tree node, Void p) {
            if (node == null)
                return 0;
            Integer n = super.scan(node, p);
            return (n == null ? 0 : n) + 1;
        }
        @Override
        public Integer reduce(Integer r1, Integer r2) {
            return (r1 == null ? 0 : r1) + (r2 == null ? 0 : r2);
        }
    }

    
    static class CountIdentifiers extends TreeScanner<Integer,Void> {
        @Override
        public Integer visitIdentifier(IdentifierTree node, Void p) {
            return 1;
        }
        @Override
        public Integer reduce(Integer r1, Integer r2) {
            return (r1 == null ? 0 : r1) + (r2 == null ? 0 : r2);
        }
    }
}
