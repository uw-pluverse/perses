



class AbstractOverride {
    static class Ex extends Exception {}
    static class A {
        void f() throws Ex {}
    }
    static abstract class B extends A {
        abstract void f();
    }
    static class C extends B {
        void f() {}
    }
    public static void main(String[] args) {
        B b = new C();
        b.f();
    }
}
