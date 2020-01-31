



public class T6650759g {

    static abstract class A<X extends A<X>> {}

    static abstract class B<X extends A<X>> {}

    interface C<X, Y> {}

    static abstract class D<X extends A<X>, Y extends B<X>> implements C<X, Y> {}

    static class E extends A<E> {}

    static class F extends B<E> {}

    static void test(Iterable<E> data) {
        m3(m2(data, m1(F.class)));
    }

    static <X extends A<X>, Y extends B<X>> D<X, Y> m1(Class<Y> c) {
        return null;
    }

    static <U, V> Iterable<V> m2(Iterable<U> x1, C<? super U, ? extends V> x2) {
        return null;
    }

    static void m3(Iterable<F> data) {
    }
}
