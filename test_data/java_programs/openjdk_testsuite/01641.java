

class Neg01eff_final {
    static class A extends Exception {}
    static class B1 extends A {}
    static class B2 extends A {}

    class Test {
        void m() throws A {
            try {
                throw new B1();
            } catch (A ex1) {
                try {
                    throw ex1; 
                } catch (B2 ex2) { }
            }
        }
    }
}
