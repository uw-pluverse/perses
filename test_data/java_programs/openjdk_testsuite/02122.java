








import java.io.*;
import java.nio.*;
import java.util.*;
import java.util.jar.*;
import javax.tools.*;
import javax.tools.StandardJavaFileManager.*;

public class T6400872 {
    static File testSrc = new File(System.getProperty("test.src", "."));
    static File testClasses = new File(System.getProperty("test.classes", "."));

    public static void main(String... args) throws Exception {
        
        compile(testClasses, null, new File(testSrc, "A.java"), new File(testSrc, "B.java"));
        
        jar(new File("A.jar"), iterable(new File(".", "B.jar")), testClasses, new File("A.class"));
        jar(new File("B.jar"), iterable(new File(".", "A.jar")), testClasses, new File("B.class"));
        
        compile(new File("."), iterable(new File("A.jar")), new File(testSrc, "C.java"));
    }

    static void compile(File classOutDir, Iterable<File> classPath, File... files)
                throws IOException {
        System.err.println("compile...");
        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager fm = compiler.getStandardFileManager(null, null, null);
        try {
            Iterable<? extends JavaFileObject> fileObjects =
                fm.getJavaFileObjectsFromFiles(Arrays.asList(files));

            List<String> options = new ArrayList<String>();
            if (classOutDir != null) {
                options.add("-d");
                options.add(classOutDir.getPath());
            }
            if (classPath != null) {
                options.add("-classpath");
                options.add(join(classPath, File.pathSeparator));
            }
            options.add("-verbose");

            JavaCompiler.CompilationTask task =
                compiler.getTask(null, fm, null, options, null, fileObjects);
            if (!task.call())
                throw new AssertionError("compilation failed");
        } finally {
            fm.close();
        }
    }

    static void jar(File jar, Iterable<File> classPath, File base, File... files)
            throws IOException {
        System.err.println("jar...");
        Manifest m = new Manifest();
        if (classPath != null) {
            Attributes mainAttrs = m.getMainAttributes();
            mainAttrs.put(Attributes.Name.MANIFEST_VERSION, "1.0");
            mainAttrs.put(Attributes.Name.CLASS_PATH, join(classPath, " "));
        }
        OutputStream out = new BufferedOutputStream(new FileOutputStream(jar));
        JarOutputStream j = new JarOutputStream(out, m);
        add(j, base, files);
        j.close();
    }

    static void add(JarOutputStream j, File base, File... files) throws IOException {
        if (files == null)
            return;

        for (File f: files)
            add(j, base, f);
    }

    static void add(JarOutputStream j, File base, File file) throws IOException {
        File f = new File(base, file.getPath());
        if (f.isDirectory()) {
            String[] children = f.list();
            if (children != null)
                for (String c: children)
                    add(j, base, new File(file, c));
        } else {
            JarEntry e = new JarEntry(file.getPath());
            e.setSize(f.length());
            j.putNextEntry(e);
            j.write(read(f));
            j.closeEntry();
        }

    }

    static byte[] read(File f) throws IOException {
        byte[] buf = new byte[(int) f.length()];
        BufferedInputStream in = new BufferedInputStream(new FileInputStream(f));
        int offset = 0;
        while (offset < buf.length) {
            int n = in.read(buf, offset, buf.length - offset);
            if (n < 0)
                throw new EOFException();
            offset += n;
        }
        return buf;
    }

    static <T> Iterable<T> iterable(T single) {
        return Collections.singleton(single);
    }

    static <T> String join(Iterable<T> iter, String sep) {
        StringBuilder p = new StringBuilder();
        for (T t: iter) {
            if (p.length() > 0)
                p.append(' ');
            p.append(t);
        }
        return p.toString();
    }
}
