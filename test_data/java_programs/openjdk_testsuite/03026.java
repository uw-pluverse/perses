



public class LambdaExpr06 {

    static void assertTrue(boolean cond) {
        if (!cond)
            throw new AssertionError();
    }

    interface A {
        int m();
    }

    interface B {
        int dup(int i);
    }

    public static void main(String[] args) {
        A a = ()-> ((B)i -> i * 2).dup(3);
        assertTrue(a.m() == 6);
    }
}
