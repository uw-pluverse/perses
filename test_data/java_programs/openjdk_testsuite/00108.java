


class T8020149 {
    static class TestData<X,Y> { }

    interface Foo<X, Y extends Foo<X, Y>> { }

    interface IntFoo extends Foo<Integer, IntFoo> { }

    interface Function<X, Y> {
        Y apply(X x);
    }

    void test(TestData<Integer, IntFoo> data) {
       m1(data, s->s);
       m2(data, s->s);
    }

    <E, E_OUT extends Foo<E, E_OUT>, W, W_IN extends Foo<W, W_IN>> void m1(TestData<W, W_IN> data, Function<W_IN, E_OUT> m) {  }
    <W, W_IN extends Foo<W, W_IN>, E, E_OUT extends Foo<E, E_OUT>> void m2(TestData<W, W_IN> data, Function<W_IN, E_OUT> m) {  }
}
