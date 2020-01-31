



package inheritance.conflict2;

class A<T> {
    void f(String s) {}
}

class B<T> extends A<T> {
    void f(T t) {}
}

class C extends B<String> {
    void f(String s) {}
}
