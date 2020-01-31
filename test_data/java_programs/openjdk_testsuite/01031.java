



public class DeadCode1
{
    public static int test() {
        Object[] arrayref = null;
        try {
            Object obj = arrayref[0];
            return 2;
        } catch (NullPointerException e)  {
            return 0;
        }
    }


    public static void main(String[] args) {
        int ret = test();
        if (ret == 2)
            throw new RuntimeException("test() = 2; accidental removal of live code");
        else
            System.out.println("correct dead-code elimination");
    }
}
