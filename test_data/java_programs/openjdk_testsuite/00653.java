



import java.io.*;
import javax.tools.*;

public class T6413876 {
    public static void main(String... args) {
        test("-d");
        test("-s");
    }

    private static void test(String outOpt) {
        File testSrc = new File(System.getProperty("test.src", "."));
        File file = new File(testSrc, T6413876.class.getName()+".java");
        Tool t = ToolProvider.getSystemJavaCompiler();
        int rc = t.run(null, null, null, outOpt, "NotADir", file.getPath());
        if (rc == 0)
            throw new AssertionError("compilation succeeded unexpectedly");
    }
}
