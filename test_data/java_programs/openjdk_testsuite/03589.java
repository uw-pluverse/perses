




public class UninitThis {

    UninitThis(String s, int i) {
        this(i == 0 ? s : "foo");
    }

    UninitThis(String s) {}

    public static void main(String... args) {}

}
