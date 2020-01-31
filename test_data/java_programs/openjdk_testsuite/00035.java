



class T8008627 {

    interface I {
        Object m(Iterable l);
    }

    interface J<S> {
        S m(Iterable<String> l);
    }

    interface K<T> {
        T m(Iterable<String> l);
    }

    @FunctionalInterface
    interface Functional<S,T> extends I, J<S>, K<T> {}
}
