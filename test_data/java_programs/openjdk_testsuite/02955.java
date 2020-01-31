



public class MethodRefQualifier1 {

    interface SAM {
       void m();
    }

    static int count = 0;

    static void assertTrue(boolean cond, String msg) {
        if (!cond)
            throw new AssertionError(msg);
    }

    MethodRefQualifier1 check() {
        count++;
        return this;
    }

    void ido(Object... args) { }

    public static void main(String[] args) {
       new MethodRefQualifier1().test();
    }

    void test() {
       count = 0;
       SAM s = check()::ido;
       assertTrue(count == 1, "creation: unexpected: " + count);
       count = 0;
       s.m();
       assertTrue(count == 0, "evaluation: unexpected: " + count);
    }
}
