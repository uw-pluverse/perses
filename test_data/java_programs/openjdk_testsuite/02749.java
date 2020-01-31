



public class ConstructorAccess {
    int i = 0;
    char c = 'x';

    private ConstructorAccess() {
        this.i = 42;
    }

    private ConstructorAccess(int i, char c) {
        this.i = i;
        this.c = c;
    }

    class Inner {
        int j;
        char c;
        boolean b;

        private Inner() {
            this.j = 0;
            this.b = false;
            this.c = 'x';
        }
        private Inner(int i, char c) {
            this.j = i;
            this.b = true;
            this.c = c;
            ConstructorAccess.this.i = i;
        }
        private Inner(int i, boolean b) {
            this.j = i;
            this.b = b;
            this.c = 'x';
        }
        void foo() throws Exception {
            ConstructorAccess x = new ConstructorAccess();
            if (x.i != 42 || x.c != 'x') {
                throw new Exception("error 1");
            }
            ConstructorAccess y = new ConstructorAccess(555, 'y');
            if (y.i != 555 || y.c != 'y') {
                throw new Exception("error2");
            }
        }
        void check(int j, char c, boolean b) throws Exception {
            if (this.j != j || this.c != c || this.b != b) {
                throw new Exception("error3");
            }
        }
    }

    void bar() throws Exception {
        Inner x = new Inner();
        x.check(0, 'x', false);
        x.foo();
        Inner y = new Inner(747, 'z');
        y.check(747, 'z', true);
        if (this.i != 747) {
            throw new Exception("error 4");
        }
        Inner z = new Inner(777, true);
        z.check(777, 'x' , true);
    }

    class InnerSub extends Inner {
        private InnerSub() {
            super();
        }
        private InnerSub(int i) {
            super(i, 'w');
        }
        private InnerSub(int i, boolean b) {
            super(i, b);
        }
    }

    public static void main(String[] args) throws Exception {
        ConstructorAccess o = new ConstructorAccess();
        o.bar();
        InnerSub x = o.new InnerSub();
        x.check(0, 'x', false);
        x.foo();
        InnerSub y = o.new InnerSub(767);
        y.check(767, 'w', true);
        if (o.i != 767) {
            throw new Exception("error 5");
        }
        InnerSub z = o.new InnerSub(777, true);
        z.check(777, 'x' , true);
    }
}
