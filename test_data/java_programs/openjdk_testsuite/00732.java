



import javax.tools.JavaFileObject;
import static java.util.Collections.singleton;

public class T6410643 extends ToolTester {

    void testGetTask(Iterable<String> options,
                     Iterable<String> classes,
                     Iterable<? extends JavaFileObject> compilationUnits) {
        try {
            task = tool.getTask(null, null, null, null, null, singleton((JavaFileObject)null));
            throw new AssertionError("Error expected");
        } catch (NullPointerException e) {
            System.err.println("Expected error occurred: " + e);
        }
    }

    void test(String... args) {
        task = tool.getTask(null, null, null, null, null, null);
        if (task.call())
            throw new AssertionError("Error expected");
        System.err.println("Compilation failed as expected!");
        Iterable<String>         s = singleton(null);
        Iterable<JavaFileObject> f = singleton(null);
        
        testGetTask(null, null, f);
        testGetTask(null, s,    null);
        testGetTask(null, s,    f);
        testGetTask(s,    null, null);
        testGetTask(s,    null, f);
        testGetTask(s,    s,     null);
        testGetTask(s,    s,    f);
        System.err.println("Test result: PASSED");
    }
    public static void main(String... args) {
        new T6410643().test(args);
    }
}
