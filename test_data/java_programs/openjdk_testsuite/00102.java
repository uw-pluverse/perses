



public class NestedWildcards {

    public static void test(Box<String> b) {
        foo(bar(b));
    }
    private static <X> Box<? extends X> foo(Box<? extends X> ts) {
        return null;
    }
    public static <Y> Box<? extends Y> bar(Box<? extends Y> language) {
        return null;
    }

    interface Box<T> {}
}
