



interface A { void g(); }

public class T5092545<D extends A> {
    D d;
    class Inner {
        public void f() {
            d.g();   
        }
    }

    public static void main(String[] args) {
        System.out.println("FISK");
    }
}
