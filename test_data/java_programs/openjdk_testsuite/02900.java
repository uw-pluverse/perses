



import java.io.Serializable;

public class LambdaInnerTypeVarSerialize {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    interface I extends Serializable {
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
                RRRRR xxxxx = r;
                @Override
                    Object it() { return xxxxx; };
            };
        }
    }

    void test1() {
        assertTrue(new TV().go().it().equals("Frump"));
    }

    public static void main(String[] args) {
        LambdaInnerTypeVarSerialize t = new LambdaInnerTypeVarSerialize();
        t.test1();
        assertTrue(assertionCount == 1);
    }
}
