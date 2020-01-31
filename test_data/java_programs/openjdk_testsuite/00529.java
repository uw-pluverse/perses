

class T6946618c {
    static class C<T> { }

    void test() {
        C<?> c1 = new C<? extends String>();
        C<?> c2 = new C<? super String>();
        C<?> c3 = new C<?>();
    }
}
