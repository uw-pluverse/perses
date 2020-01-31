



import java.io.*;
import java.util.*;
import javax.tools.*;

public class Test {
    public static void main(String[] args) throws Exception {
        new Test().run();
    }

    void run() throws Exception {

        
        compile("A.java");

        File p = new File("p");
        p.mkdirs();
        new File("q/A.class").renameTo(new File("p/A.class"));

        
        String[] out = compile("B.java");
        if (out.length == 0)
            throw new Error("no diagnostics generated");

        String expected = "B.java:6:6: compiler.err.cant.access: p.A, " +
            "(compiler.misc.bad.class.file.header: A.class, " +
            "(compiler.misc.class.file.wrong.class: q.A))";

        if (!out[0].equals(expected)) {
            System.err.println("expected: " + expected);
            System.err.println("   found: " + out[0]);
            throw new Error("test failed");
        }
    }

    String[] compile(String file) {
        String[] options = {
            "-XDrawDiagnostics",
            "-d", ".",
            "-classpath", ".",
            new File(testSrc, file).getPath()
        };

        System.err.println("compile: " + Arrays.asList(options));
        StringWriter sw = new StringWriter();
        PrintWriter out = new PrintWriter(sw);
        int rc = com.sun.tools.javac.Main.compile(options, out);
        out.close();

        String outText = sw.toString();
        System.err.println(outText);

        return sw.toString().split("[\\r\\n]+");
    }

    File testSrc = new File(System.getProperty("test.src", "."));
}
