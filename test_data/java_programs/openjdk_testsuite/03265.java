


public class TargetType35 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface A {}

    interface B {}

    static class C implements A, B {}

    static class D implements A, B {}

    interface SAM<Y, X> {
        Y invoke(X arg);
    }

    static class Sup {
       <Z> Z m(Z z) { return z; }
    }

    static class Sub extends Sup {
        <Z> Z m(Z z) { return z; }

        void test(C c, D d) {
            choose(c, d, x->x);
            choose(c, d, this::m);
            choose(c, d, super::m);
        }

        <T> void choose(T t1, T t2, SAM<T, T> t3) {
            assertTrue(true);
        }
    }

    public static void main(String[] args)
    {
        new Sub().test(null, null);
        assertTrue(assertionCount == 3);
    }
}
