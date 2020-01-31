



public class Verify {
    public static void main(String[] args) {
        test(args.length > 200);
    }

    static int test(boolean b) {
        int i;
        try {
            if (b) return 1;
            i = 2;
        } finally {
            if (b) i = 3;
        }
        return i;
    }
}
