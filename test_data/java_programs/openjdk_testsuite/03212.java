



import org.testng.annotations.Test;

import static org.testng.Assert.assertEquals;



@Test
public class MethodReferenceTestNewInner {

    String note = "NO NOTE";

    interface M0<T> {

        T m();
    }

    interface MP<T> {

        T m(MethodReferenceTestNewInner m);
    }

    class N0 {

        N0() {
        }
    }

    interface M1<T> {

        T m(Integer a);
    }

    class N1 {

        int i;

        N1(int i) {
            this.i = i;
        }
    }

    interface M2<T> {

        T m(Integer n, String o);
    }

    class N2 {

        Number n;
        Object o;

        N2(Number n, Object o) {
            this.n = n;
            this.o = o;
        }

        public String toString() {
            return note + ":N2(" + n + "," + o + ")";
        }
    }

    interface MV {

        NV m(Integer ai, int i);
    }

    class NV {

        int i;

        NV(int... v) {
            i = 0;
            for (int x : v) {
                i += x;
            }
        }

        public String toString() {
            return note + ":NV(" + i + ")";
        }
    }


    public void testConstructorReference0() {
        M0<N0> q;

        q = N0::new;
        assertEquals(q.m().getClass().getSimpleName(), "N0");
    }

    public void testConstructorReference1() {
        M1<N1> q;

        q = N1::new;
        assertEquals(q.m(14).getClass().getSimpleName(), "N1");
    }

    public void testConstructorReference2() {
        M2<N2> q;

        note = "T2";
        q = N2::new;
        assertEquals(q.m(7, "hi").toString(), "T2:N2(7,hi)");
    }

    

}
