



import org.testng.annotations.Test;
import java.lang.reflect.Array;

import static org.testng.Assert.assertEquals;



@Test
public class MethodReferenceTestVarArgs {

    interface SII {

        String m(Integer a, Integer b);
    }

    interface Siii {

        String m(int a, int b, int c);
    }

    interface Si {

        String m(int a);
    }

    interface SaO {

        String m(Object[] a);
    }

    interface Sai {

        String m(int[] a);
    }

    interface Svi {

        String m(int... va);
    }

    

    static String xvI(Integer... vi) {
        StringBuilder sb = new StringBuilder("xvI:");
        for (Integer i : vi) {
            sb.append(i);
            sb.append("-");
        }
        return sb.toString();
    }

    static String xIvI(Integer f, Integer... vi) {
        StringBuilder sb = new StringBuilder("xIvI:");
        sb.append(f);
        for (Integer i : vi) {
            sb.append(i);
            sb.append("-");
        }
        return sb.toString();
    }

    static String xvi(int... vi) {
        int sum = 0;
        for (int i : vi) {
            sum += i;
        }
        return "xvi:" + sum;
    }

    static String xIvi(Integer f, int... vi) {
        int sum = 0;
        for (int i : vi) {
            sum += i;
        }
        return "xIvi:(" + f + ")" + sum;
    }

    static String xvO(Object... vi) {
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

    public void testVarArgsSuperclass() {
        SII q;

        q = MethodReferenceTestVarArgs::xvO;
        assertEquals(q.m(55,66), "xvO:55*66*");
    }

    public void testVarArgsArray() {
        Sai q;

        q = MethodReferenceTestVarArgs::xvO;
        assertEquals(q.m(new int[] { 55,66 } ), "xvO:[55,66,]*");
    }

    public void testVarArgsII() {
        SII q;

        q = MethodReferenceTestVarArgs::xvI;
        assertEquals(q.m(33,7), "xvI:33-7-");

        q = MethodReferenceTestVarArgs::xIvI;
        assertEquals(q.m(50,40), "xIvI:5040-");

        q = MethodReferenceTestVarArgs::xvi;
        assertEquals(q.m(100,23), "xvi:123");

        q = MethodReferenceTestVarArgs::xIvi;
        assertEquals(q.m(9,21), "xIvi:(9)21");
    }

    public void testVarArgsiii() {
        Siii q;

        q = MethodReferenceTestVarArgs::xvI;
        assertEquals(q.m(3, 2, 1), "xvI:3-2-1-");

        q = MethodReferenceTestVarArgs::xIvI;
        assertEquals(q.m(888, 99, 2), "xIvI:88899-2-");

        q = MethodReferenceTestVarArgs::xvi;
        assertEquals(q.m(900,80,7), "xvi:987");

        q = MethodReferenceTestVarArgs::xIvi;
        assertEquals(q.m(333,27, 72), "xIvi:(333)99");
    }

    public void testVarArgsi() {
        Si q;

        q = MethodReferenceTestVarArgs::xvI;
        assertEquals(q.m(3), "xvI:3-");

        q = MethodReferenceTestVarArgs::xIvI;
        assertEquals(q.m(888), "xIvI:888");

        q = MethodReferenceTestVarArgs::xvi;
        assertEquals(q.m(900), "xvi:900");

        q = MethodReferenceTestVarArgs::xIvi;
        assertEquals(q.m(333), "xIvi:(333)0");
    }

    

    public void testVarArgsaO() {
        SaO q;

        q = MethodReferenceTestVarArgs::xvO;
        assertEquals(q.m(new String[] { "yo", "there", "dude" }), "xvO:yo*there*dude*");
    }


}
