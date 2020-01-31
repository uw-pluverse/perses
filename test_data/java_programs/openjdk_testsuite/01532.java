




class InconvertibleTypes {
    class Outer<S> {
        class Inner<T> {}
    }

    void m(Outer<Integer>.Inner<Long> p) {
        Object o = (Outer<? super Number>.Inner<Long>)p;
    }
}
