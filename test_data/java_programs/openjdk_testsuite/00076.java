

import java.util.*;

class T6638712c {

    <T> T sort(T[] a, Comparator<? super T> c) { return null; }

    void test(Enum[] e, Comparator<Enum<?>> comp) {
        sort(e, comp);
    }
}
