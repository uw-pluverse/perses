



class T6665356b<T> {

    class A<S> {}
    class B<X> extends A<X> {}

    void cast(A<? extends Number> a) {
        Object o = (B<? extends Integer>)a;
    }
}
