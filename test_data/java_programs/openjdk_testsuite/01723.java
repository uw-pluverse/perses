

class Neg07 {
    interface I {
        default int m() { return 1; }
    }

    static class C1 {
        public void m() { } 
    }

    static class C2 extends C1 implements I { }

    static class C3 implements I {
        public void m() { } 
    }
}
