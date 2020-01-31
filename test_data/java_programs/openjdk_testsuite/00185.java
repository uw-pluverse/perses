



package rare10;

class A {
    class B {
        Object t;
    }

    static class C {
        {
            B b = null;
            b.t = "foo";
        }
    }
}
