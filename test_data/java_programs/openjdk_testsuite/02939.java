



public class LambdaLocalTest {
    interface F {void f();}

    static F f;
    static StringBuffer sb = new StringBuffer();

    static void assertEquals(Object val, Object expected) {
        if (!val.equals(expected)) {
            throw new AssertionError("expected '" + expected + "' got '" + val + "'");
        }
    }

    public static void main(String[] args) {
        class Local {
            public Local() {
                f = () -> new Local();
                sb.append("+");
            }
        }
        new Local();
        f.f();
        assertEquals(sb.toString(), "++");
    }
}
