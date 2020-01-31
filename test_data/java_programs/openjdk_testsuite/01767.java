



class Pos10 {
    interface Function<X,Y> {
        Y apply(X x);
    }

    interface A<T> {
        default <R> void m(Function<T,R> f) { Impl.<T,R>m(this, f); }
    }

    static class Impl {
        static <T,R> void m(A<T> a, Function<T,R> f) {  }
    }
}
