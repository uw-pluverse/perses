



public class T4954546 {
    interface I {
        void f();
    }
    interface J {
        void g();
    }
    static class A implements I, J {
        public void f() {}
        public void g() {}
    }
    static class B implements J, I {
        public void f() {}
        public void g() {}
    }
    public static void main(String[] args) {
        f(true, new A(), new B());
    }
    static void f(boolean cond, A a, B b) {
        (cond?a:b).f();;
        (cond?a:b).g();;
    }
}
