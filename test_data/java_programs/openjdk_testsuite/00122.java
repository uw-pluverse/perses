



public class T6650759d {

    static abstract class A<X> {

        static <T> A<T> m(Iterable<? extends T> elements) {
            return null;
        }
    }

    static abstract class B {}

    static abstract class C<X extends B> {}

    <U extends C<V>, V extends B> Iterable<V> get(U u) {
        return null;
    }

    <U extends C<V>, V extends B> void m(U u) {
        A<V> a = A.m(get(u));
    }
}
