







class CantApplySymbolFragment {

    interface SAM {
        void m(Integer u);
    }

    static void f(String s) { }

    void test() {
        SAM s = CantApplySymbolFragment::f;
    }
}
