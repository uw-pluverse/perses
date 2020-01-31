
class T6360970 {
    interface A {
        int i = 1;
    }

    interface B {
        int i = 2;
    }

    interface C extends A, B { }

    static class D {
        public static final int i = 0;
    }

    static class E extends D implements C { }

    int i = E.i; 
}
