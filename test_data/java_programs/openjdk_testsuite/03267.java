



public class LambdaExpr02 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface S_int {
        int m();
    }

    interface S_Integer {
        Integer m();
    }

    interface S_int_int {
        int m(int i);
    }

    interface S_Integer_int {
        int m(Integer i);
    }

    interface S_int_Integer {
        Integer m(int i);
    }

    interface S_Integer_Integer {
        Integer m(Integer i);
    }

    static {
        S_int s_i = ()-> { return 3; };
        assertTrue(3 == s_i.m());
        S_Integer s_I = ()-> { return 3; };
        assertTrue(3 == s_I.m());
        S_int_int s_i_i = (int x) -> { return x + 1; };
        assertTrue(4 == s_i_i.m(3));
        S_int_Integer s_i_I = (int x) -> { return x + 1; };
        assertTrue(4 == s_i_I.m(3));
        S_Integer_int s_I_i = (Integer x) -> { return x.intValue() + 1; };
        assertTrue(4 == s_I_i.m(3));
        S_Integer_Integer s_I_I = (Integer x) -> { return x.intValue() + 1; };
        assertTrue(4 == s_I_I.m(3));
    }

    {
        S_int s_i = ()-> { return 3; };
        assertTrue(3 == s_i.m());
        S_Integer s_I = ()-> { return 3; };
        assertTrue(3 == s_I.m());
        S_int_int s_i_i = (int x) -> { return x + 1; };
        assertTrue(4 == s_i_i.m(3));
        S_int_Integer s_i_I = (int x) -> { return x + 1; };
        assertTrue(4 == s_i_I.m(3));
        S_Integer_int s_I_i = (Integer x) -> { return x.intValue() + 1; };
        assertTrue(4 == s_I_i.m(3));
        S_Integer_Integer s_I_I = (Integer x) -> { return x.intValue() + 1; };
        assertTrue(4 == s_I_I.m(3));
    }

    static void test1() {
        S_int s_i = ()-> { return 3; };
        assertTrue(3 == s_i.m());
        S_Integer s_I = ()-> { return 3; };
        assertTrue(3 == s_I.m());
        S_int_int s_i_i = (int x) -> { return x + 1; };
        assertTrue(4 == s_i_i.m(3));
        S_int_Integer s_i_I = (int x) -> { return x + 1; };
        assertTrue(4 == s_i_I.m(3));
        S_Integer_int s_I_i = (Integer x) -> { return x.intValue() + 1; };
        assertTrue(4 == s_I_i.m(3));
        S_Integer_Integer s_I_I = (Integer x) -> { return x.intValue() + 1; };
        assertTrue(4 == s_I_I.m(3));
    }

    void test2() {
        S_int s_i = ()-> { return 3; };
        assertTrue(3 == s_i.m());
        S_Integer s_I = ()-> { return 3; };
        assertTrue(3 == s_I.m());
        S_int_int s_i_i = (int x) -> { return x + 1; };
        assertTrue(4 == s_i_i.m(3));
        S_int_Integer s_i_I = (int x) -> { return x + 1; };
        assertTrue(4 == s_i_I.m(3));
        S_Integer_int s_I_i = (Integer x) -> { return x.intValue() + 1; };
        assertTrue(4 == s_I_i.m(3));
        S_Integer_Integer s_I_I = (Integer x) -> { return x.intValue() + 1; };
        assertTrue(4 == s_I_I.m(3));
    }

    public static void main(String[] args) {
        test1();
        new LambdaExpr02().test2();
        assertTrue(assertionCount == 24);
    }
}
