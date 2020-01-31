



import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.tools.*;
import com.sun.source.util.*;
import com.sun.tools.javac.api.*;
import static javax.lang.model.util.ElementFilter.*;


@SupportedAnnotationTypes("*")
public class T6439826 extends AbstractProcessor {
    public static void main(String... args) {
        String testSrc = System.getProperty("test.src", ".");
        String testClasses = System.getProperty("test.classes");
        JavacTool tool = JavacTool.create();
        MyDiagListener dl = new MyDiagListener();
        StandardJavaFileManager fm = tool.getStandardFileManager(dl, null, null);
        Iterable<? extends JavaFileObject> files =
            fm.getJavaFileObjectsFromFiles(Arrays.asList(new File(testSrc, T6439826.class.getName()+".java")));
        Iterable<String> opts = Arrays.asList("-proc:only",
                                              "-processor", "T6439826",
                                              "-processorpath", testClasses);
        StringWriter out = new StringWriter();
        JavacTask task = tool.getTask(out, fm, dl, opts, null, files);
        task.call();
        String s = out.toString();
        System.err.print(s);
        
        
        
        System.err.println(dl.count + " diagnostics; " + s.length() + " characters");
        if (dl.count != 2 || s.length() != 0)
            throw new AssertionError("unexpected output from compiler");
    }

    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        Set<? extends TypeElement> elems = typesIn(roundEnv.getRootElements());
        for (TypeElement e: elems) {
            if (e.getSimpleName().toString().equals(T6439826.class.getName()))
                writeBadFile();
        }
        return false;
    }

    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    private void writeBadFile() {
        Filer filer = processingEnv.getFiler();
        Messager messager = processingEnv.getMessager();
        try {
            Writer out = filer.createSourceFile("Foo").openWriter();
            out.write("class Foo #"); 
            out.close();
        } catch (IOException e) {
            messager.printMessage(Diagnostic.Kind.ERROR, e.toString());
        }
    }

    static class MyDiagListener implements DiagnosticListener {
        public void report(Diagnostic d) {
            System.err.println(d);
            count++;
        }

        public int count;
    }
}
