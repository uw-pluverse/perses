



import com.sun.source.util.JavacTask;
import com.sun.source.util.TaskEvent;
import com.sun.source.util.TaskListener;
import com.sun.tools.javac.api.JavacTool;
import com.sun.tools.javac.file.JavacFileManager;
import com.sun.tools.javac.util.Context;
import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Set;
import javax.annotation.processing.AbstractProcessor;
import javax.annotation.processing.Messager;
import javax.annotation.processing.RoundEnvironment;
import javax.annotation.processing.SupportedAnnotationTypes;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.TypeElement;
import javax.tools.Diagnostic;
import javax.tools.JavaFileObject;
import javax.tools.StandardJavaFileManager;
import javax.tools.StandardLocation;
import javax.tools.ToolProvider;

@SupportedAnnotationTypes("*")
public class TestClose2 extends AbstractProcessor implements TaskListener {

    public static void main(String... args) throws Exception {
        new TestClose2().run();
    }

    void run() throws IOException {
        File testSrc = new File(System.getProperty("test.src"));
        File testClasses = new File(System.getProperty("test.classes"));

        JavacTool tool = (JavacTool) ToolProvider.getSystemJavaCompiler();
        final ClassLoader cl = getClass().getClassLoader();
        Context c = new Context();
        StandardJavaFileManager fm = new JavacFileManager(c, true, null) {
            @Override
            protected ClassLoader getClassLoader(URL[] urls) {
                return new URLClassLoader(urls, cl) {
                    @Override
                    public void close() throws IOException {
                        System.err.println(getClass().getName() + " closing");
                        TestClose2.this.closedCount++;
                        TestClose2.this.closedIsLast = true;
                        super.close();
                    }
                };
            }
        };

        fm.setLocation(StandardLocation.CLASS_OUTPUT,
                Collections.singleton(new File(".")));
        fm.setLocation(StandardLocation.ANNOTATION_PROCESSOR_PATH,
                Collections.singleton(testClasses));
        Iterable<? extends JavaFileObject> files =
                fm.getJavaFileObjects(new File(testSrc, TestClose2.class.getName() + ".java"));
        List<String> options = Arrays.asList(
                "-processor", TestClose2.class.getName());

        JavacTask task = tool.getTask(null, fm, null, options, null, files);
        task.setTaskListener(this);

        if (!task.call())
            throw new Error("compilation failed");

        if (closedCount == 0)
            throw new Error("no closing message");
        else if (closedCount > 1)
            throw new Error(closedCount + " closed messages");

        if (!closedIsLast)
            throw new Error("closing message not last");
    }

    

    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        Messager messager = processingEnv.getMessager();
        messager.printMessage(Diagnostic.Kind.NOTE, "processing");
        return true;
    }

    

    @Override
    public void started(TaskEvent e) {
        System.err.println("Started: " + e);
        closedIsLast = false;
    }

    @Override
    public void finished(TaskEvent e) {
        System.err.println("Finished: " + e);
        closedIsLast = false;
    }

    

    int closedCount = 0;
    boolean closedIsLast = false;
}
