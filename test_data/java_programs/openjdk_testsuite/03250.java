

abstract class ImplicitLambdaConsideredForApplicabilityTest {
    interface A {
        B m(int a, int b);
    }

    interface C {
        String m(int a, int b);
    }

    interface B {
        int m(int c);
    }

    abstract void foo(A a);

    abstract void foo(C c);

    void bar() {
        foo((int a, int b) -> {
            if(a < b)
                return c -> 0;
            else
                return c -> 0;
        });
    }
}
