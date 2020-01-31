



public class QualifiedThisExactMatch {

    void test() throws Exception {}

    void checkIt1() throws Exception {
        QualifiedThisExactMatch z = new QualifiedThisExactMatch() {
            void test() throws Exception {
                if (this == QualifiedThisExactMatch.this) {
                    throw new Exception("anonymous");
                }
            }
        };
        z.test();
    }

    

    class A  {
        Object getThisA() { return A.this; }
        class B extends A {
            Object getThisA() { return A.this; }
            Object getThisB() { return B.this; }
        }
    }

    void check(Object x, Object y) throws Exception {
        if (x != y) {
            throw new Exception("named");
        }
    }

    void checkIt2 () throws Exception {
        A a = new A();
        A.B b = a.new B();

        check(a, a.getThisA());
        check(a, b.getThisA());
        check(b, b.getThisB());
    }

    

    public static void main(String[] s) throws Exception {
        QualifiedThisExactMatch x = new QualifiedThisExactMatch();
        x.checkIt1();
        x.checkIt2();
    }
}
