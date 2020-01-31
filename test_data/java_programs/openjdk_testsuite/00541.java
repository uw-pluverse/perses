



class T7034019a {
    interface A {
        <T> void foo();
    }

    interface B {
        void foo();
    }

    static abstract class E implements A,B {
        void test() {
            foo();
        }
    }
}
