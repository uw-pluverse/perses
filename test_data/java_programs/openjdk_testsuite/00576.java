



import com.sun.source.tree.CompilationUnitTree;
import com.sun.source.tree.IdentifierTree;
import com.sun.source.tree.VariableTree;
import com.sun.source.util.TreePathScanner;
import com.sun.source.util.Trees;
import com.sun.tools.javac.api.JavacTaskImpl;
import java.io.IOException;
import java.net.URI;
import java.util.Arrays;
import javax.lang.model.element.Element;
import javax.lang.model.element.ElementKind;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;


public class T6993301 {
    public static void main(String... args) throws Exception {
        new T6993301().testExceptionParameterCorrectKind();
    }

    static class MyFileObject extends SimpleJavaFileObject {
        private String text;
        public MyFileObject(String text) {
            super(URI.create("myfo:/Test.java"), JavaFileObject.Kind.SOURCE);
            this.text = text;
        }
        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return text;
        }
    }

    public void testExceptionParameterCorrectKind() throws IOException {
        final String bootPath = System.getProperty("sun.boot.class.path");
        final JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        assert tool != null;

        String code = "package test; public class Test { { try { } catch (NullPointerException ex) {} } }";

        final JavacTaskImpl ct = (JavacTaskImpl)tool.getTask(null, null, null,
                Arrays.asList("-bootclasspath",  bootPath),
                null, Arrays.asList(new MyFileObject(code)));
        CompilationUnitTree cut = ct.parse().iterator().next();

        ct.analyze();

        new TreePathScanner<Void, Void>() {
            @Override
            public Void visitVariable(VariableTree node, Void p) {
                Element el = Trees.instance(ct).getElement(getCurrentPath());

                assertNotNull(el);
                assertEquals(ElementKind.EXCEPTION_PARAMETER, el.getKind());

                return super.visitVariable(node, p);
            }
        }.scan(cut, null);
    }

    private void assertNotNull(Object o) {
        if (o == null)
            throw new AssertionError();
    }

    private <T> void assertEquals(T expected, T actual) {
        if (expected == null ? actual == null : expected.equals(actual))
            return;
        throw new AssertionError("expected: " + expected + ", actual: " + actual);
    }

}
