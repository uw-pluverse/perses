



import java.io.*;
import java.net.*;
import java.lang.reflect.*;

class SameJVM {

    private static ClassLoader toolsClassLoader() {
        File javaHome   = new File(System.getProperty("java.home"));
        File classesDir = new File(javaHome, "classes");
        File libDir     = new File(javaHome.getParentFile(), "lib");
        File toolsJar   = new File(libDir, "tools.jar");
        try {
            return new URLClassLoader(
                new URL[] {classesDir.toURL(), toolsJar.toURL()});
        } catch (MalformedURLException e) { throw new AssertionError(e); }
    }
    private static final ClassLoader cl = toolsClassLoader();

    static void javac(String... args) throws Exception {
        Class c = Class.forName("com.sun.tools.javac.Main", true, cl);
        int status = (Integer)
            c.getMethod("compile", new Class[] {String[].class})
            .invoke(c.newInstance(), new Object[] {args});
        if (status != 0)
            throw new Exception("javac failed: status=" + status);
    }

    static void jar(String... args) throws Exception {
        Class c = Class.forName("sun.tools.jar.Main", true, cl);
        Object instance = c.getConstructor(
            new Class[] {PrintStream.class, PrintStream.class, String.class})
            .newInstance(System.out, System.err, "jar");
        boolean result = (Boolean)
            c.getMethod("run", new Class[] {String[].class})
            .invoke(instance, new Object[] {args});
        if (! result)
            throw new Exception("jar failed");
    }
}
