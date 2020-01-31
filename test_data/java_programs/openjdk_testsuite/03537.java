



import java.io.IOException;
public class TwrMultiCatch implements AutoCloseable {
    private final Class<? extends Exception> exceptionClass;

    private TwrMultiCatch(Class<? extends Exception> exceptionClass) {
        this.exceptionClass = exceptionClass;
    }

    public static void main(String... args) {
        test(new TwrMultiCatch(CustomCloseException1.class),
             CustomCloseException1.class);

        test(new TwrMultiCatch(CustomCloseException2.class),
             CustomCloseException2.class);
    }

    private static void test(TwrMultiCatch twrMultiCatch,
                     Class<? extends Exception> expected) {
        try(TwrMultiCatch tmc = twrMultiCatch) {
            System.out.println(tmc.toString());
        } catch (CustomCloseException1 |
                 CustomCloseException2 exception) {
            if (!exception.getClass().equals(expected) ) {
                throw new RuntimeException("Unexpected catch!");
            }
        }
    }

    public void close() throws CustomCloseException1, CustomCloseException2 {
        Throwable t;
        try {
             t = exceptionClass.newInstance();
        } catch(ReflectiveOperationException rfe) {
            throw new RuntimeException(rfe);
        }

        try {
            throw t;
        } catch (CustomCloseException1 |
                 CustomCloseException2 exception) {
            throw exception;
        } catch (Throwable throwable) {
            throw new RuntimeException(throwable);
        }
    }
}

class CustomCloseException1 extends Exception {}
class CustomCloseException2 extends Exception {}
