



package overrideOK;

abstract class A {
    abstract void f();
    void g() {}
}

class B extends A {
    @Override void f() {}
    @Override void g() {}
}
