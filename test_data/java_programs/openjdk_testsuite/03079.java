



class Conditional02 {

    <Z> void m1(Z z) { }
    <Z> void m2(Z... z) { }

    void test(boolean flag) {
        m1(flag ? "" : "");
        m2(flag ? "" : "");
        m2("", flag ? "" : "");
    }
}
