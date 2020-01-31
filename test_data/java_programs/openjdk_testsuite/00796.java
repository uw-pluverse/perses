



import com.sun.source.tree.AssignmentTree;
import com.sun.source.tree.CompilationUnitTree;
import com.sun.source.util.JavacTask;
import com.sun.source.util.TreePath;
import com.sun.source.util.TreePathScanner;
import com.sun.source.util.Trees;
import com.sun.tools.javac.util.List;
import java.io.IOException;
import java.net.URI;
import javax.lang.model.type.TypeKind;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;

public class Main {
    static class MyFileObject extends SimpleJavaFileObject {
        public MyFileObject() {
            super(URI.create("myfo:/Test.java"), JavaFileObject.Kind.SOURCE);
        }
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return "public class Test { { x = java.util.Collections.emptySet(); } }";
        }
    }
    static Trees trees;
    public static void main(String[] args) throws IOException {
        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        JavacTask task = (JavacTask) compiler.getTask(null, null, null, null, null, List.of(new MyFileObject()));
        trees = Trees.instance(task);
        Iterable<? extends CompilationUnitTree> asts = task.parse();
        task.analyze();
        for (CompilationUnitTree ast : asts) {
            new MyVisitor().scan(ast, null);
        }
    }

    static class MyVisitor extends TreePathScanner<Void,Void> {
        @Override
        public Void visitAssignment(AssignmentTree node, Void ignored) {
            TreePath path = TreePath.getPath(getCurrentPath(), node.getExpression());
            if (trees.getTypeMirror(path).getKind() == TypeKind.ERROR)
                throw new AssertionError(path.getLeaf());
            return null;
        }

    }
}
