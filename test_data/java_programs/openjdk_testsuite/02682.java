

class A {

    class A1 {
    }

    static class A2 extends B {
    }

    static class A3 extends B.Inner {
    }

    class A4 {
        void m1() {
            class A3m1 { }
        }

        void m2() {
            new B() {
            };
        }
    }

}
