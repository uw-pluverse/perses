



import java.io.*;
import java.net.*;
import java.util.Collections;
import java.util.jar.*;
import java.util.zip.*;
import javax.tools.*;

public class T6483788 {
    public static void main(String[] args) throws Exception {
        new T6483788().run();
    }

    void run() throws Exception {
        File jar = createJar();
        JavaCompiler c = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager fm = c.getStandardFileManager(null, null, null);
        fm.setLocation(StandardLocation.CLASS_PATH, Collections.singleton(jar));
        JavaFileObject fo = fm.getJavaFileForInput(StandardLocation.CLASS_PATH, "dummy", JavaFileObject.Kind.CLASS);
        System.err.println("file: " + fo);
        URI uri = fo.toUri();
        System.err.println("uri: " + uri);
        if (uri.toString().contains(" "))
            throw new Exception("unexpected space character found");
    }

    File createJar() throws IOException {
        byte[] dummy_data = new byte[10];
        File f = new File("a b.jar");
        OutputStream out = new FileOutputStream(f);
        try {
            JarOutputStream jar = new JarOutputStream(out);
            jar.putNextEntry(new ZipEntry("dummy.class"));
            jar.write(dummy_data);
            jar.close();
        } finally {
            out.close();
        }
        return f;
    }
}

