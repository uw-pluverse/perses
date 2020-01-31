












import java.util.*;

class WhereCaptured {
    <T> void m(List<T> l1, List<T> l2) {}

    void test(List<? extends WhereCaptured> list) {
        m(list, list);
    }
}
