


import java.util.*;

class T6762569a {
    <T> void m(T t, List<? super List<T>> list) {}

    void test(List<? super List<?>> list) {
        m("", list);
    }
}
