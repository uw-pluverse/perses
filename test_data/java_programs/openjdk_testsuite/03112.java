


class TargetType74 {

    static class LazySeq<E> { }

    <C> LazySeq<C> cons(LazySeq<C> tailFun) { return null; }

    <T extends Comparable<T>> LazySeq<T> mergeSorted(LazySeq<T> a) {
        return cons(mergeSorted(a));
    }
}
