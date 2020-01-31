



public class Pos01 {

    static class A extends Exception {}
    static class B extends Exception {}

    static int caughtExceptions = 0;

    static void test(boolean b) {
        try {
            if (b) {
                throw new A();
            }
            else {
                throw new B();
            }
        }
        catch (final A | B ex) {
            caughtExceptions++;
        }
    }

    public static void main(String[] args) {
        test(true);
        test(false);
        if (caughtExceptions != 2) {
            throw new AssertionError("Exception handler called " + caughtExceptions + "times");
        }
    }
}
