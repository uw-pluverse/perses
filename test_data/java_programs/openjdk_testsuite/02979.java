


import java.util.*;

class T8016177d {

    interface UnaryOperator<X> {
      X m(X x);
    }

    interface IntStream {
       IntStream sorted();
       IntStream distinct();
       IntStream limit(int i);
    }

    abstract class WrappingUnaryOperator<S> implements UnaryOperator<S>  { }

    <S1> WrappingUnaryOperator<S1> wrap1(UnaryOperator<S1> uo) { return null; }
    <S2> WrappingUnaryOperator<S2> wrap2(UnaryOperator<S2> uo) { return null; }
    <S3> WrappingUnaryOperator<S3> wrap3(UnaryOperator<S3> uo) { return null; }

    <P> List<List<P>> perm(List<P> l) { return null; }

    List<List<WrappingUnaryOperator<IntStream>>> intPermutationOfFunctions =
                perm(Arrays.asList(
                        wrap1(s -> s.sorted()),
                        wrap2(s -> s.distinct()),
                        wrap3(s -> s.limit(5))
                ));
}
