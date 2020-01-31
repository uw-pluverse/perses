



import com.sun.tools.javac.util.Assert;
import java.util.function.*;

public class MethodReferenceNullCheckTest {
    public static void main(String[] args) {
        String s = null;
        boolean npeFired = false;
        try {
            Supplier<Boolean> ss = s::isEmpty;
        } catch (NullPointerException npe) {
            npeFired = true;
        } finally {
            Assert.check(npeFired, "NPE should have been thrown");
        }
    }
}
