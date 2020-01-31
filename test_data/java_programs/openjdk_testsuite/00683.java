



class DU1 {
    void f1() {
        final int i;
        try {
            assert false : i=3;
        } catch (AssertionError ae) {
        }
        i=4; 
    }
}
