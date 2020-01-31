
class MethodReference40 {

    static class Sup {
        class Inner {
            Inner(String val) { }
        }
    }

    static class Sub extends Sup {

        interface SAM { Sup.Inner m(Sub x, String str); }

        void test() {
            SAM var = Sub.Inner::new;
        }
    }
}
