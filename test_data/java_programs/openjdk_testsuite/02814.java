

import java.io.File;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.ArrayList;
import java.util.List;



public class T6873849 {
    public static void main(String... args) throws Exception {
        new T6873849().run();
    }

    public void run() throws Exception {
        test(null, "- compiler.note.unchecked.filename: T6873849.java" + newline +
                    "- compiler.note.unchecked.recompile" + newline);
        test("-XDsuppressNotes", "");
    }

    void test(String opt, String expect) throws Exception {
        List<String> args = new ArrayList<String>();
        if (opt != null)
            args.add(opt);
        args.add("-d");
        args.add(testClasses.getPath());
        args.add("-XDrawDiagnostics");
        args.add(new File(testSrc, "T6873849.java").getPath());
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        System.err.println("compile: " + args);
        int rc = com.sun.tools.javac.Main.compile(args.toArray(new String[args.size()]), pw);
        pw.close();
        String out = sw.toString();
        System.out.println(out);
        if (rc != 0)
            throw new Exception("compilation failed unexpectedly");
        if (!out.equals(expect))
            throw new Exception("unexpected output from compiler");
    }

    void m(List t) {
        
        t.add(new Object());
    }

    private File testSrc = new File(System.getProperty("test.src", "."));
    private File testClasses = new File(System.getProperty("test.classes", "."));
    private String newline = System.getProperty("line.separator");
}
