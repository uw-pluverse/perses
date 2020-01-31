



public class MethodReference13 {

    static void assertTrue(boolean cond) {
        if (!cond)
            throw new AssertionError();
    }

    interface SAM {
        void m();
    }

    static void m() { }

    public static void main(String[] args) {
        SAM s = MethodReference13::m;
        assertTrue(s.equals(s));
    }
}
