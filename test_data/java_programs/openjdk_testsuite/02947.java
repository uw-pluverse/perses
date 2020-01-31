



public class MethodRef7 {

    static interface A {void m();}

    static interface A2 {void m(int n);}

    static interface B {String m();}

    static interface B2 {String m(int n);}

    static interface C {String m(MethodRef7 mr);}

    static interface C2 {String m(MethodRef7 mr, int n);}

    static interface D {Fee<String> m();}

    static interface D2 {Fee<String> m(String s);}

    static class Fee<T> {

        public Fee() {
            System.out.println("Fee<T> instantiated");
        }

        public Fee(String s) {
            System.out.println("Fee<T> instantiated: " + s);
        }
    }

    private static void assertTrue(boolean cond) {
        if (!cond)
            throw new AssertionError();
    }

    static void bar() {
        System.out.println("MethodRef_neg1.bar()");
    }

    static void bar(int x) {
        System.out.println("MethodRef_neg1.bar(int) " + x);
    }

    String wahoo() {
        return "wahoo";
    }

    String wahoo(int x) {
        return "wahoo " + x;
    }

    public static void main(String[] args) {

        A a = MethodRef7::bar; 
        a.m();
        A2 a2 = MethodRef7::bar; 
        a2.m(10);

        MethodRef7 mr = new MethodRef7();
        B b = mr::wahoo; 
        assertTrue(b.m().equals("wahoo"));
        B2 b2 = mr::wahoo; 
        assertTrue(b2.m(1).equals("wahoo 1"));

        C c = MethodRef7::wahoo; 
        assertTrue(c.m(mr).equals("wahoo"));
        C2 c2 = MethodRef7::wahoo; 
        assertTrue(c2.m(mr, 2).equals("wahoo 2"));

        D d = Fee<String>::new; 
        D2 d2 = Fee<String>::new; 
    }
}
