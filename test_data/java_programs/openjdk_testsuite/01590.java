



public class NullQualifiedSuper1 {
    class a {
        int a1 = 5;
    }
    class c extends a {
        c() {
            null.super(); 
        }
    }
    public static void main(String[] args) {
        new NullQualifiedSuper1().new c();
    }
}
