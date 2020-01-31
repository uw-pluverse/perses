



interface MyList<T> {}

interface A {
    void f(MyList l);
}

class B {
    public void f(MyList<String> l) { }
}

class C extends B implements A { }
