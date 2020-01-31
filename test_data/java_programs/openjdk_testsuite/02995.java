


import java.util.*;
import java.util.function.*;
import java.util.stream.*;

class TargetType58 {

    void test(List<Integer> li) {
        g(li, s -> s.skip(200), Collections.emptyList());
    }

    <T, U, S_OUT extends Stream<U>,
            I extends Iterable<U>> Collection<U> g(Collection<T> coll, Function<Stream<T>, S_OUT> f, I i) {
        return null;
    }
}
