



import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.Writer;
import java.util.Arrays;
import java.util.Collections;
import java.util.Map;
import java.util.Set;
import javax.annotation.processing.AbstractProcessor;
import javax.annotation.processing.Filer;
import javax.annotation.processing.Messager;
import javax.annotation.processing.RoundEnvironment;
import javax.annotation.processing.SupportedAnnotationTypes;
import javax.annotation.processing.SupportedOptions;
import javax.annotation.processing.SupportedSourceVersion;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.TypeElement;
import javax.tools.Diagnostic.Kind;
import javax.tools.JavaCompiler;
import javax.tools.JavaCompiler.CompilationTask;
import javax.tools.StandardLocation;
import javax.tools.ToolProvider;

public class T7068437 {
    public static void main(String[] args) throws Exception {
        new T7068437().run();
    }

    void run() throws Exception {
        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        System.err.println("using " + compiler.getClass()
                + " from " + compiler.getClass().getProtectionDomain().getCodeSource());

        CompilationTask task = compiler.getTask(null, null, null,
                Collections.singleton("-proc:only"),
                Collections.singleton("java.lang.Object"),
                null);
        task.setProcessors(Collections.singleton(new Proc()));
        check("compilation", task.call());

        task = compiler.getTask(null, null, null,
                Arrays.asList("-proc:only", "-AexpectFile"),
                Collections.singleton("java.lang.Object"),
                null);
        task.setProcessors(Collections.singleton(new Proc()));
        check("compilation", task.call());
    }

    void check(String msg, boolean ok) {
        System.err.println(msg + ": " + (ok ? "ok" : "failed"));
        if (!ok)
            throw new AssertionError(msg);
    }

    @SupportedAnnotationTypes("*")
    @SupportedOptions("expectFile")
    private static class Proc extends AbstractProcessor {
        int count;

        @Override
        public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
            if (roundEnv.processingOver() || count++ > 0) {
                return false;
            }

            Filer filer = processingEnv.getFiler();
            Messager messager = processingEnv.getMessager();
            Map<String, String> options = processingEnv.getOptions();
                System.err.println(options);
            boolean expectFile = options.containsKey("expectFile");

            System.err.println("running Proc: expectFile=" + expectFile);

            boolean found;
            try {
                messager.printMessage(Kind.NOTE, "found previous content of length " +
                        filer.getResource(StandardLocation.SOURCE_OUTPUT, "p", "C.java").getCharContent(false).length());
                found = true;
            } catch (FileNotFoundException x) {
                messager.printMessage(Kind.NOTE, "not previously there");
                found = false;
            } catch (IOException x) {
                messager.printMessage(Kind.ERROR, "while reading: " + x);
                found = false;
            }

            if (expectFile && !found) {
                messager.printMessage(Kind.ERROR, "expected file but file not found");
            }

            try {
                Writer w = filer.createSourceFile("p.C").openWriter();
                w.write("/* hello! */ package p; class C {}");
                w.close();
                messager.printMessage(Kind.NOTE, "wrote new content");
            } catch (IOException x) {
                messager.printMessage(Kind.ERROR, "while writing: " + x);
            }

            return true;
        }

        @Override
        public SourceVersion getSupportedSourceVersion() {
            return SourceVersion.latest();
        }
    }
}
