



package rare8;

class A<T> {
    class B {}
}

class C extends A {
    static class D {
        {
            B b;
        }
    }
}
