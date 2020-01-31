


import java.util.*;

class T8016177f {

    interface Function<S, T> {
       T apply(S s);
    }

    interface IntFunction<T> {
       T apply(int s);
    }


    interface BiConsumer<X,Y> {
       void m(X x, Y y);
    }

    interface Consumer<X> {
       void m(X x);
    }

    interface Supplier<X> {
       X make();
    }

    interface TestData<T, S extends BaseStream<T, S>> {
       interface OfRef<T> extends TestData<T, Stream<T>> { }
       interface OfDouble extends TestData<Double, DoubleStream> { }
    }

    interface BaseStream<T, S extends BaseStream<T, S>> { }

    interface Stream<T> extends BaseStream<T, Stream<T>> {
       <M> Stream<M> map(Function<T, M> s);
       <R> R collect(Supplier<R> resultFactory, BiConsumer<R, ? super T> accumulator, BiConsumer<R, R> combiner);
       <Z> Z[] toArray(IntFunction<Z[]> s);
    }

    interface DoubleStream extends BaseStream<Double, DoubleStream> {
       DoubleStream filter(DoublePredicate dp);
       double[] toArray();
    }

    interface DoublePredicate {
       boolean p(double d);
    }

    <T, U, R, S_IN extends BaseStream<T, S_IN>, S_OUT extends BaseStream<U, S_OUT>>
           R exerciseTerminalOps(TestData<T, S_IN> data,
                                 Function<S_IN, S_OUT> streamF,
                                 Function<S_OUT, R> terminalF) { return null; }

    <O> TestData.OfRef<O> ofCollection(Collection<O> collection) { return null; }

    void test1(TestData.OfDouble data, DoublePredicate dp) {
        exerciseTerminalOps(data, s -> s.filter(dp), s -> s.toArray());
    }

    void test2(Function<Double, Integer> fdi, TestData.OfRef<Double> td, Stream<Integer> si) {
        exerciseTerminalOps(
                        ofCollection((List<Double>)null),
                        s -> s.map(fdi),
                        s -> s.toArray(Integer[]::new));
    }
}
