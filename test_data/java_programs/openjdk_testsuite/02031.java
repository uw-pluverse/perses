
class Outer {
    void m1(String s) { }
    void m2(int i1, int i2) { }

    class Inner {
        void test() {
           
           m1("");
        }
    }

    class Inner1 {
        void m1(Integer i) { }

        void test() {
           
           m1("");
        }
    }

    class Inner2 {
        private void m1(Integer i) { }
        private void m1(Double d) { }

        void test() {
           
           m1("");
        }
    }

    class Inner3 {
        private void m2(Object o, int i) { }
        private void m2(int i, Object o) { }

        void test() {
           
           m2(1, 1);
        }
    }

    class Inner4 extends Inner2 {
        void test() {
           
           m1("");
        }
    }

    class Inner5 extends Inner3 {
        void test() {
           
           m2(1, 1);
        }
    }
}
