



import java.io.*;
import java.util.*;
import javax.tools.*;
import javax.tools.JavaCompiler.CompilationTask;

public class T6900149 {
    public static void main(String[] args) throws IOException {
        DiagnosticCollector<JavaFileObject> diag =
                new DiagnosticCollector<JavaFileObject>();
        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager fm =
                compiler.getStandardFileManager(null, null, null);
        File emptyFile = createTempFile("Empty.java");
        File[] files = new File[] { emptyFile, emptyFile };
        CompilationTask task = compiler.getTask(null, fm, diag,
                null, null, fm.getJavaFileObjects(files));
        if (! task.call()) {
            throw new AssertionError("compilation failed");
        }
    }

    private static File createTempFile(String path) throws IOException {
        File f = new File(path);
        try (FileWriter out = new FileWriter(f)) { }
        return f;
    }
}
