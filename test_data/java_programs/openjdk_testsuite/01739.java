
class Neg10 {
    interface I<X extends Exception> {
        default void m() throws X { }
    }

    static class C1 {
        public void m() throws Exception { } 
    }

    static class C2<Z extends Exception> extends C1 implements I<Z> { }

    static class C3<Z extends Exception> implements I<Z> {
        public void m() throws Exception { } 
    }
}
