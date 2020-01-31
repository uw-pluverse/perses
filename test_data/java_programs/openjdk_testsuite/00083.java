
class T8019824 {
    void test(Class<? extends Foo<?, ?>> cls) {
        Foo<?, ?> foo = make(cls);
    }

    <A, B, C extends Foo<A, B>> Foo<A, B> make(Class<C> cls) { return null; }

    interface Foo<A, B> {}
}
