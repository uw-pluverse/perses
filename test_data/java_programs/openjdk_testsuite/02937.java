



public class MethodReference29 {

    interface SAM {
        void m(Integer i);
    }

    static class A {
        void m(int i) { }
    }

    static class B extends A {
        void test() {
            SAM s = super::m;
            s.m(42);
        }

        void m(int i) { throw new AssertionError(); }
    }

    public static void main(String[] args) {
        new B().test();
    }
}
