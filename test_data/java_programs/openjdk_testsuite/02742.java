



public class VerifyDA {
    public static void main(String[] a) {
        String x;
        try {
            x = "hello";
        } finally {
            try {
                System.out.println("x");
            } catch (RuntimeException e) {
                e.printStackTrace();
                x = null;
            }
        }
        if (x != null) {
            System.out.println(x);
        }
    }
}
