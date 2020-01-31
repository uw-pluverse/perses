



class T7005095pos<T extends CharSequence> {
    interface Foo<T> {}

    static final class FooImpl implements Foo<String> {}

    Object o = (Foo<T>) new FooImpl();
}
