


import java.io.*;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Set;

import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;
import javax.lang.model.util.ElementFilter;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.StandardJavaFileManager;
import javax.tools.ToolProvider;

import com.sun.source.tree.Tree;
import com.sun.source.util.*;

@SupportedAnnotationTypes("*")
public class TestTreePath extends AbstractProcessor {

    @Override
    public boolean process(Set<? extends TypeElement> annotations,
            RoundEnvironment roundEnv) {
        final Trees trees = Trees.instance(this.processingEnv);
        for (Element element : ElementFilter.typesIn(roundEnv.getRootElements())) {
            checkTreePath(trees, element, 2);
            for (Element member : element.getEnclosedElements())
                checkTreePath(trees, member, 3);
        }
        return true;
    }

    private void checkTreePath(Trees trees, Element element, int expectedLength) {
        TreePath path = trees.getPath(element);
        assert path != null;

        int enhancedLength = 0;
        for (Tree tree : path)
            ++enhancedLength;

        if (enhancedLength != expectedLength)
            throw new RuntimeException("found path length is wrong");

        int normalLoopLength = 0;
        Iterator<Tree> iter = path.iterator();
        while (iter.hasNext()) {
          iter.next();
          ++normalLoopLength;
        }
        if (normalLoopLength != expectedLength)
            throw new RuntimeException("found path length is wrong");

        TreePath curr = path;
        
        int whileLoopLength = 0;
        while (curr != null) {
          ++whileLoopLength;
          curr = curr.getParentPath();
        }
        if (whileLoopLength != expectedLength)
            throw new RuntimeException("found path length is wrong");
    }

    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    File writeTestFile() throws IOException {
        File f = new File("Test.java");
        PrintWriter out = new PrintWriter(new FileWriter(f));
        out.println("class Test { void method() { } }");
        out.close();
        return f;
    }

    public void run() throws IOException {
        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager fileManager
            = compiler.getStandardFileManager(null, null, null);
        Iterable<? extends JavaFileObject> tests
            = fileManager.getJavaFileObjects(writeTestFile());

        JavaCompiler.CompilationTask task =
            ToolProvider.getSystemJavaCompiler().getTask(
                    null, null, null,
                    Arrays.asList("-processor", this.getClass().getName()), null,
                    tests);
        task.call();
    }

    public static void main(String[] args) throws IOException {
        new TestTreePath().run();
    }
}
