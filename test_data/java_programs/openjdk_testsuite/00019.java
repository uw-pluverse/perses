



import java.io.*;
import java.lang.reflect.*;
import java.net.*;
import java.util.*;

public class T6627362 {
    static String testSrc = System.getProperty("test.src", ".");

    public static void main(String... args) throws Exception {
        new T6627362().run();
    }

    public void run() throws Exception {
        testStandard();
        testNoClone();
        if (errors > 0)
            throw new Error(errors + " test cases failed");
    }

    void testStandard() throws Exception {
        
        File x = new File(testSrc, "x");
        String[] jcArgs = { "-d", ".",
                            new File(x, "E.java").getPath() };
        compile(jcArgs);

        String[] jpArgs = { "-classpath", ".", "-c", "E" };

        StringWriter sw = new StringWriter();
        javap(new PrintWriter(sw, true), jpArgs);
        check(sw.toString(), "Method \"[LE;\".clone:()Ljava/lang/Object;");
        callValues();
    }

    void testNoClone() throws Exception {
        
        
        File x = new File(testSrc, "x");
        String[] jcArgs = { "-d", ".",
                            new File(x, "E.java").getPath(),
                            new File(x, "Object.java").getPath()};
        compile(jcArgs);

        String[] jpArgs = { "-classpath", ".", "-c", "E" };

        StringWriter sw = new StringWriter();
        javap(new PrintWriter(sw, true), jpArgs);
        check(sw.toString(), "// Method java/lang/System.arraycopy:(Ljava/lang/Object;ILjava/lang/Object;II)V");
        callValues();
    }

    void compile(String... args) {
        int rc = com.sun.tools.javac.Main.compile(args);
        if (rc != 0)
            throw new Error("javac failed: " + Arrays.asList(args) + ": " + rc);
    }

    void javap(PrintWriter out, String... args) throws Exception {
        int rc = com.sun.tools.javap.Main.run(args, out);
        if (rc != 0)
            throw new Error("javap failed: " + Arrays.asList(args) + ": " + rc);
    }

    void check(String s, String require) {
        System.out.println("Checking:\n" + s);
        if (s.indexOf(require) == -1) {
            System.err.println("Can't find " + require);
            errors++;
        }
    }

    void callValues() {
        try {
            File dot = new File(System.getProperty("user.dir"));
            ClassLoader cl = new URLClassLoader(new URL[] { dot.toURL() });
            Class<?> e_class = cl.loadClass("E");
            Method m = e_class.getMethod("values", new Class[] { });
            
            Object o = m.invoke(null, (Object[]) null);
            List<Object> v = Arrays.asList((Object[]) o);
            if (!v.toString().equals("[a, b, c]"))
                throw new Error("unexpected result for E.values(): " + v);
        } catch (Exception e) {
            throw new Error(e);
        }
    }

    int errors;
}

