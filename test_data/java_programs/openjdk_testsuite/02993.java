



public class LambdaOuterLocalTest {
    interface F {void f();}

    static F f;
    static StringBuffer sb = new StringBuffer();

    static void assertEquals(Object val, Object expected) {
        if (!val.equals(expected)) {
            throw new AssertionError("expected '" + expected + "' got '" + val + "'");
        }
    }

    public static void main(String[] args) {
        class Local1 {
            public Local1() {
                class Local2 {
                    public Local2() {
                        f = () -> new Local1();
                        sb.append("2");
                    }
                }
                sb.append("1");
                new Local2();
            }
        }
        new Local1();
        f.f();
        assertEquals(sb.toString(), "1212");
    }
}
