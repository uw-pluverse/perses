





class CantResolveLocationArgsParamsFragment {

    interface SAM {
        void m(Integer u);
    }

    void test() {
        SAM s = CantResolveLocationArgsParamsFragment::<String>f;
    }
}
