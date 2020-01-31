



import java.util.Locale;
import java.util.Objects;
import com.sun.tools.javac.util.StringUtils;

public class StringUtilsTest {
    public static void main(String... args) throws Exception {
        new StringUtilsTest().run();
    }

    void run() throws Exception {
        Locale.setDefault(new Locale("tr", "TR"));

        
        assertEquals("\u0131", "I".toLowerCase());
        assertEquals("\u0130", "i".toUpperCase());

        
        assertEquals("i", StringUtils.toLowerCase("I"));
        assertEquals("I", StringUtils.toUpperCase("i"));

        
        assertEquals(2, StringUtils.indexOfIgnoreCase("  lookFor", "lookfor"));
        assertEquals(11, StringUtils.indexOfIgnoreCase("  lookFor  LOOKfor", "lookfor", 11));
        assertEquals(2, StringUtils.indexOfIgnoreCase("\u0130\u0130lookFor", "lookfor"));
    }

    void assertEquals(String expected, String actual) {
        if (!Objects.equals(expected, actual)) {
            throw new IllegalStateException("expected=" + expected + "; actual=" + actual);
        }
    }

    void assertEquals(int expected, int actual) {
        if (expected != actual) {
            throw new IllegalStateException("expected=" + expected + "; actual=" + actual);
        }
    }
}
