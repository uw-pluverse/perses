
import java.io.PrintWriter;
import java.io.StringWriter;





public class Option_J_At_Test {
    public static void main(String... args) throws Exception {
        new Option_J_At_Test().run();
    }

    void run() throws Exception {
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        String[] help = { "-help" };
        int rc = com.sun.tools.javac.Main.compile(help, pw);
        pw.flush();
        String out = sw.toString();
        System.out.println(out);
        check(out, "-J<flag>",     true);
        check(out, "-J <flag>",    false);
        check(out, "@<filename>",  true);
        check(out, "@ <filename>", false);
        if (errors > 0)
            throw new Exception(errors + " errors found");
    }

    void check(String out, String text, boolean expect) {
        if (out.contains(text) != expect) {
            if (expect)
                error("expected string not found: " + text);
            else
                error("unexpected string found: " + text);
        }
    }

    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    int errors;
}
