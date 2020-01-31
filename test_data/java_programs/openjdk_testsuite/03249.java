



public class LambdaExpr07 {

    interface Block<A, R> {
        R apply(A x);
    }

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    String S = "A";

    void test() {
        Block<String, Block<String, String>> o = s1 -> s2 -> S + s1 + s2;
        assertTrue(o.apply("B").apply("C").equals("ABC"));
    }

    public static void main(String[] args) {
        new LambdaExpr07().test();
        assertTrue(assertionCount == 1);
    }
}
