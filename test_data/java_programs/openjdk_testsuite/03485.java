



public class CompileErrorForValidBooleanExpTest {
    static int a, b, c, d;

    static void m() {
        boolean cond1 = (a < b & c > d);
        boolean cond2 = (f1() < f2() & c > d);
        boolean cond3 = (f1() < b & f3() > d);
        boolean cond4 = (f1() < b & f3() > 1);
    }

    static int f1() {
        return 0;
    }

    static int f2() {
        return 0;
    }

    static int f3() {
        return 0;
    }

    static int f4() {
        return 0;
    }
}
