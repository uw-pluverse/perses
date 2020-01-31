



import java.io.IOException;
import javax.tools.*;
import static javax.tools.StandardLocation.*;
import static javax.tools.JavaFileObject.Kind.*;

public class T6437349 extends ToolTester {
    void test(String... args) throws IOException {
        task = tool.getTask(null, fm, null, null, null, null);
        JavaFileObject fo = fm.getJavaFileForInput(SOURCE_PATH, "T6437349", SOURCE);
        if (fo.isNameCompatible("T6437349.java", OTHER))
            throw new AssertionError();
        if (!fo.isNameCompatible("T6437349", SOURCE))
            throw new AssertionError();
        fo = fm.getJavaFileForInput(PLATFORM_CLASS_PATH, "java.lang.Object", CLASS);
        if (fo.isNameCompatible("Object.class", OTHER))
            throw new AssertionError();
        if (!fo.isNameCompatible("Object", CLASS))
            throw new AssertionError();
    }
    public static void main(String... args) throws IOException {
        new T6437349().test(args);
    }
}
