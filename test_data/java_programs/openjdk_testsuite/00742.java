



import java.io.File;

public class T6422327 extends ToolTester {
    void test(String... args) {
        File file = new File(test_src, "T6422327.other");
        try {
            task = tool.getTask(null, fm, null, null, null, fm.getJavaFileObjects(file));
            throw new AssertionError("Expected exception not thrown");
        } catch (IllegalArgumentException e) {
            System.err.println("OK, got expected exception: " + e.getLocalizedMessage());
        }
    }
    public static void main(String... args) {
        new T6422327().test(args);
    }
}
