



import java.io.Serializable;
import java.util.List;
import java.util.ArrayList;

public class LambdaInnerTypeVarArgs {

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
            List<String> ls = new ArrayList<>();
            ls.add("Oh");
            ls.add("my");
            return foo(ls).doit();
        }

        <RRRRR> I foo(List<RRRRR> r) {
            return () -> new C() {
                List<RRRRR> xxxxx = r;
                @Override
                    Object it() { return xxxxx; };
            };
        }
    }

    void test1() {
        assertTrue(((List<String>)(new TV().go().it())).get(0).equals("Oh"));
    }

    public static void main(String[] args) {
        LambdaInnerTypeVarArgs t = new LambdaInnerTypeVarArgs();
        t.test1();
        assertTrue(assertionCount == 1);
    }
}
