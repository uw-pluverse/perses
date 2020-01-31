










class OverrideBridge1 {
    static class A<T> {
        public void foo(T t) { }
    }
    static class B extends A<String> {
        public void foo(String t) { }
    }
}
