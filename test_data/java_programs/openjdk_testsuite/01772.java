



import java.io.PrintWriter;
import java.io.StringWriter;
import java.nio.file.Paths;

public class ClassLiteralWastesByteTest {

    private static final String assertionErrorMsg =
            "Instead of ldc_w, ldc instruction should have been generated";

    public static void main(String[] args) {
        new ClassLiteralWastesByteTest().run();
    }

    void run() {
        check("-c", Paths.get(System.getProperty("test.classes"),
                "test.class").toString());
    }

    void check(String... params) {
        StringWriter s;
        String out;
        try (PrintWriter pw = new PrintWriter(s = new StringWriter())) {
            com.sun.tools.javap.Main.run(params, pw);
            out = s.toString();
        }
        if (out.contains("ldc_w")) {
            throw new AssertionError(assertionErrorMsg);
        }
    }

}

class test {
    void m() {
        Class<?> aClass = test.class;
    }
}
