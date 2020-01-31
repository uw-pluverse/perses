

class Outer {
    public Inner inner;

    public void create() {
        inner = new Inner();
    }

    private class Inner {
        int k = 100;
        protected int l = 100;
        public int m = 100;
        protected int n = 100;
    }
}

class Access {
    public static void main(String[] args) {
        Outer outer = new Outer();
        outer.create();
        System.out.println("Value of k: " + outer.inner.k);
        System.out.println("Value of l: " + outer.inner.l);
        System.out.println("Value of m: " + outer.inner.m);
        System.out.println("Value of n: " + outer.inner.n);
    }
}
