



import com.sun.source.tree.IdentifierTree;
import java.io.File;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Set;
import javax.annotation.processing.AbstractProcessor;
import javax.annotation.processing.RoundEnvironment;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.StandardJavaFileManager;
import javax.tools.ToolProvider;

import com.sun.source.util.JavacTask;
import com.sun.source.util.TreePath;
import com.sun.source.util.TreePathScanner;
import com.sun.source.util.Trees;
import javax.annotation.processing.SupportedAnnotationTypes;
import javax.lang.model.SourceVersion;

@SupportedAnnotationTypes("*")
public class TestGetScope extends AbstractProcessor {
    public static void main(String... args) {
        new TestGetScope().run();
    }

    public void run() {
        File srcDir = new File(System.getProperty("test.src"));
        File thisFile = new File(srcDir, getClass().getName() + ".java");

        JavaCompiler c = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager fm = c.getStandardFileManager(null, null, null);

        List<String> opts = Arrays.asList("-proc:only", "-doe");
        Iterable<? extends JavaFileObject> files = fm.getJavaFileObjects(thisFile);
        JavacTask t = (JavacTask) c.getTask(null, fm, null, opts, null, files);
        t.setProcessors(Collections.singleton(this));
        boolean ok = t.call();
        if (!ok)
            throw new Error("compilation failed");
    }

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        Trees trees = Trees.instance(processingEnv);
        if (round++ == 0) {
            for (Element e: roundEnv.getRootElements()) {
                TreePath p = trees.getPath(e);
                new Scanner().scan(p, trees);
            }
        }
        return false;
    }

    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    int round;

    static class Scanner extends TreePathScanner<Void,Trees> {
        @Override
        public Void visitIdentifier(IdentifierTree t, Trees trees) {
            System.err.println("visitIdentifier: " + t);
            trees.getScope(getCurrentPath());
            return null;
        }
    }
}
