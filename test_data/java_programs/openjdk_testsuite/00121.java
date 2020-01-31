



public class T6650759k {

    static class A<X extends A> {}

    static class B<X extends B, Y extends A> {}

    <U extends A<U>, V extends B<V, U>> Object m(Class<V> c) {
        return null;
    }

    <U extends A<U>, V extends B<V, U>> void test(Class<V> c) {
        m(c);
    }
}
