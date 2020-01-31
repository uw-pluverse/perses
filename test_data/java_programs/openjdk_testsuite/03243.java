



public class LambdaTest4 {

    private String thisStr;
    private static int count = 0;

    {
        ((Runnable)
            ()-> {
                this.init();
                assertTrue(this.toString().equals(thisStr));
                count++;
            }
        ).run();
    }

    private static void assertTrue(boolean b) {
        if(!b)
            throw new AssertionError();
    }

    private void init() {
        thisStr = this.toString();
    }

    private void m() {
        String s1 = this.toString();
        ((Runnable)
            ()-> {
                assertTrue(this.toString().equals(thisStr));
                assertTrue(this.toString().equals(s1));
            }
        ).run();
    }

    public static void main(String[] args) {
        LambdaTest4 test = new LambdaTest4();
        assertTrue(count == 1);
        test.m();
    }
}
