



import java.util.Collections;

public class T6650759f {

    interface A<X extends A> {}

    static abstract class B<X extends B> implements A<X> {}

    static abstract class C<X extends D> extends B<X> {}

    static class D extends C<D> {}

    <X extends B, Y extends B<X>> Iterable<X> m(Y node) {
        return null;
    }

    public void test(D d) {
        Iterable<D> ops = (true) ? Collections.singletonList(d) : m(d);
    }
}
