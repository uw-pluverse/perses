

import java.io.IOException;
public class TwrFlow implements AutoCloseable {
    public static void main(String... args) {
        try(TwrFlow twrFlow = new TwrFlow()) {
            System.out.println(twrFlow.toString());
        } catch (IOException ioe) { 
            throw new AssertionError("Shouldn't reach here", ioe);
        }
        
    }

    
    public void close() throws CustomCloseException {
        throw new CustomCloseException();
    }
}

class CustomCloseException extends Exception {}
