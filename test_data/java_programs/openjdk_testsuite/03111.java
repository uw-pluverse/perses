


public class LambdaConv24 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface SAM<X> {
        boolean m(X x);
    }

    LambdaConv24(SAM<String> p) {
        assertTrue(p.m("42"));
    }

    LambdaConv24(int i) {
        this(s->true);
    }

    LambdaConv24(int i1, int i2) {
        this(LambdaConv24::m);
    }

    static boolean m(String s) { return true; }

    public static void main(String[] args) {
        new LambdaConv24(1);
        new LambdaConv24(1,2);
        assertTrue(assertionCount == 2);
    }
}
