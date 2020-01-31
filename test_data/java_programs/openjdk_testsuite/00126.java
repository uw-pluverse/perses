



import java.util.List;

public class T6650759e {

    static abstract class A<X extends B> {}

    interface B<X extends A> extends D {}

    static abstract class C<X extends D> {}

    interface D {}

    static abstract class E<X extends C<? extends B<?>>> {}

    <U extends C<V>, V extends B<W>, W extends A<V>> W m1(E<U> e) {
        return m2(e);
    }

    <U extends C<V>, V extends B<W>, W extends A<V>> W m2(E<U> e) {
        return null;
    }
}
