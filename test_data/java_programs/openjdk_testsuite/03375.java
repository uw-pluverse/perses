

class T8012003a {
    void m1(Integer i) { }

    void m2(Integer i) { }
    void m2(Integer i, Object o) { }

    void m3(Integer i) { }
    void m3(String s) { }

    void test() {
        m1("");
        m1(false ? "" : "");
        m2("");
        m3('x');
    }
}
