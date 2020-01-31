
interface Foo<X extends Number> {
    void m(X x);
}

class FooLib {
    void m1(Foo<?> uf) { }
    void m2(Foo<? extends Object> uf) { }
}
