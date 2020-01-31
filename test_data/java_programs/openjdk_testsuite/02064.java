



class TestAnnotatedAnonClass {
    void m() {
        Object o = new @Deprecated Object() { };
    }
}
