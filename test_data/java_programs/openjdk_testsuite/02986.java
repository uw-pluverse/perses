


class NestedCapture01 {

    void test(String s) {
       g(m(s.getClass()));
    }

    <F extends String> F m(Class<F> cf) {
       return null;
    }

    <P extends String> P g(P vo) {
       return null;
    }
}
