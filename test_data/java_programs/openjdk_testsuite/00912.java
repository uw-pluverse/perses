



public class ExprQualifiedType {

    static class Nested {
        static int i;
        static void m() { i = 1; }
    }

    static void test() {
        new ExprQualifiedType().Nested.i = 1;
        new ExprQualifiedType().Nested.m();
    }
}
