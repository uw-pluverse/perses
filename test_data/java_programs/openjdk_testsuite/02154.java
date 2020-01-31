



public class Varargs1 {
    static int f(String s, int a, short b) {
        return 1;
    }
    static int f(String s, int a, int b) {
        return 2;
    }
    static int f(String s, Integer ... args) {
        return 3;
    }
    static int f(String s, Number ... args) {
        return 4;
    }
    static int f(String s, Object ... args) {
        return 5;
    }
    static int f(int ... args) {
        return 6;
    }
    static void check(int expected, int actual) {
        if (actual != expected) throw new AssertionError(actual);
    }
    public static void main(String[] args) {
        check(1, f("x", 12, (short)13));
        check(2, f("x", 12, 13));
        check(3, f("x", 12, 13, 14));
        check(4, f("x", 12, 13.5));
        check(5, f("x", 12, true));
        check(6, f(12, 13));
    }
}
