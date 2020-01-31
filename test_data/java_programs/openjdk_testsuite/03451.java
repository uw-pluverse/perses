



import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Collections;
import java.util.Set;
import javax.annotation.processing.AbstractProcessor;
import javax.annotation.processing.RoundEnvironment;
import javax.annotation.processing.SupportedAnnotationTypes;
import javax.annotation.processing.SupportedSourceVersion;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.TypeElement;
import javax.tools.Diagnostic;
import javax.tools.JavaCompiler;
import javax.tools.ToolProvider;

public class T7159016 {
    public static void main(String[] args) throws Exception {
        File src = new File("C.java");
        Writer w = new FileWriter(src);
        try {
            w.write("import static p.Generated.m;\nclass C { {m(); } }\n");
            w.flush();
        } finally {
            w.close();
        }
        JavaCompiler jc = ToolProvider.getSystemJavaCompiler();
        JavaCompiler.CompilationTask task = jc.getTask(null, null, null, null, null,
                                                       jc.getStandardFileManager(null, null, null).getJavaFileObjects(src));
        task.setProcessors(Collections.singleton(new Proc()));
        if (!task.call()) {
            throw new Error("Test failed");
        }
    }

    private static class Proc extends JavacTestingAbstractProcessor {
        int written;
        @Override public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
            if (roundEnv.processingOver() || written++ > 0) {
                return false;
            }
            messager.printMessage(Diagnostic.Kind.NOTE, "writing Generated.java");
            try {
                Writer w = processingEnv.getFiler().createSourceFile("p.Generated").openWriter();
                try {
                    w.write("package p; public class Generated { public static void m() { } }");
                } finally {
                    w.close();
                }
            } catch (IOException x) {
                messager.printMessage(Diagnostic.Kind.ERROR, x.toString());
            }
            return true;
        }
    }
}
