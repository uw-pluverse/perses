




public class WhichImplicitThis1 {
    boolean isMiddle() { return false; }
    private class Middle extends WhichImplicitThis1 {
        boolean isMiddle() { return true; }
        boolean enclIsMiddle() { return WhichImplicitThis1.this.isMiddle(); }
        class Inner {}
        boolean check() {
            return new WhichImplicitThis1.Middle().enclIsMiddle();
        }
    }
    public static void main(String[] args) {
        WhichImplicitThis1 t = new WhichImplicitThis1();
        Middle m = t.new Middle();
        if (!m.check()) throw new Error();
    }
}
