



public class FinalIntConcatenation {
    public static void main(String[] args) throws Exception {
        final int i = 7;
        String s = "" + i;
        if (s.indexOf("null",0) != -1) {
            throw new Exception(
                  "incorrect compile-time evaluation of final int");
        }
    }
}
