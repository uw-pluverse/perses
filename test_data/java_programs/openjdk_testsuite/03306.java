

public class BadAccess {

    int i;
    static int I;

    interface SAM {
        int m();
    }

    static void test1() {
        int l = 0; 
        final int L = 0;
        SAM s = ()-> i + I + l + L;
    }

    void test2() {
        int l = 0; 
        final int L = 0;
        SAM s = ()-> i + I + l + L;
    }
}
