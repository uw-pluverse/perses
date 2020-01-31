
import java.util.*;

class T8019480<U> {
    interface Predicate<T> {
       void m(T t);
    }

    interface Stream<T> {
       void forEach(Predicate<T> pt);
    }

    void test(U current, Stream<U> stream) {
        List<U> list3 = new ArrayList<>();
        stream.forEach(i -> list3.add(current.clone()));
    }
}
