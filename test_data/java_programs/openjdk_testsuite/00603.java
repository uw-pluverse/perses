



public class T6541876a {
    class X {
        class Y {}
    }

    class A extends X {
        class B extends X.Y {}
    }

    public static void main(String[] args) {
        new T6541876a().new A().new B();
    }
}
