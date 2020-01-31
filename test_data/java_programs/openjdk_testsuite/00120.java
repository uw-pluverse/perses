



public class T6650759b {

    interface A<X extends A<X, Y>, Y extends B<X>> {}

    static class B<X extends A<X, ?>> {}

    interface C<X extends A<X, Y>, Y extends B<X>> {}

    interface D<X extends A<X, Y>, Y extends B<X>> {}

    static class E<X extends A<X, Y>, Y extends B<X>, W extends C<X, Y>> implements D<X, Y> {

        static <X extends A<X, Y>, Y extends B<X>, W extends C<X, Y>> D<X, Y> of(W w) {
            return null;
        }
    }

    <X extends A<X, Y>, Y extends B<X>, W extends C<X, Y>, Z extends D<X, Y>> Z test(W w) {
        return (Z) E.of(w);
    }
}
