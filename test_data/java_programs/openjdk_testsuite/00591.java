




public class IllegallyOptimizedException {
    static int i = 0;
    public static void main (String argv[]) {
        try{
            int m[] = new int[-2];
        }
        catch(NegativeArraySizeException n) { i = 1;}
        if (i != 1) {
            throw new Error();
        }
    }
}
