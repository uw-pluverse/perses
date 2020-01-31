



import java.net.URI;
import java.util.Arrays;
import javax.tools.*;
import static javax.tools.JavaFileObject.Kind.*;


public class T6437138 {
    static class JFO extends SimpleJavaFileObject {
        public JFO(URI uri, JavaFileObject.Kind kind) {
            super(uri, kind);
        }
        
    }

    public static void main(String... arg) throws Exception {
        try {
            JavaCompiler javac = ToolProvider.getSystemJavaCompiler();
            JavaFileObject jfo = new JFO(new URI("JFOTest04.java"),SOURCE);
            JavaCompiler.CompilationTask ct = javac.getTask(null,null,null,null,
                        null, Arrays.asList(jfo));
            ct.call();
            throw new Exception("no exception thrown by JavaCompiler.CompilationTask");
        } catch (RuntimeException e) {
            if (e.getCause() instanceof UnsupportedOperationException) {
                System.err.println("RuntimeException(UnsupportedOperationException) caught as expected");
                return;
            }
            throw new Exception("unexpected exception caught", e);
        }
    }
}

