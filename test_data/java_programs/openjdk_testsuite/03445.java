



public class T6266772 {
    static class Nested {
        Nested (Object o) {}
    }

    class Inner extends Nested {
        Inner() {
            super(new Object() { { s(); } });
        }
    }

    void s() {
        calledS = true;
        if (getClass() != T6266772.class)
            throw new AssertionError(getClass());
    }

    static boolean calledS = false;

    public static void main(String[] args) {
        new T6266772().new Inner();
        if (!calledS)
            throw new AssertionError("Didn't call s");
    }
}
