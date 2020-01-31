



class Pos08eff_final {

    interface Foo {}
    static class X1 extends Exception implements Foo {}
    static class X2 extends Exception implements Foo {}

    void m(boolean cond) {
        try {
            if (cond)
                throw new X1();
            else
                throw new X2();
        }
        catch (X1 | X2 ex) {}
    }
}
