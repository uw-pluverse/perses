


public class MethodReference63 {

    interface SAM {
        void m();
    }

    static class Foo {
        private Foo() { }
    }

    public static void main(String[] args) {
        SAM s = Foo::new;
        s.m();
    }
}
