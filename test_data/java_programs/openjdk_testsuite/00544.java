

class T7034019c {
    interface A {
        abstract <T extends Number> T foo();
    }

    interface B {
        abstract <T> T foo();
    }

    static abstract class E implements A,B {
        void test() {
            foo();
        }
    }
}
