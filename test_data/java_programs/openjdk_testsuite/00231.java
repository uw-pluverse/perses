

class Neg10 {
    static class Foo<X> {
        Foo(X x) {}
    }

    Foo<Number> fw = new Foo<>(1);
}
