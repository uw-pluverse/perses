






class BadTest2 {

    interface I {}
    interface J {}
    static class C implements I, J {}
    static class D implements I, J {}

    static class Main {

        static C c = new C();
        static D d = new D();

        static <A> boolean equals(A x, A y) { return x.equals(y); }

        public static void main(String[] args) {
            equals(c, d); 
        }
    }

}
