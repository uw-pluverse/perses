



import java.io.*;
import java.util.*;
import javax.tools.*;
import com.sun.source.tree.*;
import com.sun.source.util.*;
import com.sun.tools.javac.api.*;

public class T6431879 {
    public static void main(String... args) throws IOException {
        String testSrc = System.getProperty("test.src", ".");
        String testClasses = System.getProperty("test.classes", ".");
        JavacTool tool = JavacTool.create();
        StandardJavaFileManager fm = tool.getStandardFileManager(null, null, null);
        Iterable<? extends JavaFileObject> files =
            fm.getJavaFileObjectsFromFiles(Arrays.asList(new File(testSrc, T6431879.class.getName()+".java")));
        JavacTask task = tool.getTask(null, fm, null, null, null, files);
        Iterable<? extends CompilationUnitTree> trees = task.parse();
        TreeScanner<Void,Trees> dependencyScanner = new DependencyScanner();
        Trees treeUtil = Trees.instance(task);
        for (CompilationUnitTree unit : trees) {
            
            dependencyScanner.scan(unit, treeUtil);
        }

    }

    private static class DependencyScanner<R,P> extends TreePathScanner<R,P> {
        public R visitIdentifier(IdentifierTree tree, P p) {
            
            return null;
        }
    }
}
