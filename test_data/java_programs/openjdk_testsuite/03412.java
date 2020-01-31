



class T6569057 {
    static class A<X extends B<?>> {  }

    static class B<X extends A<?>> {
        D<? extends B<X>> get() { return null; }
    }

    static class D<Y extends B<?>> {}

    <E extends B<?>> void test(E x, D<B<A<?>>> d) {
        boolean b = x.get() == d;
    }
}
