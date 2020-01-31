






class UncheckedMethodInvocation {
    class X<T> {}

    public <T> void m(X<T> x, T t) {}

    public void test() {
        m(new X<X<Integer>>(), new X());
    }
}
