



class X<T> {}

class Capture {
    void f(X<? extends Number> x) {
        f2(x);
        f3(x);
    }

    <T> void f2(X<T> x) {}
    <T extends Number> void f3(X<T> x) {}
}
