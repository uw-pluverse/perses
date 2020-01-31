

import java.io.*;
import java.util.*;
import com.sun.tools.javac.main.Main;


public class CompileFail {
    public static void main(String... args) {
        if (args.length < 2)
            throw new IllegalArgumentException("insufficient args");
        int expected_rc = getReturnCode(args[0]);

        List<String> javacArgs = new ArrayList<>();
        javacArgs.addAll(Arrays.asList(
            "-bootclasspath", System.getProperty("sun.boot.class.path"),
            "-d", "."
        ));

        File testSrc = new File(System.getProperty("test.src"));
        for (int i = 1; i < args.length; i++) { 
            String arg = args[i];
            if (arg.endsWith(".java"))
                javacArgs.add(new File(testSrc, arg).getPath());
            else
                javacArgs.add(arg);
        }

        int rc = com.sun.tools.javac.Main.compile(
            javacArgs.toArray(new String[javacArgs.size()]));

        if (rc != expected_rc)
            throw new Error("unexpected exit code: " + rc
                        + ", expected: " + expected_rc);
    }

    static int getReturnCode(String name) {
        return Main.Result.valueOf(name).exitCode;
    }

}
