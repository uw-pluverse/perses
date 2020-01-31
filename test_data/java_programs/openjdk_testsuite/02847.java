



import static com.sun.tools.javac.util.Convert.enclosingCandidates;
import com.sun.tools.javac.util.*;

import java.util.Arrays;
import java.util.Locale;

public class EnclosingCandidates {

    Names names = Names.instance(new Context());

    void test(String name, String... expected) {
        List<Name> result = enclosingCandidates(names.fromString(name));
        if (!result.isEmpty() || expected.length != 0) {
            Name[] expectedNames = new Name[expected.length];
            int i = 0;
            for (String s : expected)
                expectedNames[i++] = names.fromString(s);
            if (!Arrays.equals(result.toArray(), expectedNames))
                throw new AssertionError(name + " : " +
                                         Arrays.toString(expectedNames) + " != " + result);
        }
        System.out.format((Locale)null, "OK: %s -> [%s]%n", name, result);
    }

    public static void main(String... args) {
        EnclosingCandidates test = new EnclosingCandidates();
        test.test("");
        test.test("foo");
        test.test("foo$bar", "foo");
        test.test("foo$bar$baz", "foo", "foo$bar");
        test.test("x$foo", "x");
        test.test("$foo$", "$foo");
        test.test("$foo$x", "$foo");
        test.test("$foo");
        test.test("foo$", "foo");
        test.test("foo$bar$", "foo", "foo$bar");
    }

}
