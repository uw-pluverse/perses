



import java.io.*;
import java.security.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.tools.*;
import javax.tools.Diagnostic.Kind;
import javax.tools.JavaCompiler.CompilationTask;

public class TestGetResource2 {

    public static void main(String[] args) throws Exception {
        new TestGetResource2().run();
    }

    void run() throws Exception {
        JavaCompiler javac = ToolProvider.getSystemJavaCompiler();
        CodeSource cs = javac.getClass().getProtectionDomain().getCodeSource();
        if (cs == null) {
            System.err.println("got compiler from " +
                ClassLoader.getSystemResource(javac.getClass().getName().replace(".", "/")+".class"));
        } else {
            System.err.println("got compiler from " + cs.getLocation());
        }

        testSingleSourceDir(javac);
        testCompositeSourcePath(javac);
        testMissingResource(javac);
    }

    private void testSingleSourceDir(JavaCompiler javac) throws Exception {
        System.err.println("testSingleSourceDir");
        File tmpdir = new File("testSingleSourceDir");
        File srcdir = new File(tmpdir, "src");
        File destdir = new File(tmpdir, "dest");
        write(srcdir, "pkg/X.java", "package pkg; class X {}");
        write(srcdir, "resources/file.txt", "hello");
        destdir.mkdirs();

        CompilationTask task = javac.getTask(null, null, null,
                Arrays.asList("-sourcepath", srcdir.toString(), "-d", destdir.toString()),
                Collections.singleton("pkg.X"), null);
        task.setProcessors(Collections.singleton(new AnnoProc()));
        boolean result = task.call();
        System.err.println("javac result with single source dir: " + result);
        expect(result, true);
    }

    private void testCompositeSourcePath(JavaCompiler javac) throws Exception {
        System.err.println("testCompositeSearchPath");
        File tmpdir = new File("testCompositeSourcePath");
        File srcdir = new File(tmpdir, "src");
        File rsrcdir = new File(tmpdir, "rsrc");
        File destdir = new File(tmpdir, "dest");
        write(srcdir, "pkg/X.java", "package pkg; class X {}");
        write(rsrcdir, "resources/file.txt", "hello");
        destdir.mkdirs();

        CompilationTask task = javac.getTask(null, null, null,
                Arrays.asList("-sourcepath", srcdir + File.pathSeparator + rsrcdir, "-d", destdir.toString()),
                Collections.singleton("pkg.X"), null);
        task.setProcessors(Collections.singleton(new AnnoProc()));
        boolean result = task.call();
        System.err.println("javac result with composite source path: " + result);
        expect(result, true);
    }

    private void testMissingResource(JavaCompiler javac) throws Exception {
        System.err.println("testMissingResource");
        File tmpdir = new File("testMissingResource");
        File srcdir = new File(tmpdir, "src");
        File destdir = new File(tmpdir, "dest");
        write(srcdir, "pkg/X.java", "package pkg; class X {}");
        destdir.mkdirs();

        CompilationTask task = javac.getTask(null, null, null,
                Arrays.asList("-sourcepath", srcdir.toString(), "-d", destdir.toString()),
                Collections.singleton("pkg.X"), null);
        task.setProcessors(Collections.singleton(new AnnoProc()));
        boolean result = task.call();
        System.err.println("javac result when missing resource: " + result);
        expect(result, false);

        if (errors > 0)
            throw new Exception(errors + " errors occurred");
    }

    static class AnnoProc extends JavacTestingAbstractProcessor {

        public @Override boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
            if (roundEnv.processingOver()) {
                return false;
            }

            try {
                FileObject resource = filer.getResource(StandardLocation.SOURCE_PATH, "resources", "file.txt");
                try {
                    resource.openInputStream().close();
                    messager.printMessage(Kind.NOTE, "found: " + resource.toUri());
                    return true;
                } catch (IOException x) {
                    messager.printMessage(Kind.ERROR, "could not read: " + resource.toUri());
                    x.printStackTrace();
                }
            } catch (IOException x) {
                messager.printMessage(Kind.ERROR, "did not find resource");
                x.printStackTrace();
            }

            return false;
        }

    }

    private File write(File dir, String path, String contents) throws IOException {
        File f = new File(dir, path);
        f.getParentFile().mkdirs();
        Writer w = new FileWriter(f);
        try {
            w.write(contents);
        } finally {
            w.close();
        }
        return f;
    }

    void expect(boolean val, boolean expect) {
        if (val != expect)
            error("Unexpected value: " + val + "; expected: " + expect);
    }

    void error(String msg) {
        System.err.println(msg);
        errors++;
    }

    int errors = 0;
}
