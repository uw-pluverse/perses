



class T5088429Pos02 {
    interface A {}
    interface B extends A {}

    void m(A... args) {}
    void m(B b, A... args) {}

    void test(B b) {
        m(b);
    }
}
