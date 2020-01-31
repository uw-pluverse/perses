



import java.io.*;
import java.util.*;
import javax.tools.*;
import com.sun.source.tree.*;
import com.sun.source.util.*;
import com.sun.tools.javac.api.JavacTool;


public class TestDocComments {
    
    public static void main(String... args) throws Exception {
        new TestDocComments().run();
    }

    
    void run() throws Exception {
        File testSrc = new File(System.getProperty("test.src"));
        File file = new File(testSrc, "TestDocComments.java");

        JavacTool tool = JavacTool.create();
        StandardJavaFileManager fm = tool.getStandardFileManager(null, null, null);

        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        Iterable<? extends JavaFileObject> fileObjects = fm.getJavaFileObjects(file);
        JavacTask task = tool.getTask(pw, fm, null, null, null, fileObjects);
        Iterable<? extends CompilationUnitTree> units = task.parse();
        Trees trees = Trees.instance(task);

        CommentScanner s = new CommentScanner();
        int n = s.scan(units, trees);

        if (n != 12)
            error("Unexpected number of doc comments found: " + n);

        if (errors > 0)
            throw new Exception(errors + " errors occurred");
    }

    
    class CommentScanner extends TreePathScanner<Integer,Trees> {

        
        @Override
        public Integer visitClass(ClassTree t, Trees trees) {
            return reduce(super.visitClass(t, trees),
                    check(trees, "class-" + t.getSimpleName() + "."));
        }

        
        @Override
        public Integer visitMethod(MethodTree t, Trees trees) {
            return reduce(super.visitMethod(t, trees),
                    check(trees, "method-" + t.getName() + "."));
        }

        
        @Override
        public Integer visitVariable(VariableTree t, Trees trees) {
            
            int n = (getCurrentPath().getParentPath().getLeaf().getKind() == Tree.Kind.CLASS)
                    ? check(trees, "field-" + t.getName() + ".")
                    : 0;
            return reduce(super.visitVariable(t, trees), n);
        }

        
        @Override
        public Integer reduce(Integer i1, Integer i2) {
            return (i1 == null) ? i2 : (i2 == null) ? i1 : Integer.valueOf(i1 + i2);
        }

        
        int check(Trees trees, String expect) {
            TreePath p = getCurrentPath();
            String dc = trees.getDocComment(p);

            if (dc != null && dc.trim().equals(expect))
                return 1;

            Tree.Kind k = p.getLeaf().getKind();
            if (dc == null)
                error("no doc comment for " + k);
            else
                error("unexpected doc comment for " + k + "\nexpect: " + expect + "\nfound:  " + dc);

            return 0;
        }
    }

    
    int nullCheck(Integer i) {
        return (i == null) ? 0 : i;
    }

    
    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    
    int errors;
}

