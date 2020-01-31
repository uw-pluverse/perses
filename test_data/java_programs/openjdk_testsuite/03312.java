


class MethodReference57 {

    interface F {
        <X> void m();
    }

    void test() {
        F f = this::g; 
    }

    void g() { }
}
