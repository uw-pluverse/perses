


public class T8023558b {

    interface Supplier<X> {
        X get();
    }

    static class A {
        public A(Supplier<B> supplier) { }
    }

    static class B { }

    static class C {
        public B getB() {
            return new B();
        }
    }

    public static void main(String[] args) {
        new T8023558b().test(T8023558b::getC);
    }

    private static C getC() {
        return new C();
    }

    public void test(Supplier<C> supplier) {
        new A(supplier.get()::getB);
    }
}
