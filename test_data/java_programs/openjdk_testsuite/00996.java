



import java.io.*;
import java.util.*;

public class T6999210 {
    public static void main(String... args) throws Exception {
        new T6999210().run();
    }

    void run() throws Exception {
        File srcDir = new File("src");
        File classesDir = new File("classes");
        classesDir.mkdirs();

        File c_java = writeFile(srcDir, "C.java", "class C<T> { }");
        compile("-d", classesDir.getPath(), c_java.getPath());
        File c_class = new File(classesDir, "C.class");
        setMajorVersion(c_class, 48);
        File d_java = writeFile(srcDir, "D.java", "class D { C c; }");

        
        String out1 = compile(
            "-d", classesDir.getPath(),
            "-classpath", classesDir.getPath(),
            d_java.getPath());
        if (out1.length() > 0)
            error("unexpected output from javac");

        
        String out2 = compile(
            "-d", classesDir.getPath(),
            "-classpath", classesDir.getPath(),
            "-Xlint:classfile",
            d_java.getPath());
        if (!out2.contains("[classfile]"))
            error("expected output \"[classfile]\" not found");

        
        String out3 = compile(
            "-d", classesDir.getPath(),
            "-classpath", classesDir.getPath(),
            "-Xlint:classfile", "-XDrawDiagnostics",
            d_java.getPath());
        String expect = "C.class:-:-: compiler.warn.future.attr: Signature, 49, 0, 48, 0";
        if (!out3.contains(expect))
            error("expected output \"" + expect + "\" not found");

        if (errors > 0)
            throw new Exception(errors + " errors occurred");
    }

    String compile(String... args) throws Exception {
        System.err.println("compile: " + Arrays.asList(args));
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        int rc = com.sun.tools.javac.Main.compile(args, pw);
        pw.close();
        String out = sw.toString();
        if (out.length() > 0)
            System.err.println(out);
        if (rc != 0)
            throw new Exception("compilation failed, rc=" + rc);
        return out;
    }

    void setMajorVersion(File f, int major) throws IOException {
        int len = (int) f.length();
        byte[] data = new byte[len];
        try (DataInputStream in = new DataInputStream(new FileInputStream(f))) {
            in.readFully(data);
        }
        
        
        data[6] = (byte) (major >> 8);
        data[7] = (byte) (major & 0xff);
        try (FileOutputStream out = new FileOutputStream(f)) {
            out.write(data);
        }
    }

    File writeFile(File dir, String path, String body) throws IOException {
        File f = new File(dir, path);
        f.getParentFile().mkdirs();
        try (FileWriter out = new FileWriter(f)) {
            out.write(body);
        }
        return f;
    }

    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    int errors;
}
