



public class Method<T extends Number> {
    static class Y {}
    <Y extends Number> void test() {
        Method<Y> m = null;
        Number n = m.get();
    }
    T get() {
        return null;
    }
}
