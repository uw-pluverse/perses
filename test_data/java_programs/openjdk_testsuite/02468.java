



import com.sun.tools.javac.api.JavacTool;
import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.HashMap;
import java.lang.annotation.*;
import javax.tools.JavaFileManager;
import javax.tools.JavaFileObject;
import com.sun.source.tree.*;
import com.sun.source.util.JavacTask;
import com.sun.source.util.TreeScanner;
import javax.tools.StandardJavaFileManager;


public class AnnotatedArrayOrder {
    public static void main(String[] args) throws Exception {
        PrintWriter out = new PrintWriter(System.out, true);
        JavacTool tool = JavacTool.create();
        StandardJavaFileManager fm = tool.getStandardFileManager(null, null, null);
        File testSrc = new File(System.getProperty("test.src"));
        Iterable<? extends JavaFileObject> f =
            fm.getJavaFileObjectsFromFiles(Arrays.asList(new File(testSrc, "AnnotatedArrayOrder.java")));
        JavacTask task = tool.getTask(out, fm, null, null, null, f);
        Iterable<? extends CompilationUnitTree> trees = task.parse();
        out.flush();

        Scanner s = new Scanner();
        for (CompilationUnitTree t: trees)
            s.scan(t, null);

    }

    private static class Scanner extends TreeScanner<Void,Void> {
        public Void visitCompilationUnit(CompilationUnitTree node, Void ignore) {
            super.visitCompilationUnit(node, ignore);
            if (!expectedLocations.isEmpty()) {
                throw new AssertionError("Didn't found all annotations: " + expectedLocations);
            }
            return null;
        }

        private void testAnnotations(List<? extends AnnotationTree> annos, int found) {
            String annotation = annos.get(0).toString();

            if (!expectedLocations.containsKey(annotation))
                throw new AssertionError("Found unexpected annotation: " + annotation + expectedLocations);

            int expected = expectedLocations.get(annotation);
            if (found != expected)
                throw new AssertionError("The expected array length for this error doesn't match");

            expectedLocations.remove(annotation);
        }

        public Void visitAnnotatedType(AnnotatedTypeTree node, Void ignore) {
            testAnnotations(node.getAnnotations(), arrayLength(node));
            return super.visitAnnotatedType(node, ignore);
        }

        private int arrayLength(Tree tree) {
            switch (tree.getKind()) {
            case ARRAY_TYPE:
                return 1 + arrayLength(((ArrayTypeTree)tree).getType());
            case ANNOTATED_TYPE:
                return arrayLength(((AnnotatedTypeTree)tree).getUnderlyingType());
            default:
                return 0;
            }
        }
    }

    
    static Map<String, Integer> expectedLocations = new HashMap<String, Integer>();

    
    @A String @C [] @B [] field;
    static {
        
        expectedLocations.put("@B()", 1);
        expectedLocations.put("@C()", 2);
    }

    List<@D String @F [] @E []> typearg;
    static {
        expectedLocations.put("@D()", 0);
        expectedLocations.put("@E()", 1);
        expectedLocations.put("@F()", 2);
    }

    void varargSimple(@G String @H ... vararg1) { }
    static {
        
        expectedLocations.put("@H()", 1);
    }

    void varargLong(@I String @L [] @K [] @J ... vararg2) { }
    static {
        
        expectedLocations.put("@J()", 1);
        expectedLocations.put("@K()", 2);
        expectedLocations.put("@L()", 3);
    }

    @Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
    @interface A {}
    @Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
    @interface B {}
    @Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
    @interface C {}

    @Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
    @interface D {}
    @Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
    @interface E {}
    @Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
    @interface F {}

    @Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
    @interface G {}
    @Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
    @interface H {}
    @Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
    @interface I {}

    @Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
    @interface J {}
    @Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
    @interface K {}
    @Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
    @interface L {}
}
