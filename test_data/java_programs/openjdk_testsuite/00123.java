



public class T6650759j {

    static abstract class A<X extends A<X>> {}

    static abstract class B<X extends B<X, Y>, Y> extends A<X> {}

    static abstract class C<X extends C<X, Y>, Y> extends B<X, Y> {}

    interface D {}

    static class E extends C<E, D> {}

    static abstract class F<X extends F<X, Y>, Y extends A<Y>> extends A<X> {}

    static class G extends F<G, E> {}

    static <X extends F<X, Y>, Y extends A<Y>> X m(Iterable<X> it) {
        return null;
    }

    static G test(Iterable<G> c) {
        return m(c);
    }
}
