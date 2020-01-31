










class WhereTypeVar<T extends String> {
    <T extends Integer> void test(T t) {
        m(t);
    }
    void m(T t) {}
}
