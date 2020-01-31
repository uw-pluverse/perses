
class MethodReference39 {

    static class Sup {}


    static class Sub extends Sup {

        interface SAM { Sup m(Sup x, String str); }

        class Inner extends Sup {
            Inner(String val) { }
        }

        void test() {
            SAM var = Sub.Inner::new;;
        }
    }
}
