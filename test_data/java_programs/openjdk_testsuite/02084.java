



import java.io.PrintWriter;
import java.io.StringWriter;
import java.nio.file.Paths;
import java.util.*;

public class MethodRefDupInConstantPoolTest {

    private static final String methodToLookFor =
            "java/util/Vector.iterator:()Ljava/util/Iterator;";

    public static void main(String[] args) {
        new MethodRefDupInConstantPoolTest().run();
    }

    void run() {
        check("-v", Paths.get(System.getProperty("test.classes"),
                this.getClass().getSimpleName() + "$TestHelper1.class").toString());
        check("-v", Paths.get(System.getProperty("test.classes"),
                this.getClass().getSimpleName() + "$TestHelper2.class").toString());
        check("-v", Paths.get(System.getProperty("test.classes"),
                this.getClass().getSimpleName() + "$TestHelper3.class").toString());
        check("-v", Paths.get(System.getProperty("test.classes"),
                this.getClass().getSimpleName() + "$TestHelper4.class").toString());
    }

    void check(String... params) {
        StringWriter s;
        String out;
        try (PrintWriter pw = new PrintWriter(s = new StringWriter())) {
            com.sun.tools.javap.Main.run(params, pw);
            out = s.toString();
        }
        String constantPool = getConstantPool(out);
        if (constantPool.indexOf(methodToLookFor) !=
                constantPool.lastIndexOf(methodToLookFor)) {
            throw new AssertionError("There is more than one entry for the method seek "  +
                    methodToLookFor);
        }
    }

    String getConstantPool(String out) {
        int start = out.indexOf("Constant pool:");
        int end = out.indexOf("{");
        return out.substring(start, end);
    }

    class TestHelper1 {
        void m() {
            Vector v = new Vector();
            Iterator iter = v.iterator();
            while (iter.hasNext()) {
                Object o = iter.next();
                Object o2 = o;
            }
            for (Object o: v) {
                Object o2 = o;
            }
        }
    }

    class TestHelper2<X extends Number & Iterable<String>> {
        void test(X x) {
            for (String s : x) { }
        }
    }

    interface Data extends Iterable<String> {}

    class TestHelper3<X extends Number & Iterable<? extends Data>> {
        void test(X x) {
            for (Data s : x) { }
        }
    }

    class TestHelper4 {
         void test(Iterable<? extends Data> t) {
             for(Object a: t.iterator().next());
         }
    }
}
