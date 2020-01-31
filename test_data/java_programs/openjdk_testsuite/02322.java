




class LambdaTest {

    interface I {
        int m(int x);
    }

    static int foo(I i) { return i.m(0); }

    static {
        foo((int x1) -> { return foo((int x2) -> { return x1 + x2; }); });
    }
}



