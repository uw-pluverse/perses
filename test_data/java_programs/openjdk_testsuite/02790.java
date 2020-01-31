



class T6400189c<T> {

    static class A {
        <T> T m(T6400189c<T> x) {
            return null;
        }
    }

    static class B<T> extends A {}

    void test(B b) {
        Integer i = b.m(new T6400189c<Integer>());
    }
}
