



import com.sun.source.tree.*;
import com.sun.source.util.*;
import java.io.*;
import java.lang.annotation.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.*;
import javax.lang.model.type.*;
import javax.tools.*;
import com.sun.tools.javac.api.JavacTool;
import com.sun.tools.javac.tree.JCTree;
import com.sun.tools.javac.tree.TreeInfo;

@Anno
@SupportedAnnotationTypes("*")
public class TestTrees extends AbstractProcessor {

    @Anno
    void annoMethod() { }

    @Anno
    int annoField;


    static final String testSrcDir = System.getProperty("test.src");
    static final String testClassDir = System.getProperty("test.classes");
    static final String self = TestTrees.class.getName();
    static PrintWriter out = new PrintWriter(System.err, true);

    public static void main(String[] args) throws IOException {
        new TestTrees().run();
    }

    void run() throws IOException {

        JavacTool tool = JavacTool.create();

        DiagnosticListener<JavaFileObject> dl = new DiagnosticListener<JavaFileObject>() {
                public void report(Diagnostic d) {
                    error(d.toString());
                }
            };

        StandardJavaFileManager fm = tool.getStandardFileManager(dl, null, null);
        Iterable<? extends JavaFileObject> files =
            fm.getJavaFileObjectsFromFiles(Arrays.asList(new File(testSrcDir, self + ".java")));

        Iterable<String> opts = Arrays.asList("-d", ".");

        System.err.println("simple compilation, no processing");
        JavacTask task = tool.getTask(out, fm, dl, opts, null, files);
        task.setTaskListener(new MyTaskListener(task));
        if (!task.call())
            throw new AssertionError("compilation failed");

        opts =  Arrays.asList("-d", ".", "-processorpath", testClassDir, "-processor", self);

        System.err.println();
        System.err.println("compilation with processing");
        task = tool.getTask(out, fm, dl,opts, null, files);
        if (!task.call())
            throw new AssertionError("compilation failed");

        if (errors > 0)
            throw new AssertionError(errors + " errors occurred");
    }

    void testElement(Trees trees, Element e) {
        trees.getClass();
        e.getClass();

        System.err.println("testElement: " + e);
        Tree tree = trees.getTree(e);
        

        if (TreeInfo.symbolFor((JCTree)tree) != e)
            error("bad result from getTree");

        TreePath path = trees.getPath(e);
        if (path == null) {
            error("getPath returned null");
            return;
        }
        if (path.getLeaf() != tree)
            error("bad result from getPath");

        Element e2 = trees.getElement(path);
        if (e2 == null) {
            error("getElement returned null");
            return;
        }
        if (e2 != e)
            error("bad result from getElement");

        
        
        TypeMirror t = trees.getTypeMirror(path);
        if (t != null && t.getKind() == TypeKind.DECLARED &&
                ((DeclaredType)t).asElement() != e2)
            error("bad result from getTypeMirror");

        for (AnnotationMirror m: e.getAnnotationMirrors()) {
            testAnnotation(trees, e, m);
        }
    }

    void testAnnotation(Trees trees, Element e, AnnotationMirror a) {
        System.err.println("testAnnotation: " + e + " " + a);
        Tree tree = trees.getTree(e, a);

        if (tree.getKind() != Tree.Kind.ANNOTATION)
            error("bad result from getTree");

        TreePath path = trees.getPath(e, a);
        if (path.getLeaf() != tree)
            error("bad result from getPath");
    }

    void error(String msg) {
        if (messager != null)
            
            
            messager.printMessage(Diagnostic.Kind.ERROR, msg);
        else {
            System.err.println(msg);
            errors++;
        }

    }

    Messager messager;
    int errors;


    public boolean process(Set<? extends TypeElement> annos, RoundEnvironment rEnv) {
        Trees trees = Trees.instance(processingEnv);
        messager = processingEnv.getMessager();

        for (Element e: rEnv.getRootElements()) {
            testElement(trees, e);
        }

        for (TypeElement anno: annos) {
            Set<? extends Element> elts = rEnv.getElementsAnnotatedWith(anno);
            System.err.println("anno: " + anno);
            System.err.println("elts: " + elts);
            if (elts != null) { 
                for (Element e: rEnv.getElementsAnnotatedWith(anno))
                    testElement(trees, e);
            }
        }

        return true;
    }

    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    class MyTaskListener implements TaskListener {
        MyTaskListener(JavacTask task) {
            this.task = task;
        }

        public void started(TaskEvent e) {
            System.err.println("started " + e);
        }

        public void finished(TaskEvent e) {
            
            switch (e.getKind()) {
            case ANALYZE:
                testElement(Trees.instance(task), e.getTypeElement());
                break;
            }
        }

        private final JavacTask task;
    }

}

@Retention(RetentionPolicy.SOURCE)
@interface Anno {
}
