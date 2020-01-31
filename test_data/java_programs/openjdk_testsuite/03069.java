

class IgnoreLambdaBodyDuringResolutionTest1 {
    interface SAM<T> {
        T action(T t);
    }

    <T> T m(SAM<T> op) {
        return null;
    }

    class B {
        B x() {
            return this;
        }
    }

    class C {}

    void foo(B arg) {}
    void foo(C arg) {}

    void bar() {
        foo(m(arg -> new B()));
    }
}
