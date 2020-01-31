



import java.lang.annotation.*;

public class Pos04 {

    enum ExceptionKind {
        A(1),
        B(2),
        C(1);

        int expectedValue;

        ExceptionKind(int expectedValue) {
            this.expectedValue = expectedValue;
        }
    }

    @Retention(RetentionPolicy.RUNTIME)
    @interface CatchNumber {
       int value();
    }

    @CatchNumber(1)
    static class A extends Exception { }

    @CatchNumber(2)
    static class B extends Exception { }

    @CatchNumber(1)
    static class C extends Exception { }

    static int sum = 0;

    public static void main(String[] args) {
        for (ExceptionKind ekind : ExceptionKind.values()) {
            test(ekind);
        }
        if (sum != 4) {
            throw new Error("bad checksum - expected:4, found:" + sum);
        }
    }

    public static void test(ExceptionKind ekind) {
        try {
            switch(ekind) {
                case A: throw new A();
                case B: throw new B();
                case C: throw new C();
            }
        } catch(final A | C ex) {
            CatchNumber catchNumber = ex.getClass().getAnnotation(CatchNumber.class);
            if (catchNumber == null || catchNumber.value() != ekind.expectedValue) {
                throw new Error("was expecting 1 - got " + catchNumber);
            }
            sum += catchNumber.value();
        } catch (final B ex) { 
            CatchNumber catchNumber = ex.getClass().getAnnotation(CatchNumber.class);
            if (catchNumber == null || catchNumber.value() != ekind.expectedValue) {
                throw new Error("was expecting 2 - got " + catchNumber);
            }
            sum += catchNumber.value();
        }
    }
}
