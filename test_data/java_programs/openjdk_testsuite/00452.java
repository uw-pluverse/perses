



class Test3 {
    interface I {}
    interface J {}
    static class C implements I, J {}
    static class D implements I, J {}

    interface Ord {}

    static C c = new C();
    static D d = new D();

    static <B extends Ord> List<B> nil() { return new List<B>(); }
    static <B extends I & J> B f(B x) { return x; }

    static <A> List<A> cons(A x, List<A> xs) { return xs.prepend(x); }
    static <A> Cell<A> makeCell(A x) { return new Cell<A>(x); }
    static <A> A id(A x) { return x; }

    public static void main(String[] args) {
        I i = f(c);
        J j = f(d);
        f(c);
        f(d);
    }
}
