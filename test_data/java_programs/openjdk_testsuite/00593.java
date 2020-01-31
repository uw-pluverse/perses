



public class WhichImplicitThis11 {
    public class Inner extends WhichImplicitThis11 {
        Inner(String s) {
            this();
        }
        Inner() {
        }
    }
    public static void main(String[] args) {
        new WhichImplicitThis11().new Inner("");
    }
}
