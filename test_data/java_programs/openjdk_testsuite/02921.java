


public class MethodReference49 {

    interface SAM {
       Object m(int[] i);
    }

    public static void main(String[] args) {
        SAM s = int[]::clone;
        int[] iarr = { 1, 2, 3 };
        int[] iarr2 = (int[])s.m(iarr);
        if (iarr == iarr2) {
            throw new AssertionError();
        }
        for (int i = 0 ; i < iarr.length ; i ++) {
            if (iarr[i] != iarr2[i]) {
                throw new AssertionError();
            }
        }
    }
}
