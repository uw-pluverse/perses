


public class LambdaExpr18 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface SAM<R> {
        R eval();
    }

    static void test(){
        SAM<Integer> sam1 = () -> {
            assertTrue(true);
            SAM<String> sam2 = () -> {
                assertTrue(true);
                return "";
            };
            sam2.eval();
            return 1;
        };
        sam1.eval();
    }

    public static void main(String[] args) {
        test();
        assertTrue(assertionCount == 2);
    }
}
