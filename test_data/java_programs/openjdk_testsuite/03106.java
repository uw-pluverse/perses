


class TargetType76 {

    interface Function<X, Y> {
        Y m(X x);
    }

    interface OfRef<T> { }

    interface Supplier<X> {
        X make();
    }

    interface Stream<X> { }

    interface Node<E> {
        Spliterator<E> spliterator();
    }

    interface Spliterator<X> {
        Spliterator<X> spliterator();
    }

    class RefTestData<T, I> implements OfRef<T> {
        RefTestData(I state,
                    Function<I, Stream<T>> streamFn,
                    Function<I, Spliterator<T>> splitrFn) { }
    }

    <O> OfRef<O> ofCollection(Node<O> collection) {
        return new RefTestData<>(collection,
                                 x->stream(x::spliterator),
                                 Node::spliterator);
    }

    <S> Stream<S> stream(Supplier<? extends Spliterator<S>> supplier) { return null; }
}
