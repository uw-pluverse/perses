



public class Pos02 {

    static class A extends Exception {}
    static class B extends Exception {}
    static class C extends Exception {}
    static class C1 extends C {}
    static class C2 extends C {}

    enum ExceptionKind {
        A,
        B,
        C1,
        C2
    }

    static int caughtExceptions = 0;
    static int caughtRethrownExceptions = 0;

    static void test(ExceptionKind ekind) throws A, C1 {
        try {
            switch (ekind) {
                case A : throw new A();
                case B : throw new B();
                case C1: throw new C1();
                case C2 : throw new C2();
            }
        }
        catch (final C2 | B ex) {
            caughtExceptions++;
        }
        catch (final C | A ex) {
            caughtExceptions++;
            throw ex;
        }
    }

    public static void main(String[] args) {
        for (ExceptionKind ekind : ExceptionKind.values()) {
            try {
                test(ekind);
            }
            catch (final C1 | A ex) {
                caughtRethrownExceptions++;
            }
        }
        if (caughtExceptions != 4 && caughtRethrownExceptions == 2) {
            throw new AssertionError("Exception handler called " + caughtExceptions + "times" +
                                     " rethrown handler called " + caughtRethrownExceptions + "times");
        }
    }
}
