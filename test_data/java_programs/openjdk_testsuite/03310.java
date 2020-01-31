


class MostSpecific11 {

    interface I { Object run(); }
    interface J { String run(); }

    void m(I arg) {}
    void m(J arg) {}

    void test() {
        m(() -> { throw new RuntimeException(); });
    }

}
