

public class MethodReference48 {

    static class Foo<X> {
        X m() { return null; };
    }

    interface SAM1 {
        Foo<Object> m(Foo<String> fs);
    }

    interface SAM2 {
        Integer m(Foo<Integer> fi);
    }

    interface SAM3 {
        Object m(Foo<Integer> fi);
    }

    static void g1(SAM1 s) { } 

    static void g2(SAM2 s) { } 

    static void g3(SAM3 s) { } 

    static void g4(SAM1 s) { } 
    static void g4(SAM2 s) { } 
    static void g4(SAM3 s) { } 

    public static void main(String[] args) {
        g1(Foo::m);
        g2(Foo::m);
        g3(Foo::m);
        g4(Foo::m);
    }
}
