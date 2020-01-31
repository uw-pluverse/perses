



public class T6650759l {

    public static interface A<X> {}

    public static class B implements A<Integer> {}

    public static <X extends A<Y>, Y> Y m1(X x) {
        return null;
    }

    public static void m2(Integer i) {}

    public static void test(B b) {
        m2(m1(b));
    }
}
