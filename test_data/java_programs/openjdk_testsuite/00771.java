



import javax.tools.*;
import java.io.File;
import java.util.Collections;

public class Test extends ToolTester {

    public boolean success = false;

    class DiagnosticTester implements DiagnosticListener<JavaFileObject> {
        public void report(Diagnostic<? extends JavaFileObject> diagnostic) {
            if (diagnostic.getKind() == Diagnostic.Kind.NOTE) {
                try {
                    
                    
                    diagnostic.getSource().openReader(true).getClass();
                } catch (Exception ex) {
                    throw new AssertionError(ex);
                }
                success = true;
            }
        }
    }

    void test(String... args) throws Exception {
        final Iterable<? extends JavaFileObject> compilationUnits =
            fm.getJavaFileObjects(new File(test_src, "TestMe.java"));
        task = tool.getTask(null, fm, new DiagnosticTester(), null, null, compilationUnits);
        if (!task.call())
            throw new AssertionError("Compilation failed");
        if (!success)
            throw new AssertionError("Did not see a NOTE");
        
        fm.getFileForInput(StandardLocation.PLATFORM_CLASS_PATH,
                           "java.lang",
                           "Object.class").openReader(true).getClass();
        DiagnosticCollector<JavaFileObject> diags = new DiagnosticCollector<JavaFileObject>();
        task = tool.getTask(null, fm, diags, Collections.singleton("-Xlint:all"),
                            null, compilationUnits);
        if (!task.call())
            throw new AssertionError("Compilation failed");
        String msg = diags.getDiagnostics().get(0).getMessage(null);
        long lineno = diags.getDiagnostics().get(0).getLineNumber();
        if (msg.contains(":"+lineno+":"))
            
            throw new AssertionError(msg);
    }

    public static void main(String... args) throws Exception {
        new Test().test(args);
    }

}
