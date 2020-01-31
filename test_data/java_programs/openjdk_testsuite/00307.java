



public class T4661029 {
    public static <E> void bug(E[] a, E e) {
        java.util.Arrays.fill(a, 0, 100, e);
    }
}
