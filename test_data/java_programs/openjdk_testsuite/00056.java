



import java.util.*;

class Test {
    static void test(List<Integer> l, int i) {
        equal(i, Collections.binarySearch(l, l.get(i)));
    }
    static void equal(Object x, Object y) {}
}
