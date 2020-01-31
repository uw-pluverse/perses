


import java.util.*;

public class Intersection03 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond) throw new AssertionError();
    }

    public static void main(String[] args) {
        try {
            Runnable r = (List<?> & Runnable)new ArrayList<String>();
            assertTrue(false);
        } catch (ClassCastException cce) {
            assertTrue(true);
        }
        assertTrue(assertionCount == 1);
    }
}
