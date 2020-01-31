



class T5088429Neg01 {
    interface A {}
    interface B extends A {}

    T5088429Neg01(A... args) {}
    T5088429Neg01(A a, A... args) {}

    void test(B b) {
        new T5088429Neg01(b);
    }
}
