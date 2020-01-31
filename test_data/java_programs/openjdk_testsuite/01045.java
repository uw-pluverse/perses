



import java.io.File;
import java.util.*;
import javax.tools.*;

public class T6407066 {
    public static void main(String... args) throws Exception {
        String testSrc = System.getProperty("test.src", ".");
        String testClasses = System.getProperty("test.classes", ".");

        JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager jfm = tool.getStandardFileManager(null, null, null);

        List<File> path = new ArrayList<File>();
        path.add(new File("BadDirectory"));
        path.add(new File(testSrc));
        path.add(new File("BadFile.jar"));

        jfm.setLocation(StandardLocation.SOURCE_PATH, path);

        List<File> path2  = new ArrayList<File>();
        for (File f: jfm.getLocation(StandardLocation.SOURCE_PATH))
            path2.add(f);

        if (!path.equals(path2))
            throw new AssertionError("path not preserved");
    }
}
