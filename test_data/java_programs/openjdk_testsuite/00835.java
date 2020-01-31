



import java.io.*;
import java.util.*;

public class T6595666 {
    void m() {
        
        List<Integer> list = new ArrayList();
    }

    public static void main(String... args) throws Exception {
        File testSrc = new File(System.getProperty("test.src", "."));

        String basename = T6595666.class.getName();
        File srcFile = new File(testSrc, basename+".java");
        File classFile = new File(basename+".class");
        classFile.delete();
        if (classFile.exists())
            throw new Exception("setup error, can't delete " + classFile);

        compile(1, "-d", ".", "-Xlint", "-Werror", srcFile.getPath());
        if (classFile.exists())
            throw new Exception("failed: found " + classFile);

        compile(0, "-d", ".", "-Xlint", srcFile.getPath());
        if (!classFile.exists())
            throw new Exception("failed: " + classFile + " not found");
    }

    private static void compile(int rc, String... args) throws Exception {
        System.err.println("compile: " + Arrays.asList(args));
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        int rc2 = com.sun.tools.javac.Main.compile(args, pw);
        pw.close();
        System.err.println(sw);
        if (rc != rc2)
            throw new Exception("bad exit code; expected " + rc + ", found " + rc2);
    }
}
