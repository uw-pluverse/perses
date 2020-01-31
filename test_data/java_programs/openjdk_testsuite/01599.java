


import java.util.Arrays;
import java.util.List;

public class T8016702 {

    static int assertionCount;

    static void assertTrue(boolean b, String msg) {
        assertionCount++;
        if (!b) {
            throw new AssertionError(msg);
        }
    }

    interface IntFunction<Y> {
        Y m(int x);
    }

    void test(List<Integer> li) {
        map(i -> (i % 2 == 0) ? "" : "i="+i, li);
    }


    @SuppressWarnings("unchecked")
    <R> void map(IntFunction<R> mapper, List<Integer> li) {
        for (int i : li) {
            String res = (String)mapper.m(i);
            assertTrue((i % 2 == 0) ? res.isEmpty() : res.contains("" + i),
                    "i = " + i + " res = " + res);
        }
    }

    public static void main(String[] args) {
        T8016702 tester = new T8016702();
        tester.test(Arrays.asList(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));
        assertTrue(assertionCount == 10, "wrong assertion count: " + assertionCount);
    }
}
