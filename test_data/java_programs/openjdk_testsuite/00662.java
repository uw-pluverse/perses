



public class ShiftExpressionTest {
    public static void main(String[] args) throws Exception {
        String s = "" + (0x0101L << 2) + (0x0101L >> 2) + (0x0101L >>> 2);
        if (s.indexOf("null",0) != -1) {
            throw new Exception(
                  "incorrect compile-time evaluation of shift");
        }
    }
}
