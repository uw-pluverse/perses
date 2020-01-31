





class CantResolveLocationArgsFragment {

    interface SAM {
        void m(Integer u);
    }

    void test() {
        SAM s = CantResolveLocationArgsFragment::f;
    }
}
