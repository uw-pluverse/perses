



class UncheckedCovariance {
    static class Box<T> { }
    static class A {
        Box<Integer> f() { return null; }
    }
    static class B extends A {
        Box f() { return null; }
    }
}
