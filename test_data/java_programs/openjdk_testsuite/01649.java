

class Neg02eff_final {
    static class A extends Exception {}
    static class B extends Exception {}

    void m() {
        try {
            if (true) {
                throw new A();
            }
            else {
                throw new B();
            }
        } catch (A | B ex) {
            ex = new B();
        }
    }
}
