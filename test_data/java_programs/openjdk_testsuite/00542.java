

class T7034019c {
    interface A {
        abstract <T extends Number> T foo();
    }

    interface B {
        abstract <T> T foo();
    }

    static class C<T extends A & B> {
        void test(T x) {
            x.foo();
        }
    }
}
