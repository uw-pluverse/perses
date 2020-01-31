



import com.sun.source.util.JavacTask;
import com.sun.source.util.TaskEvent;
import com.sun.source.util.TaskListener;
import com.sun.tools.javac.api.ClientCodeWrapper.Trusted;
import com.sun.tools.javac.api.BasicJavacTask;
import com.sun.tools.javac.api.JavacTool;
import com.sun.tools.javac.processing.JavacProcessingEnvironment;
import com.sun.tools.javac.util.Context;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.lang.reflect.Field;
import java.net.URI;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import javax.annotation.processing.ProcessingEnvironment;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.StandardJavaFileManager;
import javax.tools.StandardLocation;
import javax.tools.ToolProvider;



@Trusted 
public class TestClose implements TaskListener {
    public static final String annoProc =
        "import java.util.*;\n" +
        "import javax.annotation.processing.*;\n" +
        "import javax.lang.model.*;\n" +
        "import javax.lang.model.element.*;\n" +
        "import com.sun.source.util.*;\n" +
        "import com.sun.tools.javac.processing.*;\n" +
        "import com.sun.tools.javac.util.*;\n" +
        "@SupportedAnnotationTypes(\"*\")\n" +
        "public class AnnoProc extends AbstractProcessor {\n" +
        "    @Override\n" +
        "    public SourceVersion getSupportedSourceVersion() {\n" +
        "        return SourceVersion.latest();\n" +
        "    }\n" +
        "    @Override\n" +
        "    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {\n" +
        "        System.out.println(\"in AnnoProc.process\");\n" +
        "        final ClassLoader cl = getClass().getClassLoader();\n" +
        "        if (roundEnv.processingOver()) {\n" +
        "            TestClose.add(processingEnv, new Runnable() {\n" +
        "                public void run() {\n" +
        "                    System.out.println(getClass().getName() + \": run()\");\n" +
        "                    try {\n" +
        "                        cl.loadClass(\"Callback\")\n" +
        "                            .asSubclass(Runnable.class)\n" +
        "                            .newInstance()\n" +
        "                            .run();\n" +
        "                    } catch (ReflectiveOperationException e) {\n" +
        "                        throw new Error(e);\n" +
        "                    }\n" +
        "                }\n" +
        "            });\n" +
        "        }\n" +
        "        return true;\n" +
        "    }\n" +
        "}\n";

    public static final String callback =
        "public class Callback implements Runnable {\n" +
        "    public void run() {\n" +
        "        System.out.println(getClass().getName() + \": run()\");\n" +
        "    }\n" +
        "}";

    public static void main(String... args) throws Exception {
        new TestClose().run();
    }

    void run() throws IOException {
        JavacTool tool = (JavacTool) ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager fm = tool.getStandardFileManager(null, null, null);

        File classes = new File("classes");
        classes.mkdirs();
        File extraClasses = new File("extraClasses");
        extraClasses.mkdirs();

        System.out.println("compiling classes to extraClasses");
        {   
            fm.setLocation(StandardLocation.CLASS_OUTPUT,
                    Collections.singleton(extraClasses));
            List<? extends JavaFileObject> files = Arrays.asList(
                    new MemFile("AnnoProc.java", annoProc),
                    new MemFile("Callback.java", callback));
            JavacTask task = tool.getTask(null, fm, null, null, null, files);
            check(task.call());
        }

        System.out.println("compiling dummy to classes with anno processor");
        {   
            PrintStream prev = System.out;
            String out;
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            try (PrintStream ps = new PrintStream(baos)) {
                System.setOut(ps);
                File testClasses = new File(System.getProperty("test.classes"));
                fm.setLocation(StandardLocation.CLASS_OUTPUT,
                        Collections.singleton(classes));
                fm.setLocation(StandardLocation.ANNOTATION_PROCESSOR_PATH,
                        Arrays.asList(extraClasses, testClasses));
                List<? extends JavaFileObject> files = Arrays.asList(
                        new MemFile("my://dummy", "class Dummy { }"));
                List<String> options = Arrays.asList("-processor", "AnnoProc");
                JavacTask task = tool.getTask(null, fm, null, options, null, files);
                task.setTaskListener(this);
                check(task.call());
            } finally {
                System.setOut(prev);
                out = baos.toString();
                if (!out.isEmpty())
                    System.out.println(out);
            }
            check(out.contains("AnnoProc$1: run()"));
            check(out.contains("Callback: run()"));
        }
    }

    @Override
    public void started(TaskEvent e) {
        System.out.println("Started: " + e);
    }

    @Override
    public void finished(TaskEvent e) {
        System.out.println("Finished: " + e);
        if (e.getKind() == TaskEvent.Kind.ANALYZE) {
            for (Runnable r: runnables) {
                System.out.println("running " + r);
                r.run();
            }
        }
    }

    void check(boolean b) {
        if (!b)
            throw new AssertionError();
    }

    public static void add(ProcessingEnvironment env, Runnable r) {
        try {
            JavacTask task = JavacTask.instance(env);
            TaskListener l = ((BasicJavacTask) task).getTaskListeners().iterator().next();
            
            
            
            
            
            
            
            
            Field f = l.getClass().getField("runnables");
            @SuppressWarnings("unchecked")
            List<Runnable> runnables = (List<Runnable>) f.get(l);
            runnables.add(r);
        } catch (Throwable t) {
            t.printStackTrace();
        }
    }

    public List<Runnable> runnables = new ArrayList<>();

    class MemFile extends SimpleJavaFileObject {
        public final String text;

        MemFile(String name, String text) {
            super(URI.create(name), JavaFileObject.Kind.SOURCE);
            this.text = text;
        }

        @Override
        public String getName() {
            return uri.toString();
        }

        @Override
        public String getCharContent(boolean ignoreEncodingErrors) {
            return text;
        }
    }
}
