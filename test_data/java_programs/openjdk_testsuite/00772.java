



import java.util.Collections;

public class T6421756 extends ToolTester {
    void test(String... args) {
        Iterable<String> options = Collections.singleton("-verbose");
        try {
            task = tool.getTask(null, fm, null, null, options, null);
            throw new AssertionError("Expected IllegalArgumentException!");
        } catch (IllegalArgumentException e) {
            System.out.println("OK: got expected error " + e.getLocalizedMessage());
        }
    }
    public static void main(String... args) {
        new T6421756().test(args);
    }
}
