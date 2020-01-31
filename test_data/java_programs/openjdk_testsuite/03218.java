



import org.testng.annotations.Test;
import java.lang.reflect.Array;

import static org.testng.Assert.assertEquals;



interface MethodReferenceTestVarArgsSuperDefault_I {

    default String xvI(Integer... vi) {
        StringBuilder sb = new StringBuilder("xvI:");
        for (Integer i : vi) {
            sb.append(i);
            sb.append("-");
        }
        return sb.toString();
    }

    default String xIvI(Integer f, Integer... vi) {
        StringBuilder sb = new StringBuilder("xIvI:");
        sb.append(f);
        for (Integer i : vi) {
            sb.append(i);
            sb.append("-");
        }
        return sb.toString();
    }

    default String xvi(int... vi) {
        int sum = 0;
        for (int i : vi) {
            sum += i;
        }
        return "xvi:" + sum;
    }

    default String xIvi(Integer f, int... vi) {
        int sum = 0;
        for (int i : vi) {
            sum += i;
        }
        return "xIvi:(" + f + ")" + sum;
    }

    default String xvO(Object... vi) {
        StringBuilder sb = new StringBuilder("xvO:");
        for (Object i : vi) {
            if (i.getClass().isArray()) {
                sb.append("[");
                int len = Array.getLength(i);
                for (int x = 0; x < len; ++x)  {
                    sb.append(Array.get(i, x));
                    sb.append(",");
                }
                sb.append("]");

            } else {
                sb.append(i);
            }
            sb.append("*");
        }
        return sb.toString();
    }
}

@Test
public class MethodReferenceTestVarArgsSuperDefault implements MethodReferenceTestVarArgsSuperDefault_I {

    interface DSPRII { String m(Integer a, Integer b); }

    interface DSPRiii { String m(int a, int b, int c); }

    interface DSPRi { String m(int a); }

    interface DSPRaO { String m(Object[] a); }

    interface DSPRai { String m(int[] a); }

    interface DSPRvi { String m(int... va); }

    

    public void testVarArgsSPRSuperclass() {
        DSPRII q;

        q = MethodReferenceTestVarArgsSuperDefault_I.super::xvO;
        assertEquals(q.m(55,66), "xvO:55*66*");
    }

    public void testVarArgsSPRArray() {
        DSPRai q;

        q = MethodReferenceTestVarArgsSuperDefault_I.super::xvO;
        assertEquals(q.m(new int[] { 55,66 } ), "xvO:[55,66,]*");
    }

    public void testVarArgsSPRII() {
        DSPRII q;

        q = MethodReferenceTestVarArgsSuperDefault_I.super::xvI;
        assertEquals(q.m(33,7), "xvI:33-7-");

        q = MethodReferenceTestVarArgsSuperDefault_I.super::xIvI;
        assertEquals(q.m(50,40), "xIvI:5040-");

        q = MethodReferenceTestVarArgsSuperDefault_I.super::xvi;
        assertEquals(q.m(100,23), "xvi:123");

        q = MethodReferenceTestVarArgsSuperDefault_I.super::xIvi;
        assertEquals(q.m(9,21), "xIvi:(9)21");
    }

    public void testVarArgsSPRiii() {
        DSPRiii q;

        q = MethodReferenceTestVarArgsSuperDefault_I.super::xvI;
        assertEquals(q.m(3, 2, 1), "xvI:3-2-1-");

        q = MethodReferenceTestVarArgsSuperDefault_I.super::xIvI;
        assertEquals(q.m(888, 99, 2), "xIvI:88899-2-");

        q = MethodReferenceTestVarArgsSuperDefault_I.super::xvi;
        assertEquals(q.m(900,80,7), "xvi:987");

        q = MethodReferenceTestVarArgsSuperDefault_I.super::xIvi;
        assertEquals(q.m(333,27, 72), "xIvi:(333)99");
    }

    public void testVarArgsSPRi() {
        DSPRi q;

        q = MethodReferenceTestVarArgsSuperDefault_I.super::xvI;
        assertEquals(q.m(3), "xvI:3-");

        q = MethodReferenceTestVarArgsSuperDefault_I.super::xIvI;
        assertEquals(q.m(888), "xIvI:888");

        q = MethodReferenceTestVarArgsSuperDefault_I.super::xvi;
        assertEquals(q.m(900), "xvi:900");

        q = MethodReferenceTestVarArgsSuperDefault_I.super::xIvi;
        assertEquals(q.m(333), "xIvi:(333)0");
    }

    

    public void testVarArgsSPRaO() {
        DSPRaO q;

        q = MethodReferenceTestVarArgsSuperDefault_I.super::xvO;
        assertEquals(q.m(new String[] { "yo", "there", "dude" }), "xvO:yo*there*dude*");
    }


}
