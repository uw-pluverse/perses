



public class T8021567b {

    interface SAM {
        int m();
    }

    public static void main(String argv[]) {
        test();
    }

    static boolean test() {
        final int i = 0;
        SAM s = () -> i;
        return (s.m() == 0);
    }
}
