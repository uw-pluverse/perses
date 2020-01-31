

class T6476118c {
    static class A<T> {
        public void foo(T t) { }
    }

    static class B<T extends Number> extends A<T> {
        public void foo(T t) { }
    }

    static class C extends B<Integer> {
        public void foo(Object o) { }
        public void foo(Number o) { }
    }

    static class D extends C {} 
}
