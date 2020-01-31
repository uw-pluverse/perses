



import com.sun.source.tree.*;
import com.sun.source.util.Trees;
import com.sun.tools.javac.api.*;
import com.sun.tools.javac.tree.*;
import com.sun.tools.javac.tree.JCTree.*;
import java.net.URI;
import java.util.Arrays;
import javax.tools.*;

public class T6972327 {

    public static void main(String[] args) throws Exception {
        final String bootPath = System.getProperty("sun.boot.class.path"); 
        final JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        assert tool != null;

        String code = "\n@interface Test {}";

        JavacTaskImpl ct = (JavacTaskImpl) tool.getTask(null, null, null,
            Arrays.asList("-bootclasspath", bootPath, "-Xjcov"), null, Arrays.asList(new MyFileObject(code)));
        CompilationUnitTree cut = ct.parse().iterator().next();
        ClassTree clazz = (ClassTree) cut.getTypeDecls().get(0);
        Trees t = Trees.instance(ct);

        long pos = t.getSourcePositions().getStartPosition(cut, clazz);
        if (pos != code.indexOf(code.trim()))
            throw new IllegalStateException("Unexpected position=" + pos);
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
}
