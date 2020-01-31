

import java.io.IOException;

class ImplicitFinal implements AutoCloseable {
    public static void main(String... args) {
        try(ImplicitFinal r = new ImplicitFinal()) {
            r = null; 
        } catch (IOException ioe) { 
            throw new AssertionError("Shouldn't reach here", ioe);
        }

        try(@SuppressWarnings("unchecked") ImplicitFinal r1 = new ImplicitFinal()) {
            r1 = null; 
        } catch (IOException ioe) { 
            throw new AssertionError("Shouldn't reach here", ioe);
        }

        try(final ImplicitFinal r2 = new ImplicitFinal()) {
            r2 = null; 
        } catch (IOException ioe) { 
            throw new AssertionError("Shouldn't reach here", ioe);
        }

        try(final @SuppressWarnings("unchecked") ImplicitFinal r3 = new ImplicitFinal()) {
            r3 = null; 
        } catch (IOException ioe) { 
            throw new AssertionError("Shouldn't reach here", ioe);
        }
    }
    public void close() throws IOException {
        throw new IOException();
    }
}
