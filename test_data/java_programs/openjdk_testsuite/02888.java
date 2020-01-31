

public class MethodReference42 {

    static class SuperFoo<X> { }

    static class Foo<X extends Number> extends SuperFoo<X> { }

    interface SAM1 {
        SuperFoo<String> m();
    }

    interface SAM2 {
        SuperFoo<Integer> m();
    }

    interface SAM3 {
        SuperFoo<Object> m();
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
