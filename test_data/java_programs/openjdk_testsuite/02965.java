



public class MethodRef6 {

    static interface A { String make(Integer i); }

    static interface B { String make(Number i); }

    private static void assertTrue(boolean cond) {
        if (!cond)
            throw new AssertionError();
    }

    static String m(Object o) {
        return "Object " + o;
    }

    static String m(Number n) {
        return "Number " + n;
    }

    static String m(Integer i) {
        return "Integer " + i;
    }

    static String m(int i) {
        return "int " + i;
    }

    public static void main(String[] args) {
        A a = MethodRef6::m;
        assertTrue(a.make(1).equals("Integer 1"));
        B b = MethodRef6::m;
        assertTrue(b.make(1).equals("Number 1"));
    }
}
