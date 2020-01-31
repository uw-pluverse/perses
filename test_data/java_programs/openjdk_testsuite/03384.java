

import java.util.*;

class T6722234b {
    <T> void m(List<T> l1, List<T> l2) {}

    void test(List<? extends T6722234b> list) {
        m(list, list);
    }
}
