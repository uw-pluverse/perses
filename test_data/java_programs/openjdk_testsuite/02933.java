
class Main {
    void test() {
        m(new A(new Object()));
        m(new A(null));
    }

    void m(Object o) {}
}
