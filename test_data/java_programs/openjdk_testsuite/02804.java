

class T6758789a {
    class Foo<T> {}

    <X> void m(Foo<X> foo) {}

    void test() {
        m(new Foo());
    }
}
