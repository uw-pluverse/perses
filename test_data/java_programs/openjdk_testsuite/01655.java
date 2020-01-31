



import com.sun.tools.javac.util.List;

public class T6238612 {
    public static void main(String... args) {
        new T6238612().test();
    }

    boolean error = false;

    
    void test() {
        test(List.<String>nil());
        test(List.of("a"));
        test(List.of("a", "b", "c"));
        test(List.of("a", "b", "c", "d", "e", "f"));
        if (error)
            throw new Error("test failed");
    }

    
    void test(List<String> list) {
        int n = list.size();
        if (n > 0)
            test(list, new String[0]);

        if (n > 1)
            test(list, new String[n - 1]);

        test(list, new String[n]);
        test(list, new String[n + 1]);
        test(list, new String[n + 5]);
    }

    
    void test(List<String> list, String[] array) {
        String[] result = list.toArray(array);

        if (result.length < list.size()) {
            error("returned array is too small; expected: " + list.size() + ", found: " + result.length);
            return;
        }

        if (list.size() <= array.length && result != array)
            error("new array wrongly created");

        int i = 0;
        for (String s: list)
            check(result, i++, s);

        if (i < result.length)
            check(result, i, null);
    }

    
    void check(String[] array, int i, String expected) {
        if (!equal(array[i], expected))
                error("element " + i + " incorrect; expected: " + str(expected) + ", found: " + str(array[i]));
    }

    
    boolean equal(String s1, String s2) {
        return (s1 == null ? s2 == null : s1.equals(s2));
    }

    String str(String s) {
        return (s == null ? "null" : '"' + s + '"');
    }

    void error(String message) {
        System.err.println(message);
        error = true;
    }
}
