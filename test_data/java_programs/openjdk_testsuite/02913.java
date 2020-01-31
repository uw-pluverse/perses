



public class InferenceTest11 {

    private static void assertTrue(boolean b) {
        if(!b)
            throw new AssertionError();
    }

    static Func<Integer, Integer> f1;
    static Func<Integer, ? extends Number> f2;

    public static void main(String[] args) {

        f1 = n -> {
            if(n <= 0)
                return 0;
            if(n == 1)
                return 1;
            return f1.m(n-1) + f1.m(n-2);
        };
        assertTrue(f1.m(-1) == 0);
        assertTrue(f1.m(0) == 0);
        assertTrue(f1.m(10) == 55);

        f2 = n -> {
            if(n <= 1)
            return 1.0;
            return 2 * (Double)f2.m(n-1) + 1;
        };
        assertTrue(f2.m(4).doubleValue() == 15.0);
    }

    interface Func<T, V> {
        V m(T t);
    }
}
