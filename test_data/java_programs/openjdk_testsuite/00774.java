

import java.io.File;
import java.io.IOException;
import java.nio.charset.Charset;
import java.util.*;
import javax.tools.*;

import static javax.tools.StandardLocation.CLASS_PATH;
import static javax.tools.StandardLocation.SOURCE_PATH;
import static javax.tools.StandardLocation.CLASS_OUTPUT;

public class ToolTester {
    public final File test_src     = new File(System.getProperty("test.src", "."));
    public final File test_classes = new File(System.getProperty("test.classes", "."));
    public final List<File> test_class_path = pathToFiles(System.getProperty("test.class.path"),
                                     Arrays.asList(test_classes));
    public final JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
    public final StandardJavaFileManager fm = getFileManager(tool, null, null);
    public JavaCompiler.CompilationTask task = null;
    public final StandardJavaFileManager getFileManager(JavaCompiler tool,
                                                        DiagnosticListener<JavaFileObject> dl,
                                                        Charset encoding) {
        StandardJavaFileManager fm = tool.getStandardFileManager(dl, null, encoding);
        try {
            fm.setLocation(SOURCE_PATH,  Arrays.asList(test_src));
            fm.setLocation(CLASS_PATH,   test_class_path);
            fm.setLocation(CLASS_OUTPUT, Arrays.asList(test_classes));
        } catch (IOException e) {
            throw new AssertionError(e);
        }
        return fm;
    }

    protected List<File> pathToFiles(String path, List<File> defaultPath) {
        List<File> files = new ArrayList<>();
        for (String f: path.split(File.pathSeparator)) {
            if (f.isEmpty())
                continue;
            File file = new File(f);
            if (file.exists())
                files.add(file);
        }
        if (files.isEmpty())
            files.addAll(defaultPath);
        return files;
    }

    protected <T> List<T> join(List<T> a, List<T> b) {
        if (a.isEmpty())
            return b;
        if (b.isEmpty())
            return a;
        List<T> result = new ArrayList<>();
        result.addAll(a);
        result.addAll(b);
        return result;
    }
}
