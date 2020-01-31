


class TargetType65 {
    interface Predicate<X> {
        boolean accepts(X x);
    }

    static class Optional<T> {
        public boolean isPresent() { return false; }
        public static<E> Optional<E> empty() { return null; }
    }

    interface Supplier<X> {
        X make();
    }

    static class Sink<O, T> { }

    static class SubSink<R> extends Sink<R, Optional<R>> {  }

    static class Tester<T, O> {
        public static <F> Tester<F, Optional<F>> makeRef() {
            return new Tester<>(Optional.empty(), Optional::isPresent, SubSink::new);
        }

        private Tester(O emptyValue,
                       Predicate<O> presentPredicate,
                       Supplier<Sink<T, O>> sinkSupplier) {
        }
    }
}
