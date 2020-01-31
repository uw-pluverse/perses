



class X<T extends Number> {
    static <T extends Number> X<T> f(X<T> a, X<T> b) {
        return f(f(a, b), b);
    }
}
