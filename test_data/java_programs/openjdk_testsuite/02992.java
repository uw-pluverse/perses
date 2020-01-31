
class MethodReference62 {
    interface SAM {
        int m();
    }

    static abstract class Sup {
        abstract int foo() ;
    }

    static abstract class Sub extends Sup {
        abstract int foo() ;
        void test() {
            SAM s = super::foo;
        }
    }
}
