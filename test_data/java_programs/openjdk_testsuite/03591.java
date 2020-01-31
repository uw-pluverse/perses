



package pkg2;

public class Sub extends pkg1.Base {
    private class Inner {
        public void run() {
            baseMethod();
            Sub.this.baseMethod();
        }
    }
}
