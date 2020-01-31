



public class T4711694 {
    interface A<T> {
        void f(T u);
    }

    static class B {
        public void f(Integer i) {}
    }

    static abstract class C<T> extends B implements A<T> {
        public void g(T t) {
            f(t);
        }
    }

    static class D extends C<Integer> {
        public static void main(String[] args) {
            new D().g(new Integer(3));
        }
    }

    public static void main(String[] args) {
        D.main(args);
    }
}
