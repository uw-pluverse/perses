



import java.lang.reflect.*;

public class Test {
    strictfp void strict() {}
    strictfp class Inner2 { void strict() {} }

    public static void main(String[] args) throws NoSuchMethodException {
        assertStrict(Test.class.getDeclaredMethod("strict", new Class[0]));
        assertStrict(Test.Inner2.class.getDeclaredMethod("strict", new Class[0]));

        assertStrict(Test2.class.getDeclaredMethod("strict", new Class[0]));
        assertStrict(Test2.class.getDeclaredMethod("strict2", new Class[0]));
        assertStrict(Test2.Inner.class.getDeclaredMethod("strict", new Class[0]));
        assertStrict(Test2.Inner2.class.getDeclaredMethod("strict", new Class[0]));
    }

    private static void assertStrict(Method m) {
        int mod = m.getModifiers();
        if (!Modifier.isStrict(mod))
            barf(m, "strict");
    }

    private static void barf(Method m, String msg) {
        System.err.println("Method "+m+" was not "+msg+": "
                           +Modifier.toString(m.getModifiers()));

    }
}


strictfp class Test2 {
    void strict() {}
    strictfp void strict2() {}
    class Inner { void strict() {} }
    strictfp class Inner2 { void strict() {} }
}


class OtherTest
{
    static double m() {
        strictfp class Inn {
            float i;
        }
        return 2.0;
    }
}
