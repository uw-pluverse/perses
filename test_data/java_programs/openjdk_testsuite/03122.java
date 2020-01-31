

public class MethodReference46 {

    interface SAM1 {
       void m(String s);
    }

    interface SAM2 {
       void m(Integer s);
    }

    interface SAM3 {
       void m(Object o);
    }

    static class Foo<X extends Number> {
        Foo(X x) { }
    }

    static <X extends Number> void m(X fx) { }

    static void g1(SAM1 s) { }

    static void g2(SAM2 s) { }

    static void g3(SAM3 s) { }

    static void g4(SAM1 s) { }
    static void g4(SAM2 s) { }
    static void g4(SAM3 s) { }

    public static void main(String[] args) {
        g1(MethodReference46::m);
        g2(MethodReference46::m);
        g3(MethodReference46::m);
        g4(MethodReference46::m);
    }
}
