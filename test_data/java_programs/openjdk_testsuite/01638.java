



public class T6978574  {
    static class A extends Exception { }
    static class B extends Exception { }

    static void foo() throws A { throw new A(); }
    static void bar() throws B { throw new B(); }

    static void test(boolean b) {
        try {
            if (b) foo(); else bar();
            return; 
        } catch (final A | B e ) { caught = true; }
        return;
    }

    static boolean caught = false;

    public static void main(String[] args) {
        test(true);
        if (!caught) throw new AssertionError();
        caught = false;
        test(false);
        if (!caught) throw new AssertionError();
    }
}
