



public class T5003431 {
    static class SomeType<T> { T t = null; }

    static <T> T nil() { return (new SomeType<T>()).t; }

    public static void test() {
        nil().getClass();
    }
}
