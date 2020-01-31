



public class T6178365 {
    interface Bar<X> {}
    interface Foo {
        void m(Bar<String> b);
    }
    abstract class AbstractFoo implements Foo {
        public void m(Bar b) {  } 
    }
    class ConcreteFoo extends AbstractFoo {
        public void m(Bar b) {
            super.m(b);
        }
    }
    public static void main(String[] args) {
        System.out.println("PASS");
    }
}
