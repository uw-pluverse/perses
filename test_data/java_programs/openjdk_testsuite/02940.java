


import java.util.*;

class TargetType69 {

    interface Function<X,Y> {
        Y m(X x);
    }

    abstract class TabulationAssertion<T, U> { }

    class GroupedMapAssertion<K, M1 extends Map<K, ?>> extends TabulationAssertion<Integer, M1> {
        GroupedMapAssertion(Function<Integer, K> classifier) { }
    }


    <T, M2 extends Map> void exerciseMapTabulation(Function<T, ? extends M2> collector,
                                                             TabulationAssertion<T, M2> assertion)  { }

    void test(Function<Integer, Integer> classifier, Function<Integer, Map<Integer, List<Integer>>> coll) {
        exerciseMapTabulation(coll, new GroupedMapAssertion<>(classifier));
    }
}
