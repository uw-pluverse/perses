



import java.io.*;
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
public class T6358166 extends AbstractProcessor {
    public static void main(String... args) throws Throwable {
        String self = T6358166.class.getName();

        String testSrc = System.getProperty("test.src");

        JavacFileManager fm = new JavacFileManager(new Context(), false, null);
        JavaFileObject f = fm.getFileForInput(testSrc + File.separatorChar + self + ".java");

        test(fm, f, "-verbose", "-d", ".");

        test(fm, f, "-verbose", "-d", ".", "-XprintRounds", "-processorpath", ".", "-processor", self);
    }

    static void test(JavacFileManager fm, JavaFileObject f, String... args) throws Throwable {
        Context context = new Context();
        fm.setContext(context);

        Main compilerMain = new Main("javac", new PrintWriter(System.err, true));
        compilerMain.setOptions(Options.instance(context));
        compilerMain.filenames = new LinkedHashSet<File>();
        compilerMain.processArgs(args);

        JavaCompiler c = JavaCompiler.instance(context);

        c.compile(List.of(f));

        if (c.errorCount() != 0)
            throw new AssertionError("compilation failed");

        long msec = c.elapsed_msec;
        if (msec < 0 || msec > 5 * 60 * 1000) 
            throw new AssertionError("elapsed time is suspect: " + msec);
    }

    public boolean process(Set<? extends TypeElement> tes, RoundEnvironment renv) {
        return true;
    }
}
