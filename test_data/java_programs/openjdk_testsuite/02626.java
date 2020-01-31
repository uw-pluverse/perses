



public class DUBeforeDefined1 {
    static int i = j = 1;
    static final int j;
    public static void main(String[] args) {
        if (i != j) throw new Error();
    }
}
