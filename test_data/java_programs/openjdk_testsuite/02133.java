



package varargs.override;

class A {
    void f(Object[] o) {}
}

class B extends A {
    void f(Object... o) {}
}
