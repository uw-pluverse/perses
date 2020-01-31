



import java.io.*;
import java.util.*;

public class T6985181 {
    public static void main(String... args) throws Exception{
        new T6985181().run();
    }

    public void run() throws Exception {
        String code = "@java.lang.annotation.Target(java.lang.annotation.ElementType.TYPE_PARAMETER)\n" +
                "@interface Simple { }\n" +
                "interface Test<@Simple T> { }";

        File srcFile = writeFile("Test.java", code);
        File classesDir = new File("classes");
        classesDir.mkdirs();
        compile("-d", classesDir.getPath(), srcFile.getPath());
        String out = javap(new File(classesDir, srcFile.getName().replace(".java", ".class")));
        if (!out.contains("RuntimeInvisibleTypeAnnotations"))
            throw new Exception("RuntimeInvisibleTypeAnnotations not found");
    }

    void compile(String... args) throws Exception {
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        int rc = com.sun.tools.javac.Main.compile(args, pw);
        pw.close();
        String out = sw.toString();
        if (out.length() > 0)
            System.err.println(out);
        if (rc != 0)
            throw new Exception("Compilation failed: rc=" + rc);
    }

    String javap(File classFile) throws Exception {
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        String[] args = { "-v", classFile.getPath() };
        int rc = com.sun.tools.javap.Main.run(args, pw);
        pw.close();
        String out = sw.toString();
        if (out.length() > 0)
            System.err.println(out);
        if (rc != 0)
            throw new Exception("javap failed: rc=" + rc);
        return out;
    }

    File writeFile(String path, String body) throws IOException {
        File f = new File(path);
        FileWriter out = new FileWriter(f);
        try {
            out.write(body);
        } finally {
            out.close();
        }
        return f;
    }
}
