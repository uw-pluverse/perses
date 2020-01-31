



class NestedInvocationsTest<T> {
    boolean foo(I<T> i) {
        return baz(zas(i));
    }

    <U> J<U, Boolean> zas(I<U> i) {
        return null;
    }

    <R> R baz(J<T, R> j) {
        return null;
    }

    interface I<I1> {}

    interface J<J1, J2> {}
}
