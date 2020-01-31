



package inheritance.conflict3;

class X1<T> {
    int f(T t) { throw null; }
    void f(Object o) {}
}

class X2 extends X1 {
}
