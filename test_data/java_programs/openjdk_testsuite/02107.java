



import java.lang.reflect.Field;
import java.io.File;
import java.io.ByteArrayOutputStream;
import javax.tools.*;

public class T6410653 {
    public static void main(String... args) throws Exception {
        File testSrc = new File(System.getProperty("test.src"));
        String source = new File(testSrc, "T6410653.java").getPath();
        ClassLoader cl = ToolProvider.getSystemToolClassLoader();
        Tool compiler = ToolProvider.getSystemJavaCompiler();
        Class<?> log = Class.forName("com.sun.tools.javac.util.Log", true, cl);
        Field useRawMessages = log.getDeclaredField("useRawMessages");
        useRawMessages.setAccessible(true);
        useRawMessages.setBoolean(null, true);
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        compiler.run(null, null, out, "-d", source, source);
        useRawMessages.setBoolean(null, false);
        if (!out.toString().equals(String.format("%s%n%s%n",
                                                 "javac: javac.err.file.not.directory",
                                                 "javac.msg.usage"))) {
            throw new AssertionError(out);
        }
        System.out.println("Test PASSED.  Running javac again to see localized output:");
        compiler.run(null, null, System.out, "-d", source, source);
    }
}
