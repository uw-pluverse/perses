



import java.io.File;
import java.lang.reflect.Field;
import java.util.Arrays;
import static javax.tools.StandardLocation.CLASS_OUTPUT;
import javax.tools.*;

public class T6440528 extends ToolTester {
    void test(String... args) throws Exception {
        fm.setLocation(CLASS_OUTPUT, null); 
                                            
                                            
                                            
        Iterable<File> files = Arrays.asList(new File(test_src, "package-info.java"));
        JavaFileObject src = fm.getJavaFileObjectsFromFiles(files).iterator().next();
        char sep = File.separatorChar;
        FileObject cls = fm.getFileForOutput(CLASS_OUTPUT,
                                             "com.sun.foo.bar.baz",
                                             "package-info.class",
                                             src);
        File expect = new File(test_src, "package-info.class");
        File got = getUnderlyingFile(cls);
        if (!got.equals(expect))
            throw new AssertionError(String.format("Expected: %s; got: %s", expect, got));
        System.err.println("Expected: " + expect);
        System.err.println("Got:      " + got);
    }

    private File getUnderlyingFile(Object o) throws Exception {
        Field file = o.getClass().getDeclaredField("file");
        file.setAccessible(true);
        return (File)file.get(o);
    }

    public static void main(String... args) throws Exception {
        new T6440528().test(args);
    }
}
