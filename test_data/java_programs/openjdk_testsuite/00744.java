



import java.util.Arrays;
import javax.tools.*;

public class T6257235 {
    public static void main(String... args) {
        JavaCompiler javac = ToolProvider.getSystemJavaCompiler();
        try {
            javac.getTask(null, null, null, Arrays.asList("seetharam", "."), null, null);
            throw new AssertionError("Expected IllegalArgumentException");
        } catch (IllegalArgumentException ex) { }
    }
}
