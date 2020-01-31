



import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Locale;
import javax.tools.JavaFileManager.Location;
import javax.tools.*;

import static javax.tools.StandardLocation.CLASS_PATH;
import static javax.tools.StandardLocation.SOURCE_PATH;
import static javax.tools.StandardLocation.CLASS_OUTPUT;

public class T6420409 {
    static final File test_src     = new File(System.getProperty("test.src"));
    static final File test_classes = new File(System.getProperty("test.classes"));

    public static void main(String... args) throws IOException {
        final JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        final StandardJavaFileManager fm = tool.getStandardFileManager(null, null, null);
        fm.setLocation(SOURCE_PATH,  Arrays.asList(test_classes)); 
        fm.setLocation(CLASS_PATH,   Arrays.asList(test_src));
        fm.setLocation(CLASS_OUTPUT, Arrays.asList(test_classes));
        final Iterable<? extends JavaFileObject> compilationUnits =
            fm.getJavaFileObjectsFromFiles(Arrays.asList(new File(test_src, "T6420409.java")));
        tool.getTask(null,
                     fm,
                     null,
                     Arrays.asList("-proc:none"),
                     null,
                     compilationUnits).call();
        test(fm.getLocation(CLASS_PATH),   test_src,     CLASS_PATH);
        test(fm.getLocation(SOURCE_PATH),  test_classes, SOURCE_PATH);
        test(fm.getLocation(CLASS_OUTPUT), test_classes, CLASS_OUTPUT);
    }

    static void test(Iterable<? extends File> path, File file, Location location) {
        Iterator<? extends File> it = path.iterator();
        if (!it.next().equals(file))
            throw new AssertionError(file + " not in " + location);
        if (it.hasNext())
            throw new AssertionError("Unexpected element in "  + location + " : " + it.next());
        System.err.format((Locale)null, "OK: %s: %s%n", location, path);
    }
}
