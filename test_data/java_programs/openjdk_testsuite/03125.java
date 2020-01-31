



import java.util.*;

class TargetType29 {
    interface Reducer<E, V> {
        public V reduce(E element, V value);
    }

    private static <E> int reduce(Iterable<? extends E> iterable, Reducer<? super E, Integer> reducer) { return 0;  }

    void test(List<Integer> li) {
        reduce(li, (e, v) -> e + v);
    }
}
