



import java.io.StringWriter;
import java.io.PrintWriter;
import java.io.IOException;

public class LambdaInnerTypeVarReflect {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface I {
        C doit();
    }

    abstract class C {
        abstract Object it();
    }

    class TV {
        C go() {
            return foo("Frump").doit();
        }

        <RRRRR> I foo(RRRRR r) {
            return () -> new C() {
                public RRRRR xxxxx = r;
                @Override
                    Object it() { return xxxxx; };
            };
        }
    }

    void test1() throws IOException {
        char[] buffer = new char[1024];
        String innerName = new TV().go().getClass().getName();
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        int exitCode = com.sun.tools.javap.Main.run(new String[] {innerName}, pw);
        assertTrue(exitCode == 0);

        String javapOut = sw.toString();
        assertTrue(javapOut.contains(innerName));
        assertTrue(!javapOut.contains("RRRRR"));
    }

    public static void main(String[] args) throws IOException {
        LambdaInnerTypeVarReflect t = new LambdaInnerTypeVarReflect();
        t.test1();
        assertTrue(assertionCount == 3);
    }
}
