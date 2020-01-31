



public class Pos10 {
    public static void main(String... args) {
        test(0);
        test(1);

        if (record != 0b11)
            throw new RuntimeException("Unexpected exception execution: " +
                                       record);
        if (closeRecord != 0b11)
            throw new RuntimeException("Unexpected close execution: " +
                                       closeRecord);
    }

    private static int record = 0;
    private static int closeRecord = 0;

    private static void test(int i) {
        try {
            thrower(i);
        } catch (SonException | DaughterException e) {
            Class<? extends ParentException> clazz = e.getClass();
            HasFoo m = e;
            e.foo();

            try (AutoCloseable ac = e) {
                e.toString();
            } catch(Exception except) {
                throw new RuntimeException(except);
            }
        }
    }

    private static interface HasFoo {
        void foo();
    }

    private static void thrower(int i) throws SonException, DaughterException {
        if (i == 0)
            throw new SonException();
        else
            throw new DaughterException();
    }

    private static class ParentException extends RuntimeException {}

    private static class SonException
        extends ParentException
        implements HasFoo, AutoCloseable {

        public void foo() {
            record |= 0b01;
        }

        @Override
        public void close() {
            closeRecord |= 0b01;
        }
    }

    private static class DaughterException
        extends ParentException
        implements HasFoo, AutoCloseable {

        public void foo() {
            record |= 0b10;
        }

        @Override
        public  void close() {
            closeRecord |= 0b10;
        }
    }
}
