



strictfp
public class LambdaTestStrictFP {

    static double fld =  eval(() -> {
            double x = Double.longBitsToDouble(0x1e7ee00000000000L);
            double y = Double.longBitsToDouble(0x2180101010101010L);

            return x * y;
        });

    public static void main(String args[]) {
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
            check(z, fld, "field");
        }
    }

    private static void check(double expected, double got, String where) {
        if (got != expected) {
            throw new AssertionError(where + ": Non-strictfp " + got + " != " + expected);
        }
    }

    private static double eval(Face arg) {
        return arg.m();
    }

    private interface Face {
        double m();
    }
}
