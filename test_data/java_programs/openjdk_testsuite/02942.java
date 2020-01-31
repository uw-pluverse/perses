



import java.util.*;

public class MethodReference11 {
    public static void main(String[] args) {
        String[] strings = new String[] { "D", "C", "B", "A" };
        Arrays.sort( strings, String.CASE_INSENSITIVE_ORDER::compare );
        String last = "1";
        for (String s : strings) {
            if (String.CASE_INSENSITIVE_ORDER.compare(last, s) > 0) {
                throw new AssertionError();
            }
        }
    }
}
