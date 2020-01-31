



public class Primitives {
    @java.lang.annotation.Retention(java.lang.annotation.RetentionPolicy.RUNTIME)
    @interface A {
        Class value() default void.class;
    }

    @java.lang.annotation.Retention(java.lang.annotation.RetentionPolicy.RUNTIME)
    @interface B {
        Class[] value() default { void.class };
    }

    @A()
    @B()
    static class T1 {}

    @A(int.class)
    @B({void.class, byte.class, char.class, short.class, int.class, long.class,
        boolean.class, float.class, double.class, A[].class, int[].class})
    static class T2 {}

    static void check(Object actual, Object expected) {
        if (actual != expected)
            throw new Error("expected: " + expected + "; actual = " + actual);
    }

    public static void main(String[] args) {
        check(T1.class.getAnnotation(A.class).value(), void.class);
        check(T1.class.getAnnotation(B.class).value().length, 1);
        check(T1.class.getAnnotation(B.class).value()[0], void.class);

        check(T2.class.getAnnotation(A.class).value(), int.class);
        check(T2.class.getAnnotation(B.class).value().length, 11);
        check(T2.class.getAnnotation(B.class).value()[0], void.class);
        check(T2.class.getAnnotation(B.class).value()[1], byte.class);
        check(T2.class.getAnnotation(B.class).value()[2], char.class);
        check(T2.class.getAnnotation(B.class).value()[3], short.class);
        check(T2.class.getAnnotation(B.class).value()[4], int.class);
        check(T2.class.getAnnotation(B.class).value()[5], long.class);
        check(T2.class.getAnnotation(B.class).value()[6], boolean.class);
        check(T2.class.getAnnotation(B.class).value()[7], float.class);
        check(T2.class.getAnnotation(B.class).value()[8], double.class);
        check(T2.class.getAnnotation(B.class).value()[9], A[].class);
        check(T2.class.getAnnotation(B.class).value()[10], int[].class);
    }
}
