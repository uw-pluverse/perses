
abstract class A {

    private static String s = null;

    static void test() {
        new Object() {
            void m() {
                Object o = s;
            }
        };
    }
}

public abstract class B<T> extends A {

    private static Integer i = null;

    static void test() {
        new Object() {
            void m() {
                Object o = i;
            }
        };
    }
}
