



import com.sun.source.tree.CompilationUnitTree;
import com.sun.source.tree.MemberSelectTree;
import com.sun.source.tree.Scope;
import com.sun.source.util.JavacTask;
import com.sun.source.util.TreePath;
import com.sun.source.util.TreePathScanner;
import com.sun.source.util.Trees;
import com.sun.tools.javac.api.JavacTaskImpl;
import com.sun.tools.javac.api.JavacTool;
import com.sun.tools.javac.model.JavacTypes;
import java.io.IOException;
import java.net.URI;
import java.util.ArrayList;
import java.util.Collections;
import javax.lang.model.element.Element;
import javax.lang.model.type.TypeMirror;
import javax.lang.model.util.Types;
import javax.tools.JavaFileObject;
import javax.tools.JavaFileObject.Kind;
import javax.tools.SimpleJavaFileObject;

public class ScopeTest {

    private static final String SOURCE_CODE =
            "public class Test {\n" +
            "    private static void test() {\n" +
            "        InvokeOn f = null;\n" +
            "        f.run(x -> { x.correct(); });\n" +
            "    }\n" +
            "    public static final class FooBar {\n" +
            "        public void dontRun() { }\n" +
            "    }\n" +
            "}\n" +
            "class InvokeOn {\n" +
            "    public void run(I i) { }\n" +
            "}\n" +
            "class FooBar {\n" +
            "    public void correct() { }\n" +
            "}\n" +
            "interface I {\n" +
            "    public void run(FooBar f);\n" +
            "}";

    public static void main(String... args) throws Exception {
        verifyLambdaScopeCorrect("");
        verifyLambdaScopeCorrect("package test;");
    }

    private static void verifyLambdaScopeCorrect(final String packageClause) throws Exception {
        JavacTool tool = JavacTool.create();
        JavaFileObject source = new SimpleJavaFileObject(URI.create("mem://Test.java"), Kind.SOURCE) {
            @Override public CharSequence getCharContent(boolean ignoreEncodingErrors) throws IOException {
                return packageClause + SOURCE_CODE;
            }
            @Override public boolean isNameCompatible(String simpleName, Kind kind) {
                return true;
            }
        };
        Iterable<? extends JavaFileObject> fos = Collections.singletonList(source);
        JavacTask task = tool.getTask(null, null, null, new ArrayList<String>(), null, fos);
        final Types types = JavacTypes.instance(((JavacTaskImpl) task).getContext());
        final Trees trees = Trees.instance(task);
        CompilationUnitTree cu = task.parse().iterator().next();

        task.analyze();

        new TreePathScanner<Void, Void>() {
            @Override public Void visitMemberSelect(MemberSelectTree node, Void p) {
                if (node.getIdentifier().contentEquals("correct")) {
                    TypeMirror xType = trees.getTypeMirror(new TreePath(getCurrentPath(), node.getExpression()));
                    Scope scope = trees.getScope(getCurrentPath());
                    for (Element l : scope.getLocalElements()) {
                        if (!l.getSimpleName().contentEquals("x")) continue;
                        if (!types.isSameType(xType, l.asType())) {
                            throw new IllegalStateException("Incorrect variable type in scope: " + l.asType() + "; should be: " + xType);
                        }
                    }
                }
                return super.visitMemberSelect(node, p);
            }
        }.scan(cu, null);
    }
}
