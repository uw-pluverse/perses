









class CantApplySymbolsFragment {

    interface SAM {
        void m(Integer u);
    }

    static void f() { }

    static void f(String s) { }

    void test() {
        SAM s = CantApplySymbolsFragment::f;
    }
}
