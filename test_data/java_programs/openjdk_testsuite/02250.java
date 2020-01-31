



package qualifiedNewScope;

class A {
    class B {
    }
    public static void main(String[] args) {
        new A(){}.new B(){};
    }
}
