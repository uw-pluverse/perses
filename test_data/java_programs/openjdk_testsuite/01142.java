




class Foo<T> {
    T t;
}

class UncheckedAssignToVar {
    void m() {
        Foo f = new Foo();
        f.t = "??";
    }
}
