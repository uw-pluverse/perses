

import java.io.Serializable;
import java.util.Calendar;



public class InferenceTest789 {

    private static void assertTrue(boolean b) {
        if(!b)
            throw new AssertionError();
    }

    public static void main(String[] args) {
        InferenceTest789 test = new InferenceTest789();
        test.method1(() -> 1);
        SAM1<? extends Number> sam1 = () -> 1.0;
        SAM1<? extends Serializable> sam1_2 = () -> "a";
        SAM1<? extends Comparable<?>> sam1_3 = () -> Calendar.getInstance();
        SAM1<?> sam1_4 = () -> 1.5f;

        SAM2<Number> sam2 = a -> 1;
        SAM2<? extends Serializable> sam2_2 = a -> 1;
    }

    void method1(SAM1<?> s) {
        System.out.println("s.m1()=" + s.m1() + " s.m1().getClass()=" + s.m1().getClass());
          assertTrue(s.m1().equals(new Integer(1)));
    }

    interface SAM1<T> {
        T m1();
    }

    interface SAM2<T extends Serializable> {
        T m2(T t);
    }
}
