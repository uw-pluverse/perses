



public class WhichImplicitThis5 {
    static int init;
    public int i = ++init;
    class One extends WhichImplicitThis5 {
        private Object i; 
    }
    class Two extends One {
        
        Two() {
            WhichImplicitThis5.this.super();
        }
        int j = i; 
        int k = ((WhichImplicitThis5) this).i; 
        Object l = super.i;
    }
    public static void main(String[] args) {
        Two t = new WhichImplicitThis5().new Two();
        if (t.j != 1 || t.k != 2 || t.l != null)
            throw new Error();
    }
}
