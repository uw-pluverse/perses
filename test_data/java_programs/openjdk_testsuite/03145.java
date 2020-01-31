

class TargetType40 {
    void m(String s) { }
    void m(Integer i) { }

    void void_method() {}

    void test() {
       m(void_method());
    }
}
