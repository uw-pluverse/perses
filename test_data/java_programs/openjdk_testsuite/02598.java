
import java.io.*;
import java.util.Set;
import java.util.HashSet;

import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.*;
import javax.lang.model.util.ElementFilter;

import com.sun.source.util.JavacTask;
import com.sun.source.util.TaskEvent;
import com.sun.source.util.TaskListener;
import com.sun.tools.javac.main.JavaCompiler;
import com.sun.tools.javac.processing.JavacProcessingEnvironment;
import com.sun.tools.javac.util.Context;

import static com.sun.tools.javac.comp.CompileStates.CompileState;


@SupportedAnnotationTypes("*")
public class TypeProcOnly extends AbstractProcessor {
    private static final String INDICATOR = "INDICATOR";

    private final AttributionTaskListener listener = new AttributionTaskListener();
    private final Set<Name> elements = new HashSet<Name>();

    @Override
    public final void init(ProcessingEnvironment env) {
        super.init(env);
        JavacTask.instance(env).addTaskListener(listener);
        Context ctx = ((JavacProcessingEnvironment)processingEnv).getContext();
        JavaCompiler compiler = JavaCompiler.instance(ctx);
        compiler.shouldStopPolicyIfNoError = CompileState.max(
                compiler.shouldStopPolicyIfNoError,
                CompileState.FLOW);
    }

    @Override
    public final boolean process(Set<? extends TypeElement> annotations,
            RoundEnvironment roundEnv) {
        for (TypeElement elem : ElementFilter.typesIn(roundEnv.getRootElements())) {
            elements.add(elem.getQualifiedName());
        }
        return false;
    }

    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    private final class AttributionTaskListener implements TaskListener {
        @Override
        public void started(TaskEvent e) { }

        @Override
        public void finished(TaskEvent e) {
            if (e.getKind() != TaskEvent.Kind.ANALYZE)
                return;

            if (!elements.remove(e.getTypeElement().getQualifiedName()))
                return;

            System.out.println(INDICATOR);
        }
    }


    private static File writeTestFile() throws IOException {
        File f = new File("Test.java");
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(f)));
        out.println("class Test { }");
        out.close();
        return f;
    }

    public static void main(String[] args) throws Exception {
        PrintStream prevOut = System.out;

        ByteArrayOutputStream bytes = new ByteArrayOutputStream();
        PrintStream out = new PrintStream(bytes);
        System.setOut(out);

        try {
            File f = writeTestFile();
            com.sun.tools.javac.Main.compile(new String[] {"-proc:only", "-processor", "TypeProcOnly", f.getAbsolutePath()});
        } finally {
            System.setOut(prevOut);
        }

        if (bytes.toString().trim().equals(INDICATOR)) {
            System.out.println("PASSED");
        } else {
            throw new Exception("Processor did not run correctly. Output: " + bytes);
        }
    }
}
