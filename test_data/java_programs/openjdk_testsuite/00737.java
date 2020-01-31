



import javax.tools.*;
import java.io.*;
import java.util.Collections;

public class T6420464 {
    static final File test_src     = new File(System.getProperty("test.src"));
    static final File test_classes = new File(System.getProperty("test.classes"));

    public static void main(String... args) throws IOException {
        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager mgr = compiler.getStandardFileManager(null, null, null);
        mgr.setLocation(StandardLocation.SOURCE_PATH, Collections.singleton(test_src));
        JavaFileObject f = mgr.getJavaFileForInput(StandardLocation.SOURCE_PATH,
                                                   "T6420464",
                                                   JavaFileObject.Kind.SOURCE);
        if (!f.isNameCompatible("T6420464", JavaFileObject.Kind.SOURCE))
            throw new AssertionError("isNameCompatible(SOURCE) fails on " + f.toUri());
        if (f.isNameCompatible("T6420464", JavaFileObject.Kind.OTHER))
            throw new AssertionError("isNameCompatible(OTHER) fails on " + f.toUri());
        System.out.println("OK");
    }
}
