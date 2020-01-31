



class A<T> {}
class B<S, T> extends A<T> {}

class Main {
    void f(A<String> as) {
        Object o = (B<?, Integer>) as;
    }
}
