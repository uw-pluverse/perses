



import java.io.File;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import javax.tools.*;
import static java.nio.file.StandardOpenOption.*;

public class T6437999 extends ToolTester {
    final File testFile = new File("Utf8.java");
    T6437999() throws IOException {
        createTestFile();
    }
    final void createTestFile() throws IOException {
        List<String> scratch = new ArrayList<>();
        scratch.add("// @author Peter von der Ah" + (char) 0xe9);
        scratch.add("class Utf8{}");
        Files.write(testFile.toPath(), scratch, Charset.forName("UTF-8"),
                CREATE, TRUNCATE_EXISTING);
    }

    static class MyDiagnosticListener implements DiagnosticListener<JavaFileObject> {
        boolean error = false;
        public void report(Diagnostic<? extends JavaFileObject> diagnostic) {
            error |= diagnostic.getKind() == Diagnostic.Kind.ERROR;
            System.out.println(diagnostic);
        }
    }

    void test(String... args) {
        Iterable<String> sourceLevel = Collections.singleton("6");
        MyDiagnosticListener dl = new MyDiagnosticListener();
        StandardJavaFileManager fm;
        Iterable<? extends JavaFileObject> files;

        dl.error = false;
        fm = getFileManager(tool, dl, Charset.forName("ASCII"));
        fm.handleOption("-source", sourceLevel.iterator());
        files = fm.getJavaFileObjects(testFile);
        tool.getTask(null, fm, null, null, null, files).call();
        if (!dl.error)
            throw new AssertionError("No error in ASCII mode");

        dl.error = false;
        fm = getFileManager(tool, dl, Charset.forName("UTF-8"));
        fm.handleOption("-source", sourceLevel.iterator());
        files = fm.getJavaFileObjects(testFile);
        task = tool.getTask(null, fm, null, null, null, files);
        if (dl.error)
            throw new AssertionError("Error in UTF-8 mode");
    }
    public static void main(String... args) throws IOException {
        new T6437999().test(args);
    }
}
