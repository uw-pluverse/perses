



class Pos03 {

    static class A extends Exception { public void m() {}; public Object f;}
    static class B1 extends A {}
    static class B2 extends A {}

    void m() {
        try {
            if (true) {
                throw new B1();
            }
            else {
                throw new B2();
            }
        } catch (final B1 | B2 ex) {
            ex.m();
            System.out.println(ex.f);
        }
    }
}
