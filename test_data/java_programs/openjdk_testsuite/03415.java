



class T6932571a {
    static class A<T extends Comparable<? super T>> {
        public void test(T v) {
            Object obj = (Integer)v;
        }
    }

    static class B<T extends Comparable<? extends T>> {
        public void test(T v) {
            Object obj = (Integer)v;
        }
    }
}
