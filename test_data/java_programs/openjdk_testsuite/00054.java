



public class T6240565 {
    public static <E extends Integer> void doit(E[] a) {
        System.out.println(a[0] / 4);
        for (int i : a)
            System.out.println(i / 4);
        for (E e : a) {
            E f = e;
            System.out.println(e / 4);
        }
    }
    public static void main(String[] args) {
        T6240565.doit(new Integer[]{4 , 8 , 12});
    }
}
