

class TargetType28 {
    static class SuperFoo<X> {}

    static class Foo<X extends Number> extends SuperFoo<X> {}

    interface A<X, Y> {
       SuperFoo<Y> m(X x);
    }

    <Z, R> SuperFoo<R> apply(A<Z, R> ax, Z x) { return null; }

    SuperFoo<String> ls = apply(x-> new Foo<>(), 1);
    SuperFoo<Integer> li = apply(x-> new Foo<>(), 1);
    SuperFoo<?> lw = apply(x-> new Foo<>(), 1);
}
