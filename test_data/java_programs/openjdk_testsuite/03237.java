

public class AccessNonStatic_neg {

    private int n = 0;

    static {
        ((Runnable) ()-> {
            System.out.println(this);
            System.out.println(n);
        }).run();
    }

    public static void test() {
        ((Runnable) ()-> {
            Object o = this;
            n++;
        }).run();
    }
}
