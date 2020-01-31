

public class MethodReference41 {

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

    static void m1(SAM1 s) { }

    static void m2(SAM2 s) { }

    static void m3(SAM3 s) { }

    static void m4(SAM1 s) { }
    static void m4(SAM2 s) { }
    static void m4(SAM3 s) { }

    public static void main(String[] args) {
        m1(Foo::new);
        m2(Foo::new);
        m3(Foo::new);
        m4(Foo::new);
    }
}
