



import java.io.*;
import java.util.*;

public class T6986895 {
    public static void main(String... args) throws Exception {
        new T6986895().run();
    }

    String noSourceFiles = "no source files";
    String noSourceFilesOrClasses = "no source files or class names";

    void run() throws Exception {
        Locale prev = Locale.getDefault();
        try {
            Locale.setDefault(Locale.ENGLISH);
            test(noSourceFiles,           "-Werror");
            test(noSourceFilesOrClasses,  "-Werror", "-Xprint");
        } finally {
            Locale.setDefault(prev);
        }
    }

    void test(String expect, String... args) throws Exception {
        System.err.println("Test " + expect + ": " + Arrays.asList(args));
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        int rc = com.sun.tools.javac.Main.compile(args, pw);
        pw.close();
        System.err.println("compilation failed; rc=" + rc);
        String out = sw.toString();
        if (!out.isEmpty())
            System.err.println(out);
        if (!out.contains(expect))
            throw new Exception("expected text not found: " + expect);
        System.err.println();
    }
}
