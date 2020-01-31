


public class SingleLocalTest {
    interface F {void f();}

    static F f;

    public static void main(String[] args) {
        StringBuffer sb = new StringBuffer();
        class Local1 {
            public Local1() {
                f = () -> new Local1();
                sb.append("1");
            }
        }
        new Local1();
        f.f();
        String s = sb.toString();
        if (!s.equals("11")) {
            throw new AssertionError("Expected '11' got '" + s + "'");
        }
    }
}
