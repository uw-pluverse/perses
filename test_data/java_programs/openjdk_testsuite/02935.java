


import java.util.stream.*;
import java.util.*;
import static java.util.stream.Collectors.*;

class TargetType54 {
    void test(Stream<Integer> si) {
        List<Integer> l1 = si.collect(toList());
        List<Integer> l2 = si.collect(toCollection(ArrayList::new));
        m(si.collect(toList()));
        m(si.collect(toCollection(ArrayList::new)));
    }

    void m(List<Integer> l) { }
}
