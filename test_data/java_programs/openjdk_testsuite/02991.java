



public class MethodReference06 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface SAM { 
        abstract void meth(int i);
    }

    static class A {
        void m(int i) { assertTrue(true); }
    }

    static class B extends A {
        void m(int i) {
            SAM mh = super::m;
            mh.meth(i);
        }
    }

    public static void main(String[] args) {
        new B().m(10);
        assertTrue(assertionCount == 1);
    }
}
