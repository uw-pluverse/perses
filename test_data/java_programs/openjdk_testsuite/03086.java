

public class BadAccess02 {

    interface SAM {
        int m(int h);
    }

    static void test1() {
        int l = 0; 
        int j = 0; 
        j = 2;
        final int L = 0;
        SAM s = (int h) -> { int k = 0; return h + j + l + L; };
    }

    void test2() {
        int l = 0; 
        int j = 0; 
        j = 2;
        final int L = 0;
        SAM s = (int h) -> { int k = 0; return h + k + j + l + L; };
    }
}
