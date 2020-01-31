



class T4756416 {
    static class C<A> { A id ( A x) { return x; } }
    interface I<A> { A id(A x); }
    static class D extends C<String> implements I<Integer> {
        public String id(String x) { return x; }
        public Integer id(Integer x) { return x; }
    }
}
