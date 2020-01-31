
class MethodReference51 {

    private static class Foo {
        static int j(int i) { return i; }
    }

    static Foo foo = new Foo();

    static void m(String s) { }
    static void m(Integer i) { }

    static int f(String s) { return 1; }

    static int g(Integer i, Number n) { return 1; }
    static int g(Number n, Integer i) { return 1; }

    int h(int i) { return i; }
}

class TestMethodReference51 {

    interface IntSam {
        int m(int i);
    }

    interface IntegerIntegerSam {
        int m(Integer i1, Integer i2);
    }


    static void test() {
        IntSam s1 = MethodReference51::unknown; 
        IntSam s2 = MethodReference51::f; 
        IntSam s3 = MethodReference51::g; 
        IntegerIntegerSam s4 = MethodReference51::g; 
        IntSam s5 = MethodReference51::h; 
        IntSam s6 = MethodReference51.foo::j; 
    }
}
