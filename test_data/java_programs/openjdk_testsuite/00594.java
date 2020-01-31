



class WhichImplicitThis6 {
    private int i;
    WhichImplicitThis6(int i) {}
    class Sub extends WhichImplicitThis6 {
        Sub() {
            super(i); 
        }
    }
}
