



import pkg1.A;

class Separate {
    interface B extends A.I {
        default void m() { A.m(this); }
    }

    interface C extends A.I, B { }
}
