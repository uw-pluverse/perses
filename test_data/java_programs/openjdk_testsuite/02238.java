



import java.io.File;
import java.io.IOException;
import java.io.Writer;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import javax.tools.Diagnostic;
import javax.tools.DiagnosticCollector;
import javax.tools.JavaCompiler;
import javax.tools.JavaCompiler.CompilationTask;
import javax.tools.JavaFileObject;
import javax.tools.StandardJavaFileManager;
import javax.tools.ToolProvider;

public class T6458823 {
    public static void main(String[] args) throws Exception {
        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        if (compiler == null) {
            throw new RuntimeException("can't get javax.tools.JavaCompiler!");
        }
        DiagnosticCollector<JavaFileObject> diagColl =
            new DiagnosticCollector<JavaFileObject>();
        StandardJavaFileManager fm = compiler.getStandardFileManager(null, null, null);
        List<String> options = new ArrayList<String>();
        options.add("-processor");
        options.add("MyProcessor");
        options.add("-proc:only");
        List<File> files = new ArrayList<File>();
        files.add(new File(T6458823.class.getResource("TestClass.java").toURI()));
        final CompilationTask task = compiler.getTask(null, fm, diagColl,
            options, null, fm.getJavaFileObjectsFromFiles(files));
        task.call();
        int diagCount = 0;
        for (Diagnostic<? extends JavaFileObject> diag : diagColl.getDiagnostics()) {
            if (diag.getKind() != Diagnostic.Kind.WARNING) {
                throw new AssertionError("Only warnings expected");
            }
            System.out.println(diag);
            if (diag.getPosition() == Diagnostic.NOPOS) {
                throw new AssertionError("No position info in message");
            }
            if (diag.getSource() == null) {
                throw new AssertionError("No source info in message");
            }
            diagCount++;
        }
        if (diagCount != 2) {
            throw new AssertionError("unexpected number of warnings: " +
                diagCount + ", expected: 2");
        }
    }
}
