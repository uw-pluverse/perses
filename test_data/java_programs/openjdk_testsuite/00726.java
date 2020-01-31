



import javax.tools.*;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import java.util.*;
import java.io.*;

public class T6406133 extends ToolTester {

    List<Locale> locales = Arrays.asList(Locale.US, Locale.JAPAN, Locale.CHINA);

    class DiagnosticTester implements DiagnosticListener<JavaFileObject> {
        Locale locale;
        String result;

        DiagnosticTester(Locale locale) {
            this.locale = locale;
        }
        public void report(Diagnostic<? extends JavaFileObject> diagnostic) {
            result = diagnostic.getMessage(locale); 
        }
    }

    class ProcessorTester extends AbstractProcessor {

        Locale locale;

        public Set<String> getSupportedAnnotationTypes() {
            return new HashSet<String>(Arrays.asList("*"));
        }

        public void init(ProcessingEnvironment env) {
            locale = env.getLocale();
        }

        public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
            return true;
        }
    }

    void compare(Locale loc1, Locale loc2, boolean useListener) {
        String res1 = exec(useListener, loc1);
        String res2 = exec(useListener, loc2);
        boolean success = (loc1.equals(loc2) && res1.equals(res2)) ||
                          (!loc1.equals(loc2) && !res1.equals(res2));
        if (!success)
            throw new AssertionError("Error in diagnostic localization");
    }

    String exec(boolean useListener, Locale locale) {
        final Iterable<? extends JavaFileObject> compilationUnits =
            fm.getJavaFileObjects(new File(test_src, "Erroneous.java"));
        StringWriter pw = new StringWriter();
        DiagnosticTester listener = useListener ? new DiagnosticTester(locale) : null;
        ProcessorTester processor = new ProcessorTester();
        task = tool.getTask(pw, fm, listener, null, null, compilationUnits);
        task.setProcessors(Arrays.asList(processor));
        task.setLocale(locale); 
        task.call();
        if (!processor.locale.equals(locale))
            throw new AssertionError("Error in diagnostic localization during annotation processing");
        String res = useListener ? listener.result : pw.toString();
        System.err.println("[locale:"+ locale + ", listener:" + useListener + "] " +res);
        return res;
    }

    void test() {
        for (Locale l1 : locales) {
            for (Locale l2 : locales) {
                compare(l1, l2, true);
                compare(l1, l2, false);
            }
        }
    }

    public static void main(String... args) throws Exception {
        new T6406133().test();
    }
}
