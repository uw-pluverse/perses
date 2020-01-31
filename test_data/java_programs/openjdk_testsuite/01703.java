




import java.io.*;

public class T6942649 {
    public static void main(String... args) throws Exception {
        new T6942649().run();
    }

    void run() throws Exception {
        test("-XDshowClass", "com.sun.tools.javac.Main");
        test("-XDshowClass=com.sun.tools.javac.util.Log", "com.sun.tools.javac.util.Log");
    }

    void test(String opt, String clazz) throws Exception {
        System.err.println("test " + opt);
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        int rc = com.sun.tools.javac.Main.compile(new String[] { opt }, pw);
        pw.close();
        String out = sw.toString();
        System.err.println("javac rc=" + rc + "\n" + out);
        if (!out.contains(clazz))
            throw new Exception("class name not found in output");
        int lastDot = clazz.lastIndexOf(".");
        if (!out.contains(clazz.substring(lastDot + 1) + ".class"))
            throw new Exception("location of class not found in output");
        if (!out.contains("MD5 checksum: "))
            throw new Exception("checksum not found in output");
    }
}
