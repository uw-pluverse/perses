



import org.testng.annotations.Test;

import static org.testng.Assert.assertEquals;



@Test
public class MethodReferenceTestSueCase2 {

    public interface Sam2<T> { public String get(T target, String s); }

    String instanceMethod(String s) { return "2"; }
    static Sam2<MethodReferenceTestSueCase2> var = MethodReferenceTestSueCase2::instanceMethod;

    String m() {  return var.get(new MethodReferenceTestSueCase2(), ""); }

    public void testSueCase2() {
        assertEquals(m(), "2");
    }
}
