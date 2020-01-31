




import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import javax.tools.*;

public class T7022337 extends JavacTestingAbstractProcessor {
    public static void main(String... args) throws Exception {
        new T7022337().run();
    }

    void run() throws Exception {
        String myName = T7022337.class.getSimpleName();
        File testSrc = new File(System.getProperty("test.src"));
        File file = new File(testSrc, myName + ".java");

        String out = compile(
            "-XDrawDiagnostics",
            "-d", ".",
            "-processor", myName,
            "-source", "6", 
            file.getPath());

        int count = 0;
        for (String line: out.split("[\r\n]+")) {
            if (line.contains("compiler.warn.source.no.bootclasspath"))
                count++;
        }
        if (count != 1)
            throw new Exception("unexpected number of warnings found: " + count + ", expected: 1");
    }

    String compile(String... args) throws Exception {
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        int rc = com.sun.tools.javac.Main.compile(args, pw);
        pw.close();
        String out = sw.toString();
        if (!out.isEmpty())
            System.err.println(out);
        if (rc != 0)
            throw new Exception("compilation failed unexpectedly: rc=" + rc);
        return out;
    }

    

    int round = 0;

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        round++;

        final int MAXROUNDS = 3;
        if (round < MAXROUNDS)
            generate("Gen" + round);

        return true;
    }

    void generate(String name) {
        try {
            JavaFileObject fo = filer.createSourceFile(name);
            Writer out = fo.openWriter();
            try {
                out.write("class " + name + " { }");
            } finally {
                out.close();
            }
        } catch (IOException e) {
            throw new Error(e);
        }
    }
}
