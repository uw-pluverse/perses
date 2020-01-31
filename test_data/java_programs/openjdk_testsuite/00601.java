




public class WhichImplicitThis2 {
    boolean isX() { return false; }
    class Middle {
        boolean enclIsX() { return WhichImplicitThis2.this.isX(); }
    }
    class X extends WhichImplicitThis2 {
        boolean isX() { return true; }
        class Middle {} 
        boolean check() {
            return new WhichImplicitThis2.Middle().enclIsX();
        }
    }
    public static void main(String[] args) {
        WhichImplicitThis2 t = new WhichImplicitThis2();
        X x = t.new X();
        if (!x.check()) throw new Error();
    }
}
