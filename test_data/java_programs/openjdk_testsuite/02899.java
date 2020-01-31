


public class LambdaExpr15 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface Block<T> {
       void apply(T t);
    }

    public static void main(String[] args) {
        
        Block<Object> ba1 = t -> {
            new Object() {
                String get() { return ""; }
            };
            assertTrue((Integer)t == 1);
        };
        ba1.apply(1);

        
        Block<Object> ba2 = t -> {
            class A {
                String get() { return ""; }
            };
            new A();
            assertTrue((Integer)t == 2);
        };
        ba2.apply(2);
        assertTrue(assertionCount == 2);
    }
}
