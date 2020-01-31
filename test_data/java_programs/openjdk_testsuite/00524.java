



public class T6227936 {
    static class A<T extends B<?>> {}

    abstract static class B<T extends C> {
        public abstract T getC();
    }

    static class C {}

    abstract static class A1<T extends B1<?>> extends A<T> {
        void test(T t) {
            C1 c1 = t.getC();
        }
    }

    abstract static class B1<T extends C1> extends B<T> {
    }

    abstract static class C1 extends C {
        abstract void someMethod();
    }
}
