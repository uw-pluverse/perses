


class T8130304b {

    void test() {
        TestZ r = null;
        Crazy<String, String> x = r.m3("X");
        r.m1(r.m4(r.m2(x, r.m3("a")), t -> "x"), r.m3("a"));
    }

    interface Crazy<A, B> { }

    interface TestZ {
        public <A, B> Crazy<A, B> m1(Crazy<A, ? extends B>... d);
        public <A, B, C> Crazy<A, Crazy<B, C>> m2(Crazy<A, B> e, Crazy<A, C> f);
        public <A> Crazy<A, A> m3(A g);
        public <A, B, C> Crazy<A, C> m4(Crazy<A, B> h, java.util.function.Function<B, C> i);
    }
}
