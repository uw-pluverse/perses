



import java.io.*;
import java.net.URI;
import javax.tools.*;

public class T6501502 {
    public static void main(String... args) throws Exception {
        new T6501502().run();
    }

    
    
    
    
    
    
    
    
    void run() throws Exception {
        JavaCompiler c = ToolProvider.getSystemJavaCompiler();
        fm = c.getStandardFileManager(null, null, null);
        System.err.println(System.getProperties());
        File tmpDir = new File(System.getProperty("java.io.tmpdir"));
        File testSrcDir = new File(System.getProperty("test.src"));
        File testClassesDir = new File(System.getProperty("test.classes"));
        test(new File("abc.tmp"));
        test(new File(tmpDir, "bad.file"));
        test(new File(testSrcDir, "T6501501.java"));
        test(new File(testClassesDir, "T6501501.class"));
        test(new File("a b"));
    }

    void test(File f) throws Exception {
        System.err.println("test " + f);
        FileObject fo = fm.getJavaFileObjects(f).iterator().next();
        URI uri = fo.toUri();
        System.err.println("FileObject uri: " + uri);
        if (!new File(uri).equals(f.getAbsoluteFile()))
            throw new Exception("unexpected URI returned");
    }

    StandardJavaFileManager fm;
}

