



import java.io.*;
import java.net.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import javax.tools.*;
import com.sun.tools.javac.file.*;
import com.sun.tools.javac.file.JavacFileManager;
import com.sun.tools.javac.main.JavaCompiler;
import com.sun.tools.javac.main.*;
import com.sun.tools.javac.util.*;
import com.sun.tools.javac.util.List; 


@SupportedAnnotationTypes("*")
public class T6358168 extends AbstractProcessor {
    private static String testClasses = System.getProperty("test.classes");
    private static String testSrc = System.getProperty("test.src");
    private static String self = T6358168.class.getName();

    public static void main(String... args) throws Throwable {

        JavacFileManager fm = new JavacFileManager(new Context(), false, null);
        JavaFileObject f = fm.getFileForInput(testSrc + File.separatorChar + T6358168.class.getName() + ".java");

        try {
            
            testNoAnnotationProcessing(fm, f);

            
            testAnnotationProcessing(fm, f);
        }
        catch (Throwable t) {
            AssertionError e = new AssertionError();
            e.initCause(t);
            throw e;
        }
    }

    static void testNoAnnotationProcessing(JavacFileManager fm, JavaFileObject f) throws Throwable {
        Context context = new Context();
        fm.setContext(context);

        Main compilerMain = new Main("javac", new PrintWriter(System.err, true));
        compilerMain.setOptions(Options.instance(context));
        compilerMain.filenames = new LinkedHashSet<File>();
        compilerMain.processArgs(new String[] { "-d", "." });

        JavaCompiler compiler = JavaCompiler.instance(context);
        compiler.compile(List.of(f));
        try {
            compiler.compile(List.of(f));
            throw new Error("Error: AssertionError not thrown after second call of compile");
        } catch (AssertionError e) {
            System.err.println("Exception from compiler (expected): " + e);
        }
    }

    static void testAnnotationProcessing(JavacFileManager fm, JavaFileObject f) throws Throwable {
        Context context = new Context();
        fm.setContext(context);

        Main compilerMain = new Main("javac", new PrintWriter(System.err, true));
        compilerMain.setOptions(Options.instance(context));
        compilerMain.filenames = new LinkedHashSet<File>();
        compilerMain.processArgs(new String[] {
                                     "-XprintRounds",
                                     "-processorpath", testClasses,
                                     "-processor", self,
                                     "-d", "."});

        JavaCompiler compiler = JavaCompiler.instance(context);
        compiler.initProcessAnnotations(null);
        JavaCompiler compiler2 = compiler.processAnnotations(compiler.enterTrees(compiler.parseFiles(List.of(f))));
        try {
            compiler2.compile(List.of(f));
            throw new Error("Error: AssertionError not thrown after second call of compile");
        } catch (AssertionError e) {
            System.err.println("Exception from compiler (expected): " + e);
        }
    }

    public boolean process(Set<? extends TypeElement> tes, RoundEnvironment renv) {
        return true;
    }
}
