



import java.io.File;
import java.io.Serializable;
import java.util.Date;
import java.util.Calendar;
import java.util.TimeZone;

public class InferenceTest3 {

    private static void assertTrue(boolean cond) {
        if (!cond)
            throw new AssertionError();
    }

    public static void main(String[] args) {
        InferenceTest3 test = new InferenceTest3();
        test.m1(a -> a.getTime());
        test.m2(a -> a.toString());

        C<String, Integer> c = a -> a.length();
        assertTrue(c.m("lambda") == 6);

        E<Double, String> e = a -> Double.toHexString(a);
        assertTrue(e.m(Double.MAX_VALUE).equals("0x1.fffffffffffffp1023"));
        assertTrue(e.m(Double.MIN_VALUE).equals("0x0.0000000000001p-1022"));
        assertTrue(e.m(1.0).equals("0x1.0p0"));
    }

    private void m1(C<Date, Long> c) {
        Calendar cal = Calendar.getInstance(TimeZone.getTimeZone("GMT"));
        cal.set(1970, 0, 1, 0, 0, 0);
        cal.set(Calendar.MILLISECOND, 0);
        Date date = cal.getTime();
        assertTrue(c.m(date) == 0L);
    }

    private void m2(E<Integer, String> e) {
        assertTrue(e.m(2).equals("2"));
    }

    interface A<T extends Serializable, U> {
        U m(T t);
    }

    interface C<X extends Serializable, Y extends Number> extends A<X,Y> {}

    interface E<X extends Serializable, Y extends String> extends A<X,Y> {}
}
