

class TargetType10 {
    interface Function<A,R> {
        R apply(A a);
    }

    static class Test {
        <A,B,C> Function<A,C> compose(Function<B,C> g, Function<A,? extends B> f) { return null; }
        { compose(x ->  "a" + x, x -> x + "b"); }
    }
}
