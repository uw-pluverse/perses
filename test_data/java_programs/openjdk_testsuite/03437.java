



class T6558559a {
    interface A<T> {}

    static class B<T> {}

    A<?> x = null;
    B<?> y = (B<?>)x;
}
