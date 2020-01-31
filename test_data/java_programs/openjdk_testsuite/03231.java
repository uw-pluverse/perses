



import org.testng.annotations.Test;

import static org.testng.Assert.assertEquals;



@Test
public class MethodReferenceTestSueCase1 {

    public interface Sam2<T> { public String get(T target, String s); }

    String instanceMethod(String s) { return "2"; }
    Sam2<MethodReferenceTestSueCase1> var = MethodReferenceTestSueCase1::instanceMethod;

    String m() {  return var.get(new MethodReferenceTestSueCase1(), ""); }

    public void testSueCase1() {
        assertEquals(m(), "2");
    }
}
