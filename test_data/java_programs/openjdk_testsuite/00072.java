
class T6838943 {
    static class A<X> {}
    static class B {}
    static class C<X> {
        <Z> void m(X x, Z z) {
            C<A<Z>> c = new C<A<Z>>();
            c.m(new A<B>(), new B()); 
        }
    }
}
