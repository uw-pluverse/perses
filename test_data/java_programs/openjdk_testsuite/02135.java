



public class T6746184 {
    public static void main(String[] args) {
        A.m(new Object());
    }
}

class A {
    public static void m(final Object... varargs) {}
    private static void m(final Object singleArg) {}
}
