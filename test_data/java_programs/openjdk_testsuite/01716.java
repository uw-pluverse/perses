
class Neg11 {
    interface I {
        default void m() { }
    }

    static class C1 {
        public void m() throws Exception { } 
    }

    static class C2 extends C1 implements I { }

    static class C3 implements I {
        public void m() throws Exception { } 
    }
}
