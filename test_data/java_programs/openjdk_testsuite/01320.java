




class NonStaticCantBeRefFragment {

    interface SAM {
        void m(Integer u);
    }

    void f(Integer i) { }

    static void test() {
        SAM s = NonStaticCantBeRefFragment::f;
    }
}
