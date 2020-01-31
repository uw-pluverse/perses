



import com.sun.source.util.JavacTask;
import com.sun.tools.javac.code.Symbol;
import com.sun.tools.javac.code.Types;
import com.sun.tools.javac.file.JavacFileManager;
import com.sun.tools.javac.util.Context;

import com.sun.tools.javac.code.Symbol.*;

import java.io.IOException;
import java.net.URI;
import java.util.Arrays;
import java.util.List;
import javax.lang.model.element.Element;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;

import static javax.tools.JavaFileObject.Kind;

public class ImplementationCacheTest {

    static class SourceFile extends SimpleJavaFileObject {

        final String source = "interface I { void m(); }\n" +
                              "class A implements I { public void m() {} }\n" +
                              "class B extends A { }\n";

        public SourceFile() {
            super(URI.create("test.java"), Kind.SOURCE);
        }

        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return source;
        }
    }

    public static void main(String[] args) throws IOException {
        List<? extends JavaFileObject> files = Arrays.asList(new SourceFile());
        JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        JavacTask ct = (JavacTask)tool.getTask(null, null, null, null, null, files);
        Context ctx = new Context();
        JavacFileManager.preRegister(ctx);
        checkImplementationCache(ct.analyze(), Types.instance(ctx));
    }

    static void checkImplementationCache(Iterable<? extends Element> elements, Types types) {
        if (types == null) {
            throw new AssertionError("problems initializing Types");
        }

        Symbol a = null;
        Symbol b = null;
        Symbol i = null;

        for (Element e : elements) {
            if (e.getSimpleName().contentEquals("A")) {
                a = (Symbol)e;
            } else if (e.getSimpleName().contentEquals("B")) {
                b = (Symbol)e;
            } else if (e.getSimpleName().contentEquals("I")) {
                i = (Symbol)e;
            }
        }

        if (a == null || b == null || i == null) {
            throw new AssertionError("missing class");
        }

        MethodSymbol I_m = null;

        for (Symbol sym : i.members().getElements()) {
            if (sym.name.contentEquals("m")) {
                I_m = (MethodSymbol)sym;
            }
        }

        if (I_m == null) {
            throw new AssertionError("missing method m() in scope of interface I");
        }

        Symbol impl = I_m.implementation((TypeSymbol)b, types, true);

        if (impl == null || impl.owner != a) {
            throw new AssertionError("wrong implementation for m() in B");
        }

        b.members().enter(I_m.clone(b));

        Symbol newImpl = I_m.implementation((TypeSymbol)b, types, true);

        if (newImpl == impl) {
            throw new AssertionError("stale implementation for m() in B");
        }

        if (newImpl == null || newImpl.owner != b) {
            throw new AssertionError("wrong implementation for m() in B");
        }
    }
}
