



public class Capture {
    final int k;
    Capture(int n) {
        k = n;
    }
    public static void main(String args[]) {
        final int j;
        int k1 = new Capture(2 + (j=3)){
                         int get () {return k+j;}
                     }.get();
        if (k1 != 8) throw new Error("k1 = " + k1);
    }
}
