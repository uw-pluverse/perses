



import java.io.*;
import java.net.*;
import java.util.*;
import javax.tools.*;
import com.sun.source.util.*;

public class ExtraSemiTest {

    static class JavaSource extends SimpleJavaFileObject {

        final static String source =
                        "class C {\n" +
                        "    int x;;\n" +
                        "    class X { int i;; };\n" +
                        "}";

        JavaSource() {
            super(URI.create("myfo:/C.java"), JavaFileObject.Kind.SOURCE);
        }

        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return source;
        }
    }

    public static void main(String... args) throws IOException {
        new ExtraSemiTest().run();
    }

    void run() throws IOException {
        File destDir = new File("classes"); destDir.mkdir();
        final JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        JavaSource source = new JavaSource();
        JavacTask ct = (JavacTask)tool.getTask(null, null, null,
                Arrays.asList("-d", destDir.getPath(), "-XD-printsource"),
                null,
                Arrays.asList(source));
        Boolean ok = ct.call();
        if (!ok) throw new AssertionError("compilation failed");

        String text = readFile(new File(destDir, "C.java"));
        System.out.println(text);

        
        String canon = text.replaceAll("\\s+", " ");
        System.out.println("canon: " + canon);

        
        
        
        
        
        

        if (canon.contains("{ }"))
            throw new AssertionError("unexpected empty block found");
    }

    String readFile(File f) throws IOException {
        int len = (int) f.length();
        byte[] data = new byte[len];
        DataInputStream in = new DataInputStream(new FileInputStream(f));
        try {
            in.readFully(data);
            return new String(data);
        } finally {
            in.close();
        }
    }
}
