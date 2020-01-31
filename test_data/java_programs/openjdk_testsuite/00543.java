



class T7034019a {
    interface A {
        abstract <T> void foo();
    }

    interface B {
        abstract void foo();
    }

    static class C<T extends A & B> {
        void test(T x) {
            x.foo();
        }
    }
}
