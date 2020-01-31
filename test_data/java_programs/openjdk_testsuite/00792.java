



import javax.tools.DiagnosticCollector;

public class T6452876 {
    public static void main(String... args) {
        try {
            new DiagnosticCollector<Object>().report(null);
        } catch (NullPointerException npe) {
            return;
        }
        throw new AssertionError("Expected NPE not thrown");
    }
}
