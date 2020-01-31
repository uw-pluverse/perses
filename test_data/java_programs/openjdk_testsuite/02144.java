



class T5088429Neg02 {
    interface A {}
    interface B extends A {}

    void m(A... args) {}
    void m(A a, A... args) {}

    void test(B b) {
        m(b);
    }
}
