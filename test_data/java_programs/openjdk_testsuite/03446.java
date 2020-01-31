

class A<T extends A<T>> {
    class C {
        public T getT() { return null; }
    }
}

class B extends A<B> {
    public class D extends A<B>.C {}
}
