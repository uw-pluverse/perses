



import java.util.Arrays;

public class T6423003 extends ToolTester {
    void test(String... args) {
        task = tool.getTask(null, fm, null, Arrays.asList("-Xlint:all"), null, null);
        try {
            task.call();
        } catch (IllegalStateException ex) {
            return;
        }
        throw new AssertionError("Expected IllegalStateException not thrown");
    }
    public static void main(String... args) {
        new T6423003().test(args);
    }
}
