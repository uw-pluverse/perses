



public class MethodRef1 {

    static interface A {void m();}

    static interface B {void m(int i);}

    static interface C {String m(String s);}

    private static void assertTrue(boolean cond) {
        if (!cond)
            throw new AssertionError();
    }

    static void foo(int x) {
        System.out.println("MethodRef1.foo(int) " + x);
    }

    static void bar() {
        System.out.println("MethodRef1.bar()");
    }

    static void bar(int x) {
        System.out.println("MethodRef1.bar(int) " + x);
    }

    static String bar(String s) {
        return "MethodRef1.bar(String) " + s;
    }

    public static void main(String[] args) {

        A a = MethodRef1::bar; 
        a.m();

        B b = MethodRef1::foo; 
        b.m(1);

        b = MethodRef1::foo; 
        b.m(1);

        b = MethodRef1::bar; 
        b.m(2);

        C c = MethodRef1::bar; 
        assertTrue( c.m("hi").equals("MethodRef1.bar(String) hi") );
    }
}
