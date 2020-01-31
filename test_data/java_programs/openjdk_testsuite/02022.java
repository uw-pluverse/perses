






public class Closure4 {

    public int v;

    public Closure4() {
        v = 0;

        Inner i = new Inner() {
            public void foo() {
                if (v != 0) throw new Error();
            }
        };

        i.foo();
    }

    public static void main(String[] arg) {
        new Closure4();
    }
}

class Inner {
    Inner() {
        foo();
    }

    public void foo() { throw new Error(); }
}
