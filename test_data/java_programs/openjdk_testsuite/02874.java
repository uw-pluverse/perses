



public class MethodReference33 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    class Foo {
        Foo(Integer i) { assertTrue(true); }
        Foo() { assertTrue(true); }
    }

    interface BridgeSAMBound<X> {
        X m(int i);
    }

    interface NonBridgeSAMBound<X> {
        X m();
    }

    void test() {
        BridgeSAMBound<Foo> b1 = Foo::new;
        b1.m(1);
        NonBridgeSAMBound<Foo> b2 = Foo::new;
        b2.m();
    }

    public static void main(String[] args) {
        MethodReference33 test = new MethodReference33();
        test.test();
        assertTrue(assertionCount == 2);
    }
}
