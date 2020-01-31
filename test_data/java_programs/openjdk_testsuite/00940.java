



public class NullQualifiedSuper2 {
    NullQualifiedSuper2 u = null;
    class a {
        int a1 = 5;
    }
    class c extends a {
        c() {
            u.super(); 
        }
    }
    public static void main(String[] args) {
        new NullQualifiedSuper2().new c();
    }
}
