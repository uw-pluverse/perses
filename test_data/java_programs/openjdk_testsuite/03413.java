



class T6932571b {

    interface A1<T extends B<? super T>> {
        public T getT();
    }

    interface A2<T extends B<? extends T>> {
        public T getT();
    }

    class B<T extends B<T>> {}

    class C extends B<C> {}

    void test1(A1<?> a) {
        Object o = (C)a.getT();
    }

    void test2(A2<?> a) {
        Object o = (C)a.getT();
    }
}
