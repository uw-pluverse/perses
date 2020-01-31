


public class T7177306c {

    static <T> T m(T t) { return (T)"Null"; }

    public static void main(String[] args) {
        if (m("NonNullConst") != "Null") {
            throw new AssertionError("should not get there!");
        }
    }
}
