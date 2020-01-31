



public class LambdaTestStrictFPMethod {

    public static void main(String args[]) {
        new LambdaTestStrictFPMethod().test();
    }

    strictfp void test() {
        double result = eval(() -> {
            double x = Double.longBitsToDouble(0x1e7ee00000000000L);
            double y = Double.longBitsToDouble(0x2180101010101010L);

            return x * y;
        });
        {
            double x = Double.longBitsToDouble(0x1e7ee00000000000L);
            double y = Double.longBitsToDouble(0x2180101010101010L);

            double z = x * y;
            check(z, result, "method");
        }
    }

    strictfp void check(double expected, double got, String where) {
        if (got != expected) {
            throw new AssertionError(where + ": Non-strictfp " + got + " != " + expected);
        }
    }

    static double eval(Face arg) {
        return arg.m();
    }

    interface Face {
        double m();
    }
}
