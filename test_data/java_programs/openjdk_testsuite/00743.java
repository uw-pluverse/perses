



import javax.tools.*;
import static javax.tools.StandardLocation.*;

public class T6400205 {
    public static void main(String... args) {
        JavaFileManager fm =
            ToolProvider.getSystemJavaCompiler().getStandardFileManager(null, null, null);
        try {
            fm.getClassLoader(null);
            throw new AssertionError("NullPointerException not thrown");
        } catch (NullPointerException e) {
            
        }
        ClassLoader cl = fm.getClassLoader(locationFor("bogus"));
        if (cl != null)
            throw new AssertionError("non-null class loader for bogus location");
        System.err.println("Test PASSED.");
    }
}
