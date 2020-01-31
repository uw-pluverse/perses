




public class T6531075 {

    static class A {
        void a() {}
    }

    static interface I{
        void i();
    }

    static class E extends A implements I{
        public void i() {}
    }

    static class C<W extends A & I, T extends W>{
        T t;
        W w;
        C(W w, T t) {
            this.w = w;
            this.t = t;
        }
    }

    public static void main(String... args) {
        C<E,E> c = new C<E,E>(new E(), new E());
        testMemberMethods(c);
    }

    static void testMemberMethods(C<?, ?> arg) {
        arg.t.a();
        arg.t.i();
    }
}
