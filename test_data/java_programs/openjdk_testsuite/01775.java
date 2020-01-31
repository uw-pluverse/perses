

class NoWarn {
    void m(Object... args) { }
    void foo() {
        m(null);
    }
}
