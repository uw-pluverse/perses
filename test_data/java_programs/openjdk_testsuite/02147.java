



class T5088429Pos01 {
    interface A {}
    interface B extends A {}

    T5088429Pos01(A... args) {}
    T5088429Pos01(B b, A... args) {}

    void test(B b) {
        new T5088429Pos01(b);
    }
}
