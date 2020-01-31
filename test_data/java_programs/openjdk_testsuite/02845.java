



package util.list;

import static com.sun.tools.javac.util.List.from;
import java.util.List;

public class AbstractList {
    public static void test(String... args) {
        List<String> ss = from(args);
        if (args != null) {
            int index = 0;
            for (String s : args) {
                if (s != ss.get(index))
                    throw new AssertionError("s != ss.get(" + index + ")");
                index++;
            }
            boolean ok = false;
            try {
                ss.get(-1);
            } catch(IndexOutOfBoundsException ex) {
                ok = true;
            }
            if (!ok)
                throw new AssertionError();
            ok = false;
            try {
                ss.get(args.length);
            } catch(IndexOutOfBoundsException ex) {
                ok = true;
            }
            if (!ok)
                throw new AssertionError();
        }
    }
    public static void main(String... args) {
        test();
        test("foo");
        test("foo", "bar");
        test("foo", "bar", "bax", "qux", "hest", "fisk", "ko", "fugl");
        System.out.println("List.get(int) test OK");
    }
}
