



import javax.tools.ToolProvider;

import com.sun.tools.javac.api.JavacTaskImpl;
import com.sun.tools.javac.code.Symbol.CompletionFailure;
import com.sun.tools.javac.main.JavaCompiler;

public class T6400303 {
    public static void main(String... args) {
        javax.tools.JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        JavacTaskImpl task = (JavacTaskImpl)tool.getTask(null, null, null, null, null, null);
        JavaCompiler compiler = JavaCompiler.instance(task.getContext());
        try {
            compiler.resolveIdent("Test$1").complete();
        } catch (CompletionFailure ex) {
            System.err.println("Got expected completion failure: " + ex.getLocalizedMessage());
            return;
        }
        throw new AssertionError("No error reported");
    }
}
