



public class LambdaScope03 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface SAM {
        void m();
    }

    static void call(SAM s) { s.m(); }

    void test() {
        call(()-> { assertTrue(LambdaScope03.this.getClass().equals(getClass())); });
        call(()-> { assertTrue(LambdaScope03.this.getClass().equals(this.getClass())); });
        call(()-> { assertTrue(LambdaScope03.this.hashCode() == hashCode()); });
        call(()-> { assertTrue(LambdaScope03.this.hashCode() == this.hashCode()); });
        call(()-> { assertTrue(LambdaScope03.this.toString().equals(toString())); });
        call(()-> { assertTrue(LambdaScope03.this.toString().equals(this.toString())); });
        call(()-> { assertTrue(LambdaScope03.this.equals(this)); });
        call(()-> { assertTrue(equals(LambdaScope03.this)); });
    }

    public static void main(String[] args) {
        new LambdaScope03().test();
        assertTrue(assertionCount == 8);
    }
}
