



public class LambdaIncrement {

    interface IntegerOp { Integer apply(Integer arg); }

    private static void assertNotIncremented(IntegerOp lmb, String label) {
        int result = lmb.apply(3);
        if (result != 3) {
            throw new AssertionError("Post-increment failure. Expected 3, got: " +
                                     result + " " + label);
        }
    }

    public static void main(String... args) throws Exception {
        assertNotIncremented(x -> x++, "PostIncExpr");
        assertNotIncremented(x -> { return x++; }, "PostIncReturn");
        assertNotIncremented(x -> { int y = x; return y++; }, "PostIncLocal");
        assertNotIncremented(x -> { Integer y = x; return y++; }, "PostIncLocalBox");
        assertNotIncremented(x -> { int y = x; return y; }, "HASINIT");
    }
}
