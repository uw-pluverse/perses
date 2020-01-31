



import java.io.IOException;
import javax.tools.*;
import static javax.tools.StandardLocation.*;
import static javax.tools.JavaFileObject.Kind.*;



public class T6411333 extends ToolTester {

    
    void testInferBinaryName(String binaryName, boolean fail) {
        try {
            JavaFileObject file = fm.getJavaFileForInput(PLATFORM_CLASS_PATH,
                                                         binaryName,
                                                         CLASS);
            String inferred = fm.inferBinaryName(fail ? CLASS_PATH : PLATFORM_CLASS_PATH,
                                                 file);
            if (inferred == null && fail)
                return;
            if (!inferred.equals(binaryName))
                throw new AssertionError(String.format("binaryName (%s) != inferred (%s)",
                                                       binaryName,
                                                       inferred));
        } catch (IOException ex) {
            throw new AssertionError(ex);
        }
    }

    
    void testRelativeUri(String name, boolean fail) {
        try {
            fm.getFileForInput(SOURCE_OUTPUT, "java.lang", name);
        } catch (IllegalArgumentException ex) {
            if (fail)
                return;
        } catch (IOException ex) {
            throw new AssertionError(ex);
        }
        if (fail)
            throw new AssertionError("Expected failure on " + name);
    }

    void test(String... args) {
        testInferBinaryName("java.lang.Object", false);
        testInferBinaryName("java.lang.Object", true);

        testRelativeUri("../util/List.java", true);
        testRelativeUri("util/List.java", false);
        testRelativeUri("/util/List.java", true);
    }
    public static void main(String... args) {
        new T6411333().test(args);
    }
}
