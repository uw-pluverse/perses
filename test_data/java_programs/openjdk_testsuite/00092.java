



import java.util.Arrays;

public class T6222762 {
    static <T> void varargs(T... args) {
        for(T t : args)
            System.out.println(Arrays.toString((int[])t));
    }
    public static void main(String[] args) {
        varargs(new int[]{1, 2, 3}, new int[]{4, 5, 6});
    }
}
