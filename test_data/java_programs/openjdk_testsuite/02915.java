

import java.util.*;



public class InferenceTest2b {

    private static void assertTrue(boolean cond) {
        if (!cond)
            throw new AssertionError();
    }

    public static void main(String[] args) {

        InferenceTest2b test = new InferenceTest2b();

        test.m1((a, b) -> {return a;});
        test.m2((a, b) -> {return a;});
        test.m3((a, b) -> a);
    }

    interface SAM6<T> {
        T m6(T a, T b);
    }

    void m1(SAM6<? super List<?>> s) {
        System.out.println("m1()");
        Stack<String> a = new Stack<String>();
        ArrayList<String> b = new ArrayList<String>();
        assertTrue(s.m6(a, b) == a);

        Vector<?> c = null;
        assertTrue(s.m6(c, b) == c);
    }

    void m2(SAM6<? super Integer> s) {
        System.out.println("m2()");
        assertTrue(s.m6(1, 2).equals(Integer.valueOf(1)));
    }

    void m3(SAM6<? super Calendar> s) {
        System.out.println("m3()");
        Calendar gc = Calendar.getInstance();
        GregorianCalendar gc2 = new GregorianCalendar();
        assertTrue(s.m6(gc, gc2) == gc);
    }
}
