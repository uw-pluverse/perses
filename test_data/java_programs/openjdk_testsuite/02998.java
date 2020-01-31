


import java.util.*;
import java.util.stream.*;
import java.util.function.*;

class TargetType53 {

    <P> List<List<P>> perm(List<P> l) { return null; }

    void g(List<List<UnaryOperator<IntStream>>> l) { }

    void test() {
        List<List<UnaryOperator<IntStream>>> l =
            perm(Arrays.asList(s -> s.sorted()));
        g(perm(Arrays.asList(s -> s.sorted())));
    }
}
