



import org.testng.annotations.Test;

import static org.testng.Assert.assertEquals;



@Test
public class MethodReferenceTestSueCase4 {

    public interface Sam2<T> { public String get(T target, String s); }

    Sam2<Target> var = new Object().equals(new Object()) ? Target::instanceMethod : Target::instanceMethod;

    String m() {
        return var.get(new Target(), "");
    }

    static class Target {
        String instanceMethod(String s) { return "2"; }
    }

    public void testSueCase4() {
        assertEquals(m(), "2");
    }
}
