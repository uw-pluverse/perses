


class FunctionalInterfaceAnno02 {
    interface Foo<T, N extends Number> {
        void m(T arg);
        void m(N arg);
    }

    @FunctionalInterface
    interface Baz extends Foo<Integer, Integer> { }
}
