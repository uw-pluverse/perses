




class IllegalStaticIntfMethCall {
    interface A {
        static void m() { }
    }
    void test(A a) {
        a.m();
    }
}
