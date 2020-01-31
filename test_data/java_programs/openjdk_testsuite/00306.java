



public class T6481655 {

    public static <T> T getT(T t) {
        return t;
    }

    public static void main(String... s) {
        T6481655.<String>getT("");
        (T6481655.<String>getT("")).getClass();
    }
}
