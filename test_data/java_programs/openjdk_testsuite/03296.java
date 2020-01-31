



import java.util.*;

class TargetType12 {

    interface Extractor<X,Y> {
       Y get(X x);
    }

    static <T, U extends Comparable<? super U>> void sortBy2(T[] array, Extractor<T, U> extractor) {
        Comparator<T> comparator = (left,right) -> extractor.get(left).compareTo(extractor.get(right));
        Arrays.sort(array, comparator);
    }
}
