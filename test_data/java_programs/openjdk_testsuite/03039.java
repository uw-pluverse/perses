

class T8020843a {
    interface Function<X, Y> {
        Y m(X x);
    }

    <T> void test(T t) {
        Function<T, Object> ss = T::clone;
    }
}
