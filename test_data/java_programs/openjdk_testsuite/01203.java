




class MulticatchNotSupported {
    class E1 extends Exception { }
    class E2 extends Exception { }

    void e1() throws E1 { }
    void e2() throws E2 { }

    void m() {
        try {
            e1();
            e2();
        } catch (final E1 | E2 e) {
            e.printStackTrace();
        }
    }
}
