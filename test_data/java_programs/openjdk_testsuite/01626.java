

class Neg02 {
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
        } catch (final A | B ex) {
            ex = new B();
        }
    }
}
