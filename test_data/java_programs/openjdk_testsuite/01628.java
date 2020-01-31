

class Neg01 {
    static class A extends Exception {}
    static class B1 extends A {}
    static class B2 extends A {}

    class Test {
        void m() throws A {
            try {
                throw new B1();
            } catch (final A ex1) {
                try {
                    throw ex1; 
                } catch (B2 ex2) { }
            }
        }
    }
}
