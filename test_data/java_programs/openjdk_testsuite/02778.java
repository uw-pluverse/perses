
class A1 {
    void foo(Object[] args) { }
}

class A1a extends A1 {
    void foo(Object... args) { }
}

class A2 {
    void foo(Object... args) { }
}

class A2a extends A2 {
    void foo(Object[] args) { }
}
