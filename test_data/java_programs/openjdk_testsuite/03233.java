



public class LambdaTest3 {

    private static int count = 0;

    private static void assertTrue(boolean b) {
        if(!b)
            throw new AssertionError();
    }

    public static void main(String[] args) {
        final int N = 100;
        int n = 2; 

        Runnable r = ((Runnable)
            () -> {
                count += N;
                count += n;
            }
        );
        assertTrue(count == 0);
        r.run();
        assertTrue(count == 102);
    }
}
