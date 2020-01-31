





class WhichImplicitThis7 {
    static private int i;
    static class B extends WhichImplicitThis7 {
        private int i;
    }
    class C extends B {
        C(int j) {}
        C() {
            
            
            
            
            this(i);
        }
    }
}
