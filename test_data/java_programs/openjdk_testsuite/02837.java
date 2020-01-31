



public class T4903103 {
    private class InnerSuperclass extends T4903103 {}

    private class InnerSubclass extends InnerSuperclass {}

    public static void main(String[] args) {
        new T4903103().new InnerSubclass();
    }
}
