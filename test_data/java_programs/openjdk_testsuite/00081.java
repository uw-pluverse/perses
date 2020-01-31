



public class Pos {
    public static <T> void foo() {
        System.out.println("foo");
    }
    public static void bar() {
        System.out.println("foo");
    }
    public static void main(String[] args) {
        Pos.<Object>foo();
        Pos.<Object>bar();
    }
}
