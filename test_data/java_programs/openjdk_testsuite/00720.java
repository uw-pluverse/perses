



import java.io.File;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import javax.tools.*;
import static java.nio.file.StandardOpenOption.*;

public class T6306137 {
    boolean error;
    final StandardJavaFileManager fm;
    final JavaCompiler compiler;
    Iterable<? extends JavaFileObject> files;
    DiagnosticListener<JavaFileObject> dl;
    final File testFile = new File("Utf8.java");

    T6306137() throws IOException {
        dl = new DiagnosticListener<JavaFileObject>() {
                public void report(Diagnostic<? extends JavaFileObject> message) {
                    if (message.getKind() == Diagnostic.Kind.ERROR)
                        error = true;
                    System.out.println(message.getSource()
                                       +":"+message.getStartPosition()+":"
                                       +message.getStartPosition()+":"+message.getPosition());
                    System.out.println(message.toString());
                    System.out.format("Found problem: %s%n", message.getCode());
                    System.out.flush();
                }
        };
        compiler = ToolProvider.getSystemJavaCompiler();
        fm = compiler.getStandardFileManager(dl, null, null);
        files =
            fm.getJavaFileObjectsFromFiles(Arrays.asList(testFile));
        createTestFile();
    }
    final void createTestFile() throws IOException {
        List<String> scratch = new ArrayList<>();
        scratch.add("// @author Peter von der Ah" + (char)0xe9);
        scratch.add("class Utf8{}");
        Files.write(testFile.toPath(), scratch, Charset.forName("UTF-8"),
                CREATE, TRUNCATE_EXISTING);
    }
    void test(String encoding, boolean good) {
        error = false;
        Iterable<String> args = Arrays.asList("-source", "6", "-encoding", encoding, "-d", ".");
        compiler.getTask(null, fm, dl, args, null, files).call();
        if (error == good) {
            if (error) {
                throw new AssertionError("Error reported");
            } else {
                throw new AssertionError("No error reported");
            }
        }
    }

    public static void main(String[] args) throws IOException {
        T6306137 self = new T6306137();
        self.test("utf-8", true);
        self.test("ascii", false);
        self.test("utf-8", true);
    }
}
