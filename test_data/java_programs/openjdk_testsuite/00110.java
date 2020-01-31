


import java.util.List;

public class T7177306d {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        if (!cond) {
            throw new AssertionError();
        }
        assertionCount++;
    }

    static <T, S extends List<T>> void m(List<? super T> arg1, S arg2, Class<Object> arg3) { assertTrue(false); }
    static void m(Object o1, Object o2, Object o3) { assertTrue(true); }

    static void test(List<Integer> li, List<String> ls, Class c) {
        m(li, ls, c);
    }

    public static void main(String[] args) {
        test(null, null, null);
        assertTrue(assertionCount == 1);
    }
}
