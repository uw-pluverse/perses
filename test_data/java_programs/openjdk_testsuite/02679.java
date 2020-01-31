



public class DUBeforeDefined2 {
    int i = j = 1;
    final int j;
    void f() {
        if (i != j) throw new Error();
    }
    public static void main(String[] args) {
        new DUBeforeDefined2().f();
    }
}
