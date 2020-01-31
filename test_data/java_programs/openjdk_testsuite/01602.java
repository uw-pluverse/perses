



public class T6500343b {

    final static int i1 = 0;
    final static int i2 = 1;

    static void crash(int i) {
        switch (i) {
            case (true ? 0 : 1):
            case (i1 == 5 ? 1 : 2):
            case (i1 == i2 ? 2 : 3):
        }
    }

    public static void main(String[] args) {
        T6500343b.crash(0);
    }
}
