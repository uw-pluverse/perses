



import java.io.*;
import java.util.*;
import javax.annotation.processing.RoundEnvironment;
import javax.annotation.processing.SupportedOptions;
import javax.lang.model.element.TypeElement;
import javax.tools.Diagnostic;

import com.sun.tools.javac.file.FSInfo;
import com.sun.tools.javac.processing.JavacProcessingEnvironment;
import com.sun.tools.javac.util.Context;

@SupportedOptions("expect")
public class T7018098 extends JavacTestingAbstractProcessor {
    public static void main(String... args) throws Exception {
        new T7018098().run();
    }

    static File testDir = new File("T7018098.dir");

    void run() throws Exception {
        String myName = T7018098.class.getSimpleName();
        File testSrc = new File(System.getProperty("test.src"));
        File file = new File(testSrc, myName + ".java");

        _assert(!testDir.exists());

        compile(
            "-proc:only",
            "-processor", myName,
            "-Aexpect=false",
            file.getPath());

        testDir.mkdirs();
        _assert(testDir.exists());

        compile(
            "-proc:only",
            "-processor", myName,
            "-Aexpect=true",
            file.getPath());
    }

    void _assert(boolean cond) {
        if (!cond)
            throw new AssertionError();
    }

    void compile(String... args) throws Exception {
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        int rc = com.sun.tools.javac.Main.compile(args, pw);
        pw.close();
        String out = sw.toString();
        if (!out.isEmpty())
            System.err.println(out);
        if (rc != 0)
            throw new Exception("compilation failed unexpectedly: rc=" + rc);
    }

    

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        Context context = ((JavacProcessingEnvironment) processingEnv).getContext();
        FSInfo fsInfo = context.get(FSInfo.class);

        round++;
        if (round == 1) {
            boolean expect = Boolean.valueOf(options.get("expect"));
            checkEqual("cache result", fsInfo.isDirectory(testDir), expect);
            initialFSInfo = fsInfo;
        } else {
            checkEqual("fsInfo", fsInfo, initialFSInfo);
        }

        return true;
    }

    <T> void checkEqual(String label, T actual, T expected) {
        if (actual != expected)
            messager.printMessage(Diagnostic.Kind.ERROR,
                    "Unexpected value for " + label
                    + "; expected: " + expected
                    + "; found: " + actual);
    }

    int round = 0;
    FSInfo initialFSInfo;
}
