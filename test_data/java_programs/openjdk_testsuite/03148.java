


import java.util.function.*;

class TargetType55  {

    <R> void m(Function<Integer, R> collector) { }

    <T, D> Function<T, Integer> g(D d, BinaryOperator<D> reducer) { return null; }

    public void test() {
        m(g((Integer)null, (x,y)->1));
    }
}
