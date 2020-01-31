



import java.io.*;
import java.util.*;
import com.sun.tools.javac.api.*;

public class T6403424 {
    public static void main(String[] args) {
        File testSrc = new File(System.getProperty("test.src", "."));

        File TMP = new File("TMP");
        TMP.mkdirs();

        
        File A_java = new File(testSrc, "A.java");
        compile("-d", TMP.getPath(), A_java.getPath());

        
        
        File B_java = new File(testSrc, "B.java");
        compile("-classpath",  TMP.getPath(),
                "-Xbootclasspath/p:" + TMP.getPath().toLowerCase(),
                "-d", ".",
                B_java.getPath());

        
    }

    private static void compile(String... args) {
        System.err.println("compile: " + Arrays.asList(args));
        JavacTool javac = JavacTool.create();

        int rc = javac.run(null, null, null, args);
        if (rc != 0)
            throw new AssertionError("test compilation failed");
    }
}
