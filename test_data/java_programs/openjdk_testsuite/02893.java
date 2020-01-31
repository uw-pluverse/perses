
class MethodReference54 {

    interface SAM {
        void m();
    }

    void test() {
        nonExistent.m(MethodReference54::get);
    }

    static String get() { return ""; }
}
