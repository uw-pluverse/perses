



import java.io.IOException;

public class ExplicitFinal implements AutoCloseable {
    public static void main(String... args) {
        try(final ExplicitFinal r2 = new ExplicitFinal()) {
            r2.toString();
        } catch (IOException ioe) {
            throw new AssertionError("Shouldn't reach here", ioe);
        }

        try(final @SuppressWarnings("unchecked") ExplicitFinal r3 = new ExplicitFinal()) {
            r3.toString();
        } catch (IOException ioe) {
            throw new AssertionError("Shouldn't reach here", ioe);
        }

        try(@SuppressWarnings("unchecked") ExplicitFinal r4 = new ExplicitFinal()) {
            r4.toString();
        } catch (IOException ioe) {
            throw new AssertionError("Shouldn't reach here", ioe);
        }
    }
    public void close() throws IOException {
        System.out.println("Calling close on " + this);
    }
}
