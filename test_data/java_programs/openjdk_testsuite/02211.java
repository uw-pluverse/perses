
import java.io.PrintWriter;
import java.io.StringWriter;
import java.nio.file.Paths;





public class EmptyFinallyTest {
    private static final String assertionErrorMsg =
            "No \"Exception table\" should be generated in this case";

    public static void main(String[] args) {
        new EmptyFinallyTest().run();
    }

    void run() {
        check("-c", Paths.get(System.getProperty("test.classes"),
                "EmptyFinally.class").toString());
    }

    void check(String... params) {
        StringWriter s;
        String out;
        try (PrintWriter pw = new PrintWriter(s = new StringWriter())) {
            com.sun.tools.javap.Main.run(params, pw);
            out = s.toString();
        }
        if (out.contains("Exception table")) {
            throw new AssertionError(assertionErrorMsg);
        }
    }
}

class EmptyFinally {
    void m() {
        try {
            System.out.println("EMPTY TRY!");
        } finally {}
    }
}
