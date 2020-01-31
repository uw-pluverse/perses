





class MissingReturnValueFragment {
    interface SAM {
        String m();
    }

    void test() {
        SAM s = ()->{};
    }
}
