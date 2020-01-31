



public class LambdaExpr12 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface Getter<X> {
        X get();
    }


    interface Mapper<X,Y> {
        Y map(X x);
    }

    void test() {
        Mapper<String, Getter<Character>> mapper =
                (final String s) -> new Getter<Character>() {
                     @Override
                     public Character get() {
                         return s.charAt(0);
                     }
                };
        assertTrue(mapper.map("First").get() == 'F');
    }

    public static void main(String[] args) {
        new LambdaExpr12().test();
        assertTrue(assertionCount == 1);
    }
}
