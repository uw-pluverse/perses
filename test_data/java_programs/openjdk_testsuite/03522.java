



public class TwrNullTests {
    
    public static void main(String... args) {
        testNormalCompletion();
        testNoSuppression();
    }

    
    private static void testNormalCompletion() {
        try(AutoCloseable resource = null) {
            return; 
        } catch (Exception e) {
            throw new AssertionError("Should not be reached", e);
        }
    }

    
    private static void testNoSuppression() {
        try(AutoCloseable resource = null) {
            throw new java.io.IOException();
        } catch(java.io.IOException ioe) {
            Throwable[] suppressed = ioe.getSuppressed();
            if (suppressed.length != 0) {
                throw new AssertionError("Non-empty suppressed exceptions",
                                         ioe);
            }
        } catch (Exception e) {
            throw new AssertionError("Should not be reached", e);
        }
    }
}
