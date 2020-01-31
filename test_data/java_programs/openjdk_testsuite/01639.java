



class Pos09 {

    static class Foo<X> {
       Foo(X x) {}
    }

    static interface Base<X> {}
    static class A extends Exception implements Base<String> {}
    static class B extends Exception implements Base<Integer> {}

    void m() {
        try {
            if (true) {
                throw new A();
            }
            else {
                throw new B();
            }
        } catch (A | B ex) {
            Foo<?> f = new Foo<>(ex);
        }
    }
}
