



public class T5073060 {
    static String foo;
    public static void main(String[] args) {
        C2 c2 = null;
        C3 c3 = null;

        m1(c2, c3).c1m1();
        m1(c2, c3).i1m1();
        m1(c2, c3).i2m1();
    }

    public static <T> T m1(T t1, T t2) {
        return null;
    }

    class C1 { void c1m1() {} }
    interface I1 { void i1m1(); }
    interface I2 { void i2m1(); }

    class C2 extends C1 implements I1, I2 {
        public void i1m1() { }
        public void i2m1() { }
    }

    class C3 extends C1 implements I1, I2 {
        public void i1m1() { }
        public void i2m1() { }
    }
}
