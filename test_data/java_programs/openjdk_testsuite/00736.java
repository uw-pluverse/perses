



import java.io.File;
import java.io.IOException;
import java.net.URI;
import javax.tools.JavaFileObject;

public class T6440333 extends ToolTester {
    void test(String... args) throws IOException {
        File path = test_src.getCanonicalFile();
        File src = new File(new File(path, "."), "T6440333.java");
        JavaFileObject fo = fm.getJavaFileObjects(src).iterator().next();
        URI expect = src.getCanonicalFile().toURI();
        System.err.println("Expect " + expect);
        System.err.println("Found  " + fo.toUri());
        if (!expect.equals(fo.toUri())) {
            throw new AssertionError();
        }
    }
    public static void main(String... args) throws IOException {
        new T6440333().test(args);
    }
}
