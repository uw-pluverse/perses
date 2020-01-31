


public class T6650759i {

    static class A<X extends A, Y extends B> {}

    static class B<X extends B> {}

    static class C<X extends A<X, Y>, Y extends B<Y>> {}

    static <U extends A<U, V>, V extends B<V>> Class<U> m1(U x) {
        return null;
    }

    static <U extends A<U, V>, V extends B<V>> U m2(Class<U> c) {
        return null;
    }

    static <W, U extends A<U, V>, V extends B<V>> W m3(Class<W> c1, C<U, V> c2) {
        return null;
    }

    static <U extends A<U, V>, V extends B<V>> void test(U u, C<U, V> c) {
        m2(m1(u));
        U res = m3(m1(u), c);
    }
}
