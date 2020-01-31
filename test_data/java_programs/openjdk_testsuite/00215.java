

class T6939780 {

    static class Foo<X extends Number> {
        Foo() {}
        Foo(X x) {}
    }

    void testAssign() {
        Foo<Number> f1 = new Foo<Number>(1);
        Foo<?> f2 = new Foo<Number>();
        Foo<?> f3 = new Foo<Integer>();
        Foo<Number> f4 = new Foo<Number>(1) {};
        Foo<?> f5 = new Foo<Number>() {};
        Foo<?> f6 = new Foo<Integer>() {};
    }

    void testMethod() {
        gn(new Foo<Number>(1));
        gw(new Foo<Number>());
        gw(new Foo<Integer>());
        gn(new Foo<Number>(1) {});
        gw(new Foo<Number>() {});
        gw(new Foo<Integer>() {});
    }

    void gw(Foo<?> fw) { }
    void gn(Foo<Number> fn) { }

    static class Foo2<X> {
        X copy(X t) {
            return t;
        }
    }

    void testReciever() {
        Number s = new Foo2<Number>().copy(0);
    }

}
