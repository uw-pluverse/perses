

class T6722234a<T extends String> {
    <T extends Integer> void test(T t) {
        m(t);
    }
    void m(T t) {}
}
