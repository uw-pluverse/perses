



import java.io.*;
import java.util.*;
import javax.annotation.processing.RoundEnvironment;
import javax.lang.model.element.TypeElement;
import javax.lang.model.util.ElementFilter;
import javax.tools.*;

import p.NestedExamples;

public class Test extends JavacTestingAbstractProcessor {
    public static void main(String... args) throws Exception {
        new Test().run();
    }

    void run() throws Exception {
        NestedExamples e = new NestedExamples();
        List<String> names = getNames(e.getClasses());
        test(names);
        test(reverse(names));
        names = Arrays.asList(e.getClassNames());
        test(names);
        test(reverse(names));

        if (errors > 0)
            throw new RuntimeException(errors + " errors occurred");
    }

    List<String> getNames(Class<?>[] classes) {
        List<String> names = new ArrayList<String>();
        for (Class<?> c: classes)
            names.add(c.getName());
        return names;
    }

    void test(List<String> names) throws Exception {
        System.err.println("test: " + names);
        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager fm = compiler.getStandardFileManager(null, null, null);
        File testClasses = new File(System.getProperty("test.classes"));
        fm.setLocation(StandardLocation.CLASS_PATH, Arrays.asList(testClasses));
        JavaCompiler.CompilationTask task = compiler.getTask(
                null, null, null, Arrays.asList("-proc:only"), names, null);
        task.setProcessors(Arrays.asList(new Test()));
        boolean ok = task.call();
        if (!ok)
            error("compilation failed");
        System.err.println();
    }

    <T> List<T> reverse(List<T> list) {
        List<T> newList = new ArrayList<T>(list);
        Collections.reverse(newList);
        return newList;
    }

    int errors = 0;

    void error(String msg) {
        System.out.println("Error: " + msg);
        errors++;
    }

    

    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        if (!roundEnv.processingOver()) {
            for (TypeElement typeElt : ElementFilter.typesIn(roundEnv.getRootElements())) {
                messager.printMessage(Diagnostic.Kind.NOTE, "processing " + typeElt);
            }
        }
        return true;
    }
}
