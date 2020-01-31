



package varargs.warn2;

class T {
    static void f(String fmt, Object... args) {}

    public static void main(String[] args) {
        f("foo", null);
    }
}
