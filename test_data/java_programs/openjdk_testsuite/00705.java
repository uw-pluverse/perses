



import java.io.File;
import java.net.URI;
import java.util.Arrays;
import javax.tools.*;
import static javax.tools.JavaFileObject.Kind.*;

public class T6358955 {
    public static void main(String[] args) throws Exception {
        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager jfm = compiler.getStandardFileManager(null, null, null);

        File dir = new File("temp" + args.hashCode());
        if (!dir.exists())
            dir.mkdir();
        if (!dir.isDirectory())
            throw new AssertionError("Not a directory " + dir);

        try {
            jfm.setLocation(StandardLocation.CLASS_OUTPUT,
                            Arrays.asList(dir.getCanonicalFile().getParentFile()));
            try {
                jfm.getFileForInput(StandardLocation.CLASS_OUTPUT, "", dir.getPath());
                throw new AssertionError("IllegalArgumentException not thrown");
            } catch (IllegalArgumentException e) {
                System.out.println("OK: " + e.getLocalizedMessage());
            }
            try {
                jfm.getJavaFileObjectsFromFiles(Arrays.asList(dir));
                throw new AssertionError("IllegalArgumentException not thrown");
            } catch (IllegalArgumentException e) {
                System.out.println("OK: " + e.getLocalizedMessage());
            }
        } finally {
            try {
                dir.delete(); 
            } catch (Throwable t) {
                t.printStackTrace();
            }
        }
    }
}
