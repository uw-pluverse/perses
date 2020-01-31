

class T7005095pos<T extends Integer> {
    interface Foo<T> {}

    static final class FooImpl implements Foo<String> {}

    Object o = (Foo<T>) new FooImpl();
}
