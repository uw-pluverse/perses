



class X<T> {}

class Capture {
    void f(X<X<? extends Number>> x) {
        f4(x);
    }

    <T> void f4(X<X<T>> x) {}
}
