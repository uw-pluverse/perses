



public class TwrSuppression implements AutoCloseable {
    public static void main(String... args) throws Throwable {
        try {
            try (TwrSuppression r1 = new TwrSuppression(false);
                 TwrSuppression r2 = new TwrSuppression(true)) {
                throw new RuntimeException();
            }
        } catch(RuntimeException e) {
            Throwable[] suppressedExceptions = e.getSuppressed();
            int length = suppressedExceptions.length;
            if (length != 2)
                throw new RuntimeException("Unexpected length " + length);

            if (suppressedExceptions[0].getClass() != Error.class ||
                suppressedExceptions[1].getClass() != Exception.class) {
                System.err.println("Unexpected suppressed types!");
                e.printStackTrace();
                throw new RuntimeException(e);
            }
        }
    }

    private boolean throwError;

    private TwrSuppression(boolean throwError) {
        this.throwError = throwError;
    }

    @Override
    public void close() throws Exception {
        if (throwError) {
            throw new Error();
        } else {
            throw new Exception();
        }
    }
}
