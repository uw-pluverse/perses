

class T6638712b<X> {

    <I extends T6638712b<T>, T> T m(I test) { return null; }

    void test(T6638712b<Integer> x) {
        String i = m(x);
    }
}
