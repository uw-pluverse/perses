



class Pos07 {

    static class A extends Exception { public void m() {}; public Object f;}
    static class B1 extends A {}
    static class B2 extends A {}

    void m() throws B1, B2 {
        try {
            if (true) {
                throw new B1();
            }
            else {
                throw new B2();
            }
        } catch (Exception ex) { 
            throw ex;
        }
    }
}
