



import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import javax.tools.DiagnosticCollector;
import javax.tools.JavaFileObject;
import javax.tools.StandardJavaFileManager;
import javax.tools.StandardLocation;
import javax.tools.ToolProvider;

public class TestCompileJARInClassPath {

    public static void main(String args[]) throws Exception {
        TestCompileJARInClassPath theTest = new TestCompileJARInClassPath();
        theTest.run();
    }

    void run() throws Exception {
        try {
            clean();
            generateFilesNeeded();
            compileWithJSR199();
        } finally {
            clean();
        }
    }

    void writeFile(String f, String contents) throws IOException {
        PrintStream s = new PrintStream(new FileOutputStream(f));
        s.println(contents);
        s.close();
    }

    void rm(String filename) throws Exception {
        File f = new File(filename);
        f.delete();
        if (f.exists())
            throw new Exception(filename + ": couldn't remove");
    }

    void clean() throws Exception {
        rm("C1.java");
        rm("C1.class");
        rm("C1.jar");

        rm("C2.java");
        rm("C2.class");
        rm("C2.jar");
        rm("MANIFEST.MF");

        rm("C3.java");
        rm("C3.class");
    }

    void generateFilesNeeded() throws Exception {
        sun.tools.jar.Main jarGenerator = new sun.tools.jar.Main(System.out, System.err, "jar");

        writeFile("C1.java",
                  "public class C1 {public static void f() {}}");
        com.sun.tools.javac.Main.compile(new String[]{"C1.java"});
        jarGenerator.run(new String[] {"cf", "C1.jar", "C1.class"});

        writeFile("C2.java",
                  "public class C2 {public static void g() {}}");
        writeFile("MANIFEST.MF",
                  "Manifest-Version: 1.0\n" +
                  "Class-Path: C1.jar\n" +
                  "Main-Class: C2");
        com.sun.tools.javac.Main.compile(new String[]{"C2.java"});
        jarGenerator.run(new String[] {"cfm", "C2.jar", "MANIFEST.MF", "C2.class"});

        writeFile("C3.java",
                  "public class C3 {public static void h() {C2.g(); C1.f();}}");
    }

    void compileWithJSR199() throws IOException {
        String cpath = "C2.jar";
        File clientJarFile = new File(cpath);
        File sourceFileToCompile = new File("C3.java");


        javax.tools.JavaCompiler javac = ToolProvider.getSystemJavaCompiler();
        DiagnosticCollector<JavaFileObject> diagnostics = new DiagnosticCollector<>();
        StandardJavaFileManager stdFileManager = javac.getStandardFileManager(diagnostics, null, null);

        List<File> files = new ArrayList<>();
        files.add(clientJarFile);

        stdFileManager.setLocation(StandardLocation.CLASS_PATH, files);

        Iterable<? extends JavaFileObject> sourceFiles = stdFileManager.getJavaFileObjects(sourceFileToCompile);

        if (!javac.getTask(null, stdFileManager, diagnostics, null, null, sourceFiles).call()) {
            throw new AssertionError("compilation failed");
        }
    }
}
