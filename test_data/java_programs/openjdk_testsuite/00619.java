



public class Closure6 {
    static class L { L(Object o){} }
    public static void f(final char x) {
        class Sub extends L {
            Sub(final char y) {
                super(new Object() {{
                    System.out.println("" + x + y);
                    }});
            }
        }
        new Sub('K');
    }
    public static void main(String[] args) {
        f('O');
    }
}
