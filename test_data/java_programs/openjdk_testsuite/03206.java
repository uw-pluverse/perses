



import org.testng.annotations.Test;

import static org.testng.Assert.assertEquals;



class MethodReferenceTestInstance_E {
    String xI(Integer i) {
        return "ExI:" + i;
    }
}

@Test
public class MethodReferenceTestInstance {

    interface SI { String m(Integer a); }

    String xI(Integer i) {
        return "xI:" + i;
    }

    public void testMethodReferenceInstance() {
        SI q;

        q = this::xI;
        assertEquals(q.m(55), "xI:55");
    }

    public void testMethodReferenceExternal() {
        SI q;

        q = (new MethodReferenceTestInstance_E())::xI;
        assertEquals(q.m(77), "ExI:77");
    }

}
