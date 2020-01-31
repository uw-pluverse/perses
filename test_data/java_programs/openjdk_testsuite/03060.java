



public class LambdaConv03 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface TU<T, U> {
      public T foo(U u);
    }

    public static <T, U> T exec(TU<T, U> lambda, U x) {
        return lambda.foo(x);
    }

    static {
        
        int i1 = exec((Integer x) -> { return x; }, 3);
        assertTrue(3 == i1);
        
        int i2 = exec((Integer x) -> { return x; }, 3);
        assertTrue(3 == i2);
        
        try {
            exec((Object x) -> { return x.hashCode(); }, null);
        }
        catch (RuntimeException e) {
            assertTrue(true);
        }
    }

    {
        
        int i1 = exec((Integer x) -> { return x; }, 3);
        assertTrue(3 == i1);
        
        int i2 = exec((Integer x) -> { return x; }, 3);
        assertTrue(3 == i2);
        
        try {
            exec((Object x) -> { return x.hashCode(); }, null);
        }
        catch (RuntimeException e) {
            assertTrue(true);
        }
    }

    public static void test1() {
        
        int i1 = exec((Integer x) -> { return x; }, 3);
        assertTrue(3 == i1);
        
        int i2 = exec((Integer x) -> { return x; }, 3);
        assertTrue(3 == i2);
        
        try {
            exec((Object x) -> { return x.hashCode(); }, null);
        }
        catch (RuntimeException e) {
            assertTrue(true);
        }
    }

    public void test2() {
        
        int i1 = exec((Integer x) -> { return x; }, 3);
        assertTrue(3 == i1);
        
        int i2 = exec((Integer x) -> { return x; }, 3);
        assertTrue(3 == i2);
        
        try {
            exec((Object x) -> { return x.hashCode(); }, null);
        }
        catch (RuntimeException e) {
            assertTrue(true);
        }
    }

    public static void main(String[] args) {
        test1();
        new LambdaConv03().test2();
        assertTrue(assertionCount == 12);
    }
}
